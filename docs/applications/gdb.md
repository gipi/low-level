# GDB

## Information about an address

```
(gdb) $ info symbol <address>
```
If you have also ``gef``

```
gef> xinfo <address>
```

is more exhaustive.

## Breakpoints commands

You can indicate commands to be executed after a breakpoint,
remember to use ``continue`` to let the program run

```
break 30
commands
silent
printf "(%d, %d) %d %d %d %d\n", i, j, first, second, third, fourth
continue
end
r < hockey_rivalry_dynamic_programming6.test
quit
```
