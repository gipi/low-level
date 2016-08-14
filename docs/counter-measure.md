# Counter measure

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

## ASLR

If you want to check in a Linux system you can read the file ``/proc/sys/kernel/randomize_va_space``.

 - [To disable randomization](https://gcc.gnu.org/wiki/Randomization)

## RELRO
