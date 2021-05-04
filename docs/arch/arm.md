# ARM

The ARM architecture is a 32-bit RISC architecture with 16 general
purpose registers available to regular programs and a status
register (actually there are more general purpose registers and
status registers but those are only used in exception modes and not
important for our discussion). Every instruction is 4 bytes long,
this is
very different from the x86 architecture which has variable length
instructions.

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

## Coprocessors

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

[However](https://stackoverflow.com/questions/19544694/understanding-mrc-on-arm7) coprocessor in ARM is a misleading notion. It's shorthand for an
optional piece of functionality that is not exposed via the core
instruction set. ARM CPUs are modular. There are bits and pieces
of CPU hardware that implementers of the architecture may or may
not place on the chip. The memory management unit (MMU) is one example;
there are others, such is the hardware debugging facility. Those are,
indeed, identified by coprocessor number (pXX), so that more than one
coprocessor can be present at the same time. The coprocessor number
for MMU is traditionally p15. Coprocessors p0..p14 have nothing to
do with memory management and may not be present. The debugging subsystem,
for example, is p14.

 - [Processor setup via co-processor 15 and about co-processors](http://www.heyrick.co.uk/assembler/coprocmnd.html)

## Instruction set

![](../images/arm-isa.png)

### Links

 - A few documents about it
   - [Cheat sheet](http://infocenter.arm.com/help/topic/com.arm.doc.qrc0001l/QRC0001_UAL.pdf)
   - [specification](http://vision.gel.ulaval.ca/~jflalonde/cours/1001/h17/docs/arm-instructionset.pdf)
   - [The Instruction Set](http://www.peter-cockerell.net/aalp/html/ch-3.html)
   - [ARM instruction set](http://vision.gel.ulaval.ca/~jflalonde/cours/1001/h17/docs/arm-instructionset.pdf)
   - [The ARM Instruction Set Architecture](http://users.ece.utexas.edu/~valvano/EE345M/Arm_EE382N_4.pdf)
   - [ARM immediate value encoding](https://alisdair.mcdiarmid.org/arm-immediate-value-encoding/)
   - [Instruction set](https://cs107e.github.io/readings/armisa.pdf)


 - [Why does the ARM PC register point to the instruction after the next one to be executed?
](https://stackoverflow.com/questions/24091566/why-does-the-arm-pc-register-point-to-the-instruction-after-the-next-one-to-be-e/24092329#24092329): original ARM has 3-stage pipeline (fetch-decode-execute) so you have to add 2 words to calculate offset from pc: it's more useful in reversing probably

    In ARM state, the value of the PC is the address of the current instruction plus 8 bytes.

    In Thumb state:

    For B, BL, CBNZ, and CBZ instructions, the value of the PC is the address of the current instruction plus 4 bytes.
    For all other instructions that use labels, the value of the PC is the address of the current instruction plus 4 bytes, with bit[1] of the result cleared to 0 to make it word-aligned.

## Links

 - [A Brief History of Arm: Part 1](https://community.arm.com/developer/ip-products/processors/b/processors-ip-blog/posts/a-brief-history-of-arm-part-1)
 - [A Brief History of Arm: Part 2](https://community.arm.com/developer/ip-products/processors/b/processors-ip-blog/posts/a-brief-history-of-arm-part-2)
 - [List of ARM microarchitectures](https://en.wikipedia.org/wiki/List_of_ARM_microarchitectures)
 - [ARM architecture overview](https://web.eecs.umich.edu/~prabal/teaching/eecs373-f10/readings/ARM_Architecture_Overview.pdf)
 - [ARM1176JZFS specification](http://infocenter.arm.com/help/topic/com.arm.doc.ddi0301h/ddi0301h_arm1176jzfs_r0p7_trm.pdf)
 - [Status register](https://www.heyrick.co.uk/armwiki/The_Status_register)
 - [Cortex-M for beginners](/documents/Cortex-M for Beginners - 2017_EN_v2.pdf)
 - [open source baremetal coding resources for ARM Cortex-M](http://asm.thi.ng/)
 - [Alphanumeric RISC ARM Shellcode](http://phrack.org/issues/66/12.html)
 - [ARM assembly tutorial](https://azeria-labs.com/writing-arm-assembly-part-1/)
 - [ARM Cortex-M0 assembly programming tips and tricks](https://community.arm.com/docs/DOC-7869)
 - Intro to Cortex M0 and LPCxpresso 1114 [PDF](https://web.eecs.umich.edu/~prabal/teaching/eecs373-f10/slides/lec21.pdf)
 - [Difference between arm-eabi arm-gnueabi and gnueabi-hf compilers]
 - [ARM calling convention](http://caxapa.ru/thumbs/656023/IHI0042F_aapcs.pdf)
 - [Generica page about ARM](https://www.aldeid.com/wiki/Category:Architecture/ARM)
 - [Reverse engineering the ARM1](http://www.righto.com/2015/12/reverse-engineering-arm1-ancestor-of.html)
 - [More ARM1 processor reverse engineering: the priority encoder](http://www.righto.com/2016/01/more-arm1-processor-reverse-engineering.html)
 - [What is the difference between arm-eabi and gnueabi-hf](https://stackoverflow.com/questions/26692065/difference-between-arm-eabi-arm-gnueabi-and-gnueabi-hf-compilers)
 - [What is the difference between arm-linux-gcc and arm-none-linux-gnueabi](https://stackoverflow.com/questions/13797693/what-is-the-difference-between-arm-linux-gcc-and-arm-none-linux-gnueabi)
 - [VPF](https://en.wikipedia.org/wiki/ARM_architecture#Floating-point_.28VFP.29): technology is an FPU (Floating-Point Unit) coprocessor extension to the ARM architecture
 - [Whirlwind Tour of ARM Assembly](http://www.coranac.com/tonc/text/asm.htm)
 - [Online ARM To Hex Converter](http://armconverter.com/)
 - [White Paper: DSP capabilities of Cortex-M4 and Cortex-M7](https://community.arm.com/developer/ip-products/processors/b/processors-ip-blog/posts/white-paper-dsp-capabilities-of-cortex-m4-and-cortex-m7)
 - [posborne/cmsis-svd](https://github.com/posborne/cmsis-svd) This repository seeks to provide value to developers targetting ARM platforms in two main ways:
    - Provide a convenient place to access and aggregate CMSIS-SVD hardware descriptions from multiple sources.
    - Provide parsers that make code generation and tooling based on SVD easier to build. Most parsers simply parse a provided SVD file and turn it into a data structure more easily used in that language.
 - [libopencm3/libopencm3](https://github.com/libopencm3/libopencm3) Open source ARM Cortex-M microcontroller library
 - [How stack trace on ARM works](https://alexkalmuk.medium.com/how-stack-trace-on-arm-works-5634b35ddca1)

