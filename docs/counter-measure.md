# Counter measure

 - [PAX](https://pax.grsecurity.net/)
 - [Stack Smashing as of Today](https://www.blackhat.com/presentations/bh-europe-09/Fritsch/Blackhat-Europe-2009-Fritsch-Bypassing-aslr-slides.pdf)

You can find a script to check in this repo: ``https://github.com/slimm609/checksec.sh``.

```
/checksec -f ~/ch20
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH	FORTIFY	Fortified Fortifiable  FILE
Partial RELRO   Canary found      NX disabled   No PIE          No RPATH   No RUNPATH   Yes	0		6	/challenge/app-systeme/ch20/ch20
app-systeme-ch20@challenge02:/tmp/_check$ ./checksec -ff ~/ch20
* FORTIFY_SOURCE support available (libc)    : Yes
* Binary compiled with FORTIFY_SOURCE support: Yes

 ------ EXECUTABLE-FILE ------- . -------- LIBC --------
 Fortifiable library functions | Checked function names
 -------------------------------------------------------
 printf                         | __printf_chk
 printf                         | __printf_chk
 fgets                          | __fgets_chk
 fgets                          | __fgets_chk
 memset                         | __memset_chk
 memset                         | __memset_chk

SUMMARY:

* Number of checked functions in libc                : 76
* Total number of library functions in the executable: 98
* Number of Fortifiable functions in the executable : 6
* Number of checked functions in the executable      : 0
* Number of unchecked functions in the executable    : 6

```

## NX

Avoid trivial execution of shellcodes from the stack marking the pages as not executable

 - [EXSTACK_ENABLE_X](http://lxr.free-electrons.com/ident?v=3.18;i=EXSTACK_ENABLE_X)

## Canary

The implementation of the function ``__stack_chk_fail()`` is the following

```
/* Note how buffer overruns are undefined behavior and the compilers tend to
   optimize these checks away if you wrote them yourself, this only works
   robustly because the compiler did it itself. */
extern uintptr_t __stack_chk_guard;
noreturn void __stack_chk_fail(void);
void foo(const char* str)
{
    uintptr_t canary = __stack_chk_guard;
    char buffer[16];
    strcpy(buffer, str);
    if ( (canary = canary ^ __stack_chk_guard) != 0 )
        __stack_chk_fail();
}
```

with the value of ``__stack_chk_guard`` put into a static address that you can find
reading a core dump

 - [Stack Smashing Protector description on OSDev wiki](http://wiki.osdev.org/Stack_Smashing_Protector)
 - [__stack_chk_fail specification](http://refspecs.linux-foundation.org/LSB_4.1.0/LSB-Core-generic/LSB-Core-generic/libc---stack-chk-fail-1.html)
 - [CodeGate 2012 Quals Vuln500 Write-up](http://mslc.ctf.su/wp/codegate-2012-quals-vuln500-write-up/)
 - [Debugging __thead variables from coredumps](https://www.technovelty.org/linux/debugging-__thead-variables-from-coredumps.html)


## ASLR

When a process is mapped in memory, the addresses of 
[heap](http://lxr.free-electrons.com/ident?v=3.18;i=arch_randomize_brk)
are shifted of a random amount with a mask

 - **stack: **[randomize_stack_top](http://lxr.free-electrons.com/ident?v=3.18;i=randomize_stack_top),[STACK_RND_MASK](http://lxr.free-electrons.com/ident?v=3.18;i=STACK_RND_MASK) ``0x7ff``/``0x3fffff`` for 32/64 bits

Linux ASLR can be configured through /proc/sys/kernel/randomize_va_space. The following values are supported:

 - No randomization. Everything is static.
 - Conservative randomization. Shared libraries, stack, mmap(), VDSO and heap are randomized.
 - Full randomization. In addition to elements listed in the previous point, memory managed through brk() is also randomized.

### Links

 - [ASLR implementation in Linux Kernel 3.7](http://shell-storm.org/blog/ASLR-implementation-in-Linux-Kernel-3.7/)
 - [To disable randomization](https://gcc.gnu.org/wiki/Randomization)

## RELRO


