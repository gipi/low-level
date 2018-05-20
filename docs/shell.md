# Shell

In this page will refer as shell to the device that allows to communicate with the system, including terminal,
shells and control characters (think about ``Ctrl-v`` in the shell).

Normally in the interaction with a client you have to take into account

 - the terminal
 - the shell
 - the application

so, if we want to rename a file named ``-|^C`` to ``foo`` you  have to issue the following
keys sequence

    m v Space . / - \ | Ctrl-V Ctrl-C Space f o o Return

into the terminal.

Take into account also the path separator and the syntax behind it.

## Console&TTY

An useful diagram from [here](https://clementc.github.io/blog/2018/01/25/moving_cli/)

![](moving_cli.png)

 - [Programming with ANSI escape codes](http://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html)
 - [The TTY demystified](http://www.linusakesson.net/programming/tty/)
 - [Abusing the FILE structure](https://outflux.net/blog/archives/2011/12/22/abusing-the-file-structure/)
 - http://blog.hostilefork.com/where-printf-rubber-meets-road/
 - https://sourceware.org/glibc/wiki/LibioVtables
 - [SO question and answer](https://unix.stackexchange.com/questions/117981/what-are-the-responsibilities-of-each-pseudo-terminal-pty-component-software) What are the responsibilities of each Pseudo-Terminal (PTY) component (software, master side, slave side)?

## Links

 - [Google Bash style guide](https://google.github.io/styleguide/shell.xml)
 - http://resources.mpi-inf.mpg.de/departments/rg1/teaching/unixffb-ss98/quoting-guide.html
 - http://twistedoakstudios.com/blog/Post4872_dont-treat-paths-like-strings
 - [Why Bash is like that: suid](http://www.vidarholen.net/contents/blog/?p=30)
 - [buffering in standard streams](http://www.pixelbeat.org/programming/stdio_buffering/)
 - [Command Injection Without Spaces](http://www.betterhacker.com/2016/10/command-injection-without-spaces.html)
 - [HINTS FOR WRITING UNIX TOOLS](https://monkey.org/~marius/unix-tools-hints.html)
