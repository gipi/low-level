
 - [The definitive guide to linux system calls](http://blog.packagecloud.io/eng/2016/04/05/the-definitive-guide-to-linux-system-calls/)
 - [Syscalls table](https://filippo.io/linux-syscall-table/)
 - [Practical Guide to Bare Metal C++](https://arobenko.gitbooks.io/bare_metal_cpp)
 - [Writing C++17 for 16-bit x86](https://dev.krzaq.cc/post/writing-cpp17-for-16bit-x86/)
 - [Anatomy of a Program in Memory](http://duartes.org/gustavo/blog/post/anatomy-of-a-program-in-memory/)
 - [The Kernel Boot Process](http://duartes.org/gustavo/blog/post/kernel-boot-process/)
 - [CPU Rings, Privilege, and Protection](http://duartes.org/gustavo/blog/post/cpu-rings-privilege-and-protection/)
 - Hello from a libc-free world!
    * [part1](https://blogs.oracle.com/ksplice/entry/hello_from_a_libc_free)
    * [part2](https://blogs.oracle.com/ksplice/entry/hello_from_a_libc_free1)
 - [Protected mode programming tutorial](http://prodebug.sourceforge.net/pmtut.html)
 - [Linux Inside](https://www.gitbook.com/book/0xax/linux-insides/details)
 - [Linux System Calls, Error Numbers, and In-Band Signaling](http://nullprogram.com/blog/2016/09/23/)
 - [Linux containers in 500 lines of code](https://blog.lizzie.io/linux-containers-in-500-loc.html)
 - [Linux Performance](http://www.brendangregg.com/linuxperf.html)
 - [Video](https://www.youtube.com/watch?v=GsMs3n8CB6g): Give me 15 minutes and I'll change your view of Linux tracing
 - [gist](https://gist.github.com/marcan/a2eafd605d3d6ac76eb10a7c64f736c3) Linux kernel initialization, translated to bash

## Two's complement

It's used to represent signed integers. The formula is

$$
w = - a_{N - 1}\, 2^{N - 1} + \sum_{i = 0}^{N - 2} a_i\,2^i
$$

in practice the MSB has much more weight with respect to the others;
This system can represent the range $[-2^{N - 1}, 2^{N - 1} - 1]$


Below a simple python function to calculate the value

```python
def twos_complement(input_value, num_bits):
    '''Calculates a two's complement integer from the given input value's bits'''
    mask = 2**(num_bits - 1)
    return -(input_value & mask) + (input_value & ~mask)
```
