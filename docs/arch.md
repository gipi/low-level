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

Four principles of IS architecture

 - simplicity favors regularity
 - smaller is faster
 - good design demands compromise
 - make the common case fast

### Links

 - [Wikipedia](https://en.wikipedia.org/wiki/Instruction_set)

### Microarchitecture

In electronics engineering and computer engineering, [microarchitecture](https://en.wikipedia.org/wiki/Microarchitecture), also
called computer organization and sometimes abbreviated as µarch or uarch, is
the way a given instruction set architecture (ISA) is implemented in a
particular processor. A given ISA may be implemented with different
microarchitectures; implementations may vary due to different goals of a
given design or due to shifts in technology.

 - [MIPS Pipeline](https://www.cs.cornell.edu/courses/cs3410/2012sp/lecture/09-pipelined-cpu-i-g.pdf)

### Computer architecture

Computer architecture is the combination of microarchitecture and instruction set designs.

## X86

**x86** is a family of backward compatible instruction set architectures
based on the Intel 8086 CPU and its Intel 8088 variant.

 - [Assembly Wikibook](https://en.wikibooks.org/wiki/X86_Assembly)
 - [A fundamental introduction to x86 assembly programming](https://www.nayuki.io/page/a-fundamental-introduction-to-x86-assembly-programming)
 - [Encoding Real x86 Instructions](http://www.c-jump.com/CIS77/CPU/x86/lecture.html)
 - [The mysteries arround "0x7C00" in x86 architecture bios bootloader](http://www.glamenv-septzen.net/en/view/6)
 - [Shellcode obfuscation](https://breakdev.org/x86-shellcode-obfuscation-part-2/) talk about internal format of opcode
 - [x86 paging](http://www.cirosantilli.com/x86-paging/)

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

 - [MIPS vs. ARM Assembly](http://www2.ece.gatech.edu/academic/courses/ece2035/readings/embedded/MIPSvsARM.pdf)

### ARM

The ARM architecture is a 32-bit RISC architecture with 16 general
purpose registers available to regular programs and a status
register (actually there are more general purpose registers and
status registers but those are only used in exception modes and not
important for our discussion). Every instruction is 4 bytes long so
we must ensure that all 4 of these bytes are alphanumeric. This is
very different from the x86 architecture which has variable length
instructions. As a result, getting instructions to be completely
alphanumeric is harder on ARM than on x86.

Registers R0 to R12 are real general purpose registers that do not
have a dedicated purpose. Register R13 is used as a stack pointer
and can also be referred to as register SP. Register R14 is used as
the link register and is also referred to as LR. It contains the
return address for functions and exceptions. Register R15 contains
the current program counter and is also referred to as PC. Unlike
x86 architectures, we can directly read and write this register.
Reading from this register will return the currently executing
instruction + 8 bytes in ARM mode or the current instruction + 4
bytes in Thumb mode (see section 1.5). Writing to this register
causes execution to continue at this address.

#### Coprocessors

ARM processors can be extended with a number of coprocessors to
perform non-standard calculations and to avoid having to do these
calculations in software. ARM supports up to 16 coprocessors, each
of which has a unique identification number. Some processors might
need more than one identification number, in order to accommodate
large instruction sets. Coprocessors are available for memory
management, floating point operations, debugging, media,
cryptography, ...

When an ARM processor encounters an instruction it cannot process,
it sends the instruction out on the coprocessor bus. If a
coprocessor recognizes the instruction, it can execute it and
respond to the main processor. If none of the coprocessors respond,
an 'illegal instruction' exception is raised.

 - [ARM calling convention](http://caxapa.ru/thumbs/656023/IHI0042F_aapcs.pdf)
 - [Generica page about ARM](https://www.aldeid.com/wiki/Category:Architecture/ARM)
 - [Reverse engineering the ARM1](http://www.righto.com/2015/12/reverse-engineering-arm1-ancestor-of.html)
 - [More ARM1 processor reverse engineering: the priority encoder](http://www.righto.com/2016/01/more-arm1-processor-reverse-engineering.html)
 - [The ARM Instruction Set Architecture](http://users.ece.utexas.edu/~valvano/EE345M/Arm_EE382N_4.pdf)
 - [ARM Cortex-M0 assembly programming tips and tricks](https://community.arm.com/docs/DOC-7869)
 - Intro to Cortex M0 and LPCxpresso 1114 [PDF](https://web.eecs.umich.edu/~prabal/teaching/eecs373-f10/slides/lec21.pdf)
 - [Difference between arm-eabi arm-gnueabi and gnueabi-hf compilers](https://stackoverflow.com/questions/26692065/difference-between-arm-eabi-arm-gnueabi-and-gnueabi-hf-compilers)
 - [What is the difference between arm-linux-gcc and arm-none-linux-gnueabi](https://stackoverflow.com/questions/13797693/what-is-the-difference-between-arm-linux-gcc-and-arm-none-linux-gnueabi)
 - [VPF](https://en.wikipedia.org/wiki/ARM_architecture#Floating-point_.28VFP.29): technology is an FPU (Floating-Point Unit) coprocessor extension to the ARM architecture
 - [Alphanumeric RISC ARM Shellcode](http://phrack.org/issues/66/12.html)

### AVR

Modified Harvard architecture 8-bit ``RISC`` microcontroller. Atmel's AVRs have a two-stage, single-level pipeline design.

There are the following registers:

 - 32 general purpose 8-bit registers, ``r0``-``r31``; with some alias like ``x=r27:r26``, ``y=r29:28`` and ``z=r31:r30``
 - ``pc`` 16- or 22-bit program counter
 - ``sp`` 8- or 16-bit stack pointer
 - ``sreg`` 8-bit status register
 - ``rampx``, ``rampy``, ``rampz`` and ``eind``

#### Links

 - [Wikipedia's AVR Instruction set](https://en.wikipedia.org/wiki/Atmel_AVR_instruction_set)

### MIPS

**Microprocessor without Interlocked Pipeline Stages**

 - [MIPS Basic Training Course](https://community.imgtec.com/developers/mips/resources/training-courses/mips-basic-training-course/)
 - [MIPS32® Instruction Set Quick Reference](https://www.cs.duke.edu/courses/fall13/compsci250/MIPS32_QRC.pdf)
 - [MIPS: non-virtualizable architecture (Part 1)](http://www.nulltrace.org/2011/04/mips-non-virtualizable-architecture.html)
 - [Exceptions in MIPS](http://www.cs.iit.edu/~virgil/cs470/Labs/Lab7.pdf)

### SPARC

**Scalable Processor ARChitecture**. It's an ``ISA``.

### POWERPC

**Performance Optimization With Enhanced RISC**

## 65(C)02

The MOS Technology 6502 is a little-endian 8-bit microprocessor with a 16 bit address bus 

 - [Wikipedia page](https://en.wikipedia.org/wiki/MOS_Technology_6502)
 - [cc65](https://cc65.github.io/cc65/) is a complete cross development package for 65(C)02 systems, including a powerful macro assembler, a C compiler, linker, librarian and several other tools.


## Links

 - What every programmer should know about memory, Part 1 [LWN](http://lwn.net/Articles/250967/)
 - [Baking Pi – Operating Systems Development](https://www.cl.cam.ac.uk/projects/raspberrypi/tutorials/os/)
 - [Build a Debian Jessie root filesystem](http://www.acmesystems.it/debian_jessie) how to build an Debian Jessie root filesystem using ``multistrap``

