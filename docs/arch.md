# Architecture

In order to run some software you need a real machine and
real machines come with a great variety of architecture: a kind of differentiation
could be

 * **load/store** architecture: instructions are divided in two categories: **memory access** and **ALU operations** between registers.
 * **register** architecture: instructions are not divided and operations like ``add`` can be between memory and registers.

In particular, the kind of architecture can influence the way a function is called:

 - [Function calls in C: the boring specs](http://www.gghh.name/dibtp/2015/11/10/function-calls-in-c-the-boring-specs.html)
 - [Function calls in C: a practical example](http://www.gghh.name/dibtp/2015/11/11/function-calls-in-c-practical-example.html)

## Assembler

There are two notations: **Intel** and **AT&T**.

 - [Intel and AT&T Syntax](http://www.imada.sdu.dk/Courses/DM18/Litteratur/IntelnATT.htm)
 - [GNU As manual](http://tigcc.ticalc.org/doc/gnuasm.html)

## ISA

 - [Wikipedia](https://en.wikipedia.org/wiki/Instruction_set)

### Microarchitecture

In electronics engineering and computer engineering, [microarchitecture](https://en.wikipedia.org/wiki/Microarchitecture), also
called computer organization and sometimes abbreviated as µarch or uarch, is
the way a given instruction set architecture (ISA) is implemented in a
particular processor. A given ISA may be implemented with different
microarchitectures; implementations may vary due to different goals of a
given design or due to shifts in technology.

### Computer architecture

Computer architecture is the combination of microarchitecture and instruction set designs.

## X86

**x86** is a family of backward compatible instruction set architectures
based on the Intel 8086 CPU and its Intel 8088 variant.

 - [Assembly Wikibook](https://en.wikibooks.org/wiki/X86_Assembly)
 - [A fundamental introduction to x86 assembly programming](https://www.nayuki.io/page/a-fundamental-introduction-to-x86-assembly-programming)
 - [The mysteries arround "0x7C00" in x86 architecture bios bootloader](http://www.glamenv-septzen.net/en/view/6)
 - [Shellcode obfuscation](https://breakdev.org/x86-shellcode-obfuscation-part-2/) talk about internal format of opcode

## AMD64

**x86-64** is the 64-bit version of the x86 instruction set. 

1. User-level applications use as integer registers for passing the sequence %rdi, %rsi, %rdx, %rcx, %r8 and %r9. The kernel interface uses %rdi, %rsi, %rdx, %r10, %r8 and %r9.
2. A system-call is done via the syscall instruction. The kernel destroys registers %rcx and %r11.
3. The number of the syscall has to be passed in register %rax.
4. System-calls are limited to six arguments, no argument is passed directly on the stack.
5. Returning from the syscall, register %rax contains the result of the system-call. A value in the range between -4095 and -1 indicates an error, it is -errno.
6. Only values of class INTEGER or class MEMORY are passed to the kernel.

### Links

 - [Gentle Introduction to x86-64 Assembly](http://www.x86-64.org/documentation/assembly.html)

## RISC

The name stands for **Reduced instruction set computing**: it's a CPU design.

### ARM

 - [Reverse engineering the ARM1](http://www.righto.com/2015/12/reverse-engineering-arm1-ancestor-of.html)
 - [More ARM1 processor reverse engineering: the priority encoder](http://www.righto.com/2016/01/more-arm1-processor-reverse-engineering.html)
 - [The ARM Instruction Set Architecture](http://users.ece.utexas.edu/~valvano/EE345M/Arm_EE382N_4.pdf)

### MIPS

**Microprocessor without Interlocked Pipeline Stages**

### SPARC

**Scalable Processor ARChitecture**. It's an ``ISA``.

### POWERPC

**Performance Optimization With Enhanced RISC**

## Links

 - What every programmer should know about memory, Part 1 [LWN](http://lwn.net/Articles/250967/)
 - [Baking Pi – Operating Systems Development](https://www.cl.cam.ac.uk/projects/raspberrypi/tutorials/os/)
