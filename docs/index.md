
 - [Build-your-own-X](https://github.com/danistefanovic/build-your-own-x)
 - [Color](http://jamie-wong.com/post/color/)
 - [Practical Guide to Bare Metal C++](https://arobenko.gitbooks.io/bare_metal_cpp)
 - [Anatomy of a Program in Memory](http://duartes.org/gustavo/blog/post/anatomy-of-a-program-in-memory/)
 - [The Kernel Boot Process](http://duartes.org/gustavo/blog/post/kernel-boot-process/)
 - [CPU Rings, Privilege, and Protection](http://duartes.org/gustavo/blog/post/cpu-rings-privilege-and-protection/)
 - [Protected mode programming tutorial](http://prodebug.sourceforge.net/pmtut.html)
 - [Linux Inside](https://www.gitbook.com/book/0xax/linux-insides/details)
 - [Linux System Calls, Error Numbers, and In-Band Signaling](http://nullprogram.com/blog/2016/09/23/)
 - [Linux containers in 500 lines of code](https://blog.lizzie.io/linux-containers-in-500-loc.html)
 - [Linux Performance](http://www.brendangregg.com/linuxperf.html)
 - [Video](https://www.youtube.com/watch?v=GsMs3n8CB6g): Give me 15 minutes and I'll change your view of Linux tracing
 - [gist](https://gist.github.com/marcan/a2eafd605d3d6ac76eb10a7c64f736c3) Linux kernel initialization, translated to bash
 - [The Collapse of the UNIX Philosophy](https://kukuruku.co/post/the-collapse-of-the-unix-philosophy/)
 - [spawn() of Satan](https://tavianator.com/spawn-of-satan/)
 - [Repo](https://github.com/cirosantilli/x86-bare-metal-examples) with bare metal example/documentation

## Compiling&Linking

 - [A ToC of the 20 part linker essay](https://lwn.net/Articles/276782/)
 - [Designing Linker Scripts with GNU Linker](https://ravikiranb.com/articles/linker-script/)
 - [From Zero to main(): Demystifying Firmware Linker Scripts](https://interrupt.memfault.com/blog/how-to-write-linker-scripts-for-firmware)
 - [LD command language](https://www.math.utah.edu/docs/info/ld_3.html)
 - [Breaking the links: Exploiting the linker](https://www.nth-dimension.org.uk/pub/BTL.pdf)

## Two's complement

It's used to represent signed integers. The formula is

$$
w = - a_{N - 1}\, 2^{N - 1} + \sum_{i = 0}^{N - 2} a_i\,2^i
$$

in practice the MSB has much more weight with respect to the others;
This system can represent the range \\([-2^{N - 1}, 2^{N - 1} - 1]\\).


Below a simple python function to calculate the value

```python
def twos_complement(input_value, num_bits):
    '''Calculates a two's complement integer from the given input value's bits'''
    mask = 2**(num_bits - 1)
    return -(input_value & mask) + (input_value & ~mask)
```

 - Twos complement: Negative numbers in binary [video](https://youtu.be/4qH4unVtJkE)
 - [Number Systems](http://www.syssec.ethz.ch/content/dam/ethz/special-interest/infk/inst-infsec/system-security-group-dam/education/Digitaltechnik_14/12_NumberSystems.pdf)
 - [The CARRY flag and OVERFLOW flag in binary arithmetic](http://teaching.idallen.com/dat2343/10f/notes/040_overflow.txt)

