# MIPS

**Microprocessor without Interlocked Pipeline Stages**

## Registers

| number | name | description |
|--------|------|-------------|
| 0 | zero | always zero |
| 1 | at | temporary |
| 2-3 | v0-v1 | return value from a function call |
| 4-7 | a0-a3 | first four parameters of a function call |
| 8-15 | t0-t7 | temporary variables need not to be preserved |
| 16-23 | s0-s7 | function variables, must be preserved |
| 24-25 | t8-t9 | two more temporary variables |
| 26-27 | k0-k1 | kernel use registers |
| 28 | gp | global pointer |
| 29 | st | stack pointer |
| 30 | fp | frame pointer |
| 31 | ra | return address register |

## Instruction set

| Instruction | short name | description |
|-------------|------------|-------------|
| slti r, s, imm | Set on less than immediate (signed) | If ``s`` is less than immediate, ``t`` is set to one. It gets zero otherwise. |

## Links

 - [MIPS alternative registers name](https://www.cs.umd.edu/class/sum2003/cmsc311/Notes/Mips/altReg.html)
 - [Cheat sheet](https://inst.eecs.berkeley.edu/~cs61c/resources/MIPS_Green_Sheet.pdf)
 - [MIPS Basic Training Course](https://community.imgtec.com/developers/mips/resources/training-courses/mips-basic-training-course/)
 - [MIPS32® Instruction Set Quick Reference](https://www.cs.duke.edu/courses/fall13/compsci250/MIPS32_QRC.pdf)
 - [MIPS: non-virtualizable architecture (Part 1)](http://www.nulltrace.org/2011/04/mips-non-virtualizable-architecture.html)
 - [Exceptions in MIPS](http://www.cs.iit.edu/~virgil/cs470/Labs/Lab7.pdf)
 - MIPS binary [repo](https://github.com/darkerego/mips-binaries)
 - The MIPS R4000
   - [Introduction](https://blogs.msdn.microsoft.com/oldnewthing/20180402-00/?p=98415)
   - [32-bit integer calculations](https://blogs.msdn.microsoft.com/oldnewthing/20180403-00/?p=98425)
 - [MIPS architecture overview](https://tams.informatik.uni-hamburg.de/applets/hades/webdemos/mips.html)

