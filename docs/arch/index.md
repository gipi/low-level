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

## RISC

The name stands for **Reduced instruction set computing**: it's a CPU design.

 - [MIPS vs. ARM Assembly](http://www2.ece.gatech.edu/academic/courses/ece2035/readings/embedded/MIPSvsARM.pdf)


### SPARC

**Scalable Processor ARChitecture**. It's an ``ISA``.

### POWERPC

**Performance Optimization With Enhanced RISC**

### 65(C)02

The MOS Technology 6502 is a little-endian 8-bit microprocessor with a 16 bit address bus 

 - [Wikipedia page](https://en.wikipedia.org/wiki/MOS_Technology_6502)
 - [cc65](https://cc65.github.io/cc65/) is a complete cross development package for 65(C)02 systems, including a powerful macro assembler, a C compiler, linker, librarian and several other tools.

### Ricoh 5A22/SNES

The Ricoh 5A22 is a microprocessor produced by Ricoh for the Super Nintendo Entertainment System (SNES) video game console
and is based on the MOS Technology 6502 family of processors.

 - [The Edge of Emulation](https://byuu.org/articles/edge-of-emulation): the limit of software emulation for the PPU
 - [THE POLYGONS OF ANOTHER WORLD: SUPER NINTENDO](http://fabiensanglard.net/another_world_polygons_SNES/index.html)

### RISC-V

Open source ISA

 - [Home page](https://riscv.org/)
 - [potato](https://github.com/skordal/potato) A simple RISC-V processor for use in FPGA designs.


## Links

 - What every programmer should know about memory, Part 1 [LWN](http://lwn.net/Articles/250967/)
 - [Baking Pi – Operating Systems Development](https://www.cl.cam.ac.uk/projects/raspberrypi/tutorials/os/)
 - [Build a Debian Jessie root filesystem](http://www.acmesystems.it/debian_jessie) how to build an Debian Jessie root filesystem using ``multistrap``

