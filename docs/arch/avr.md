# AVR

Modified Harvard architecture 8-bit ``RISC`` microcontroller. Atmel's AVRs have a two-stage, single-level pipeline design.

There are the following registers:

 - 32 general purpose 8-bit registers, ``r0``-``r31``; with some alias like ``x=r27:r26``, ``y=r29:28`` and ``z=r31:r30``
 - ``pc`` 16- or 22-bit program counter
 - ``sp`` 8- or 16-bit stack pointer
 - ``sreg`` 8-bit status register
 - ``rampx``, ``rampy``, ``rampz`` and ``eind``

Usually ``r0`` and ``r1`` are [fixed](https://gcc.gnu.org/wiki/avr-gcc#Fixed_Registers) as usage.

#### Links

 - [Wikipedia's AVR Instruction set](https://en.wikipedia.org/wiki/Atmel_AVR_instruction_set)
 - [Instruction set manual](http://roncella.iet.unipi.it/Didattica/Corsi/Elettronica/Risorse/Atmel-0856-AVR-Instruction-Set-Manual.pdf)
 - [Instruction set summary](http://www.avr-tutorials.com/sites/default/files/Instruction%20Set%20Summary.pdf)
 - [Branching](http://web.csulb.edu/~hill/ee346/Lectures/05%20AVR%20Branching.pdf)
 - [AVR opcodes table](https://embarc.org/man-pages/as/AVR-Opcodes.html) by ``as``
 - [Instructions encoding](http://web.csulb.edu/~hill/ee346/Lectures/16%20AVR%20Instruction%20Encoding.pdf)
 - [Table with opcode](http://www.zbasic.net/download/AVR_opcodes.txt)
