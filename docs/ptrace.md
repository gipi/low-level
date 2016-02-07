# Ptrace&Debugger

ptrace is the system call used to trace a program and it's used
primarly by debuggers like gdb to do their stuffs.

##

Idea: write a ptrace-based command that take a list of address, set breakpoint
and dump a list of local variables, based with respect to the ``esp``/``ebp``
offset; also intercept ``SEGFAULT`` and stop. First POC's code: [ptrace](code/ptrace_on_segfault.c).

```
$ ./ptrace_on_segfault  ./i_crash 265
RIP: 41414141 Instruction executed: ffffffff 11
 [I] child 17148 received signal 11
```


 - http://blog.0x972.info/?d=2014/11/13/10/40/50-how-does-a-debugger-work
 - https://github.com/laertis/ptrace
