# eBPF

[eBPF documentation](https://docs.ebpf.io/)

## bpftrace

[homepage](https://bpftrace.org/)

## BCC

[github project](https://github.com/iovisor/bcc/)

```python
#!/usr/bin/python3

import sys
import time
import ctypes

from bcc import BPF
# sudo bpftrace -e 'tracepoint:sched:sched_switch /args->prev_comm=="child"/{  printf("%s\n", args->next_comm);@[ustack(1)]=count();}'
# sudo bpftrace -l tracepoint:sched:sched_switch -vv
# tracepoint:sched:sched_switch
#    char prev_comm[16]
#    pid_t prev_pid
#    int prev_prio
#    long prev_state
#    char next_comm[16]
#    pid_t next_pid
#    int next_prio
src = r"""
#define TARGET_PROCESS_NAME "child"


BPF_RINGBUF_OUTPUT(buffer, 1 << 4);
BPF_STACK_TRACE(stacktraces, 1024);

// https://github.com/iovisor/bcc/issues/5137 bpf_strncmp doesn't work

// Returns 0 if lhs and rhs compares equal up to n bytes. Otherwise a non-zero value is returned.
// NOTE #1: Cannot use C standard library's strncmp() because that cannot be compiled by BCC.
// NOTE #2: Different from the C standard library's strncmp(), this does not distinguish order.
// NOTE #3: n must be a literal so that the BCC runtime can unroll the inner loop.
// NOTE #4: Loop unrolling increases instruction code, be aware when BPF verifier complains about
// breaching instruction count limit.
static __inline int bpf_xstrncmp(const char* lhs, size_t n, const char* rhs) {
  for (size_t i = 0; i < n; ++i) {
    if (lhs[i] != rhs[i]) {
      return 1;
    }
    // check we have a NULL we can bail out
    if (lhs[i] == 0) {
        break;
    }
  }
  return 0;
}

struct event {
    u64 timestamp;
    u64 stackid;
};
/*
 * This function serves two roles:
 *
 *  1. if we are entering our process of choice (next_comm) then save the timestamp
 *  2. if we are leaving our process of choiche (prev_comm) we calculate the diff
 *     with the previous timestamp and we save the stack and we send out the data
 */
TRACEPOINT_PROBE(sched, sched_switch) {
    char comm[16];

    bpf_probe_read_kernel_str(comm, sizeof(comm), args->prev_comm);
    bool is_leaving = bpf_xstrncmp(comm, 16, TARGET_PROCESS_NAME) == 0;

    bpf_probe_read_kernel_str(comm, sizeof(comm), args->next_comm);
    bool is_entering = bpf_xstrncmp(TARGET_PROCESS_NAME, 16, comm) == 0;

    // we are interested in other that our process
    if (!(is_entering || is_leaving)) {
        return 0;
    }
    // bpf_trace_printk("evil %s!!!", comm);


    struct event event = {};
    event.timestamp = bpf_ktime_get_ns();

    if (is_leaving) {
        event.stackid = stacktraces.get_stackid(args, BPF_F_USER_STACK);
    }
    
    buffer.ringbuf_output(&event, sizeof(event), 0);

    return 0;
}
"""

b = BPF(text=src)

pid = int(sys.argv[1])

def get_stacktrace(bpf, stackid: int):
    stack_traces = bpf["stacktraces"]
    
    output = []

    for addr in stack_traces.walk(stackid):
        sym = bpf.sym(
               addr,
               pid,
                show_module=True,
                show_offset=True)
        output.append(sym.decode('utf-8'))

    return output



def callback(ctx, data, size):
    event = b['buffer'].event(data)
    stacks = get_stacktrace(b, event.stackid) if event.stackid != 0 else [""]
    print("%10d %s" % (event.timestamp, ";".join(stacks)))

b['buffer'].open_ring_buffer(callback)

print("Printing openat() calls, ctrl-c to exit.")

print("%-16s %10s" % ("TIMESTAMP", "stacktrace",))

try:
    while 1:
        b.ring_buffer_poll()
        # or b.ring_buffer_consume()
        time.sleep(0.5)
except KeyboardInterrupt:
    sys.exit()
```
