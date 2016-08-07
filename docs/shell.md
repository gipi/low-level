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

## Console

 - [Programming with ANSI escape codes](http://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html)

## Links

 - http://resources.mpi-inf.mpg.de/departments/rg1/teaching/unixffb-ss98/quoting-guide.html
 - http://twistedoakstudios.com/blog/Post4872_dont-treat-paths-like-strings
 - [Why Bash is like that: suid](http://www.vidarholen.net/contents/blog/?p=30)
 - [buffering in standard streams](http://www.pixelbeat.org/programming/stdio_buffering/)
 - [The Design and Implementation of Userland Exec](https://grugq.github.io/docs/ul_exec.txt)
