Idea: write a ptrace-based command that take a list of address, set breakpoint
and dump a list of local variables, based with respect to the ``esp``/``ebp``
offset; also intercept ``SEGFAULT`` and stop.

 - http://blog.0x972.info/?d=2014/11/13/10/40/50-how-does-a-debugger-work
 - https://github.com/laertis/ptrace
