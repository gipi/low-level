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

An important feature of a shell like `bash` is the stream redirection:
by default every process has associated at least three file descriptors

 - `stdin` (associated with the literal number 0)
 - `stdout` (associated with 1)
 - `stderr` (associated with 2)

but it's possible to open/close old/new file descriptors directly from the command line
using the following expressions

 - `[n]>output`: redirect stream `n` to file `output` that it's created if needed; the file is truncated
 - `[n]>>output`: as above but the content is appended
 - `[n]>&word`: duplicated output file descriptor

Note that the order of redirections is significant.  For example, the command

```
ls > dirlist 2>&1
```

directs both standard output and standard error to the file dirlist, while the command

```
ls 2>&1 > dirlist
```

directs only the standard output to file dirlist, because the standard error
was duplicated from the standard output before the standard output was
redirected to dirlist. To understand better think of an analogy where `>` is like
the equality operator `=` and `&` is instead used as a variable definition like `$`

https://unix.stackexchange.com/a/37662/32025

```
1 = /dev/tty
2 = /dev/tty
```

`1> file.txt 2>&1`

```
1 = file.txt
2 = $1           # and currently $1 = file.txt
```

```
1 = file.txt
2 = file.txt
```

`2>&1 > file.txt`

```
2 = $1           # and currently $1 = /dev/tty
1 = file.txt
```

```
1 = file.txt
2 = /dev/tty
```

So you need to think about `&` as a copy of a file descriptor and not as a reference.

### Links

 - [How to use arguments from previous command?](https://stackoverflow.com/questions/4009412/how-to-use-arguments-from-previous-command/32332694)
 - [Programming with ANSI escape codes](http://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html)
 - [The TTY demystified](http://www.linusakesson.net/programming/tty/)
 - [Abusing the FILE structure](https://outflux.net/blog/archives/2011/12/22/abusing-the-file-structure/)
 - http://blog.hostilefork.com/where-printf-rubber-meets-road/
 - https://sourceware.org/glibc/wiki/LibioVtables
 - [SO question and answer](https://unix.stackexchange.com/questions/117981/what-are-the-responsibilities-of-each-pseudo-terminal-pty-component-software) What are the responsibilities of each Pseudo-Terminal (PTY) component (software, master side, slave side)?
 - [!!Con West 2019 - Tabitha Sable: My, my, TTY!](https://www.youtube.com/watch?v=bdBQPwMFkFY)

## Links

 - [dylanaraps/pure-bash-bible](https://github.com/dylanaraps/pure-bash-bible) A collection of pure bash alternatives to external processes
 - [Google Bash style guide](https://google.github.io/styleguide/shell.xml)
 - http://resources.mpi-inf.mpg.de/departments/rg1/teaching/unixffb-ss98/quoting-guide.html
 - http://twistedoakstudios.com/blog/Post4872_dont-treat-paths-like-strings
 - [Why Bash is like that: suid](http://www.vidarholen.net/contents/blog/?p=30)
 - [buffering in standard streams](http://www.pixelbeat.org/programming/stdio_buffering/)
 - [Command Injection Without Spaces](http://www.betterhacker.com/2016/10/command-injection-without-spaces.html)
 - [HINTS FOR WRITING UNIX TOOLS](https://monkey.org/~marius/unix-tools-hints.html)
 - [PIPES, FORKS, & DUPS: UNDERSTANDING COMMAND EXECUTION AND INPUT/OUTPUT DATA FLOW](http://www.rozmichelle.com/pipes-forks-dups/)
 - [How fast are Linux pipes anyway?](https://mazzo.li/posts/fast-pipes.html)
 - [What exactly was the point of ``[ “x$var” = “xval” ]``?](https://www.vidarholen.net/contents/blog/?p=1035)
 - [Bash Pitfalls](https://mywiki.wooledge.org/BashPitfalls)
