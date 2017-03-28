# Radare2

```
$ docker pull radare/radare2
$ docker run -it -v /path/to/dir/containing/binary/:/build /bin/bash
root@8c41772329f6:/# r2 /build/binary
 -- One does not simply write documentation.
[0x00000000]>
[0x004008e0]> f*~sym.jmp
f sym.jmp 10 0x00400cc4
[0x004008e0]> pdf@sym.jmp
/ (fcn) sym.jmp 10
|           ; var int local_8h @ rbp-0x8
|           ; CALL XREF from 0x00400e29 (sym.main)
|           0x00400cc4      55             push rbp
|           0x00400cc5      4889e5         mov rbp, rsp
|           0x00400cc8      48897df8       mov qword [rbp - local_8h], rdi
\           0x00400ccc      ffe7           jmp rdi
[0x00000815]> ?d sei
set interrupt disable status
```

Disassemble also for different architecture (like arm ``r2 -aarm -b16 gy1_v162.frm``).

## Print ELF

In the example below we print the ``ELF`` header of an executable and then
examine the first three program headers:

```
s 0
[0x00000000]> pfo elf32
[0x00000000]> pf.elf_header 
     ident : 0x00000000 = .ELF...
      type : 0x00000010 = type (enum elf_type) = 0x2 ; ET_EXEC
   machine : 0x00000012 = machine (enum elf_machine) = 0x3 ; EM_386
   version : 0x00000014 = 0x00000001
     entry : 0x00000018 = 0x08048450
     phoff : 0x0000001c = 0x00000034
     shoff : 0x00000020 = 0x00000964
     flags : 0x00000024 = 0x00000000
    ehsize : 0x00000028 = 0x0034
 phentsize : 0x0000002a = 0x0020
     phnum : 0x0000002c = 0x0008
 shentsize : 0x0000002e = 0x0028
     shnum : 0x00000030 = 0x001d
  shstrndx : 0x00000032 = 0x001a
[0x00000000]> pf.elf_phdr @0x34+(0x20*0)
   type : 0x00000034 = type (enum elf_p_type) = 0x6 ; PT_PHDR
 offset : 0x00000038 = 0x00000034
  vaddr : 0x0000003c = 0x08048034
  paddr : 0x00000040 = 0x08048034
 filesz : 0x00000044 = 0x00000100
  memsz : 0x00000048 = 0x00000100
  flags : 0x0000004c = flags (enum elf_p_flags) = 0x5 ; PF_Read_Exec
  align : 0x00000050 = 0x00000004
[0x00000000]> pf.elf_phdr @0x34+(0x20*1)
   type : 0x00000054 = type (enum elf_p_type) = 0x3 ; PT_INTERP
 offset : 0x00000058 = 0x00000134
  vaddr : 0x0000005c = 0x08048134
  paddr : 0x00000060 = 0x08048134
 filesz : 0x00000064 = 0x00000013
  memsz : 0x00000068 = 0x00000013
  flags : 0x0000006c = flags (enum elf_p_flags) = 0x4 ; PF_Read
  align : 0x00000070 = 0x00000001
[0x00000000]> pf.elf_phdr @0x34+(0x20*2)
   type : 0x00000074 = type (enum elf_p_type) = 0x1 ; PT_LOAD
 offset : 0x00000078 = 0x00000000
  vaddr : 0x0000007c = 0x08048000
  paddr : 0x00000080 = 0x08048000
 filesz : 0x00000084 = 0x0000072c
  memsz : 0x00000088 = 0x0000072c
  flags : 0x0000008c = flags (enum elf_p_flags) = 0x5 ; PF_Read_Exec
  align : 0x00000090 = 0x00001000
```

## Links

 - [Cheat sheet](https://github.com/zxgio/r2-cheatsheet/blob/master/r2-cheatsheet.pdf)
 - [A journey into radare2](https://www.megabeets.net/a-journey-into-radare-2-part-1/)
 - Radare2 [tutorial](http://solidsec.blogspot.de/2015/10/tool-radare-2-open-source-alternative.html)
 - https://www.dustri.org/b/exploiting-ezhp-pwn200-from-plaidctf-2014-with-radare2.html
 - http://wapiflapi.github.io/2015/04/22/single-null-byte-heap-overflow/
 - http://hxp.io/blog/16/CONFidence%20CTF%202015:%20Reversing%20400%20%22Deobfuscate%20Me%22%20writeup/
 - [Slide](http://radare.org/get/lacon2k15-esil.pdf) Emulating Code In Radare2
 - http://www.oklabs.net/skype-reverse-engineering-the-long-journey/
 - [Github](https://github.com/rotlogix/Exercises) repo with exercises of ARM reversing
 - [Post](http://ctfhacker.com/ctf/python/symbolic/execution/reverse/radare/2015/11/28/cmu-binary-bomb-flag2.html) about symbolic execution with ``angr``
 - [Radare2 of the Lost Magic Gadget](https://0xabe.io/howto/exploit/2016/03/30/Radare2-of-the-Lost-Magic-Gadget.html)
 - [Radare 2 in 0x1E minutes](https://blog.techorganic.com/2016/03/08/radare-2-in-0x1e-minutes/)
 - [BINARY BOMB WITH RADARE2 - PRELUDE](https://unlogic.co.uk/2016/04/12/binary-bomb-with-radare2-prelude/)
 - [TUM CTF 2016: zwiebel (rev 50)](https://losfuzzys.github.io/writeup/2016/10/03/tumctf-zwiebel50/) radare2 automation
 - [ReverUsing Radare2](https://0x6d696368.blogspot.it/2016/10/rever-using-radare2.html)
 - [Android malware analysis with Radare: Dissecting the Triada Trojan](https://www.nowsecure.com/blog/2016/11/21/android-malware-analysis-radare-triada-trojan/)
 - [Practical Firmware Reversing and Exploit Development for AVR-based Embedded Devices](http://www.radare.org/get/avrworkshops2016.pdf)
 - Short [Video](https://www.youtube.com/watch?v=G_yqIW-pUNc): radare2 esil emulation
 - [Emulating a simple bootloader](http://radare.today/posts/emulating-simple-bootloader/)
 - [Using Emulation To Unpack Metasploit Encoders](https://xpnsec.tumblr.com/post/156211722581/radare2-using-emulation-to-unpack-metasploit)
 - [Disassembling 6502 code with Radare – Part I](https://retro.moe/2015/11/18/disassembling-6502-code-with-radare-part-i/)
