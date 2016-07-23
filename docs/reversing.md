# Reversing

## Hardware

### Links

 - [CSCI 4974 / 6974 Hardware Reverse Engineering](http://security.cs.rpi.edu/courses/hwre-spring2014/)
 - [UPC UBEE EVW3226 WPA2 Password Reverse Engineering](https://deadcode.me/blog/2016/07/01/UPC-UBEE-EVW3226-WPA2-Reversing.html)
 - [im-me LCD Interface Hacked](https://daveshacks.blogspot.it/2010/01/im-me-lcd-interface-hacked.html)
 - [Reverse Engineering Flash Memory for Fun and Benefit](https://www.blackhat.com/docs/us-14/materials/us-14-Oh-Reverse-Engineering-Flash-Memory-For-Fun-And-Benefit-WP.pdf)

## Software

### Radare2

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
```

#### Links

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

### Plasma

Interactive disassembler for x86/ARM/MIPS. Generates indented pseudo-code with colored syntax code.

This is the [github repo](https://github.com/joelpx/plasma).

```
$ plasma -i /opt/low-level/docs/code/payload-eater_x86
plasma> help
analyzer 
      Analyzer information
dump SYMBOL|0xXXXX|EP [NB_LINES]
      Disassemble only.
exit 
      Exit
functions 
      Print the function list.
help 
      Display this help
hexdump SYMBOL|0xXXXX|EP [NB_LINES]
      Dump memory in hexa.
history 
      Display the command history
info 
      Information about the current binary
jmptable INST_ADDR TABLE_ADDR NB_ENTRIES SIZE_ENTRY
      Create a jump table referenced at TABLE_ADDR and called
      from INST_ADDR.
mips_set_gp ADDR
      Set the register $gp to a fixed value.
py [FILE]
      Run an interactive python shell or execute a script.
      The global variable 'api' will be accessible.
push_analyze_symbols 
      Force to analyze the entry point, symbols and a memory scan will be done.
rename OLD_SYM NEW_SYM
      Rename a symbol.
save 
      Save the database (only symbols and history currently).
sections 
      Print all sections
sym [SYMBOL 0xXXXX] [| FILTER]
      Print all symbols or set a new symbol.
      You can filter symbols by searching the word FILTER.
      If FILTER starts with -, the match is inversed.
x [SYMBOL|0xXXXX|EP]
      Decompile and print on stdout. By default it will be main.
      The decompilation is forced, it dosn't check if addresses
      are defined as code.
v [SYMBOL|0xXXXX|EP]
      Visual mode
      Shortcuts:
      c       create code
      b/w/d/Q create byte/word/dword/qword
      a       create ascii string
      p       create function
      o       set [d|q]word as an offset
      x       show xrefs
      r       rename
      /       binary search: if the first char is ! you can put an
              hexa string example: /!ab 13 42
      n/N     next/previous search occurence
      I       switch to traditional instruction string output
      M       show/hide mangling
      B       show/hide bytes
      g       top
      G       bottom
      z       set current line on the middle
      Q       quit
      ;       edit inline comment (enter/escape to validate/cancel)
      %       goto next bracket
      *       highlight current word (ctrl-k to clear)
      { }     previous/next paragraph
      tab     switch between dump/decompilation
      enter   follow address
      escape  go back
      u       re-enter (for undo)
display.print_section 
      Print or not section when an address is found
xrefs SYMBOL|0xXXXX|EP
      Print all xrefs.
```

### Vivisect

This the [github](https://github.com/pdasilva/vivisect) page.
