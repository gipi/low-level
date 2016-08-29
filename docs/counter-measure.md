# Counter measure

 - [PAX](https://pax.grsecurity.net/)

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

## Canary

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

 - [Stack Smashing Protector description on OSDev wiki](http://wiki.osdev.org/Stack_Smashing_Protector)
 - [__stack_chk_fail specification](http://refspecs.linux-foundation.org/LSB_4.1.0/LSB-Core-generic/LSB-Core-generic/libc---stack-chk-fail-1.html)

## ASLR

If you want to check in a Linux system you can read the file ``/proc/sys/kernel/randomize_va_space``.

 - [To disable randomization](https://gcc.gnu.org/wiki/Randomization)

## RELRO


