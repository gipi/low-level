# Reversing

 - https://advancedpersistentjest.com/2017/06/19/reversing-the-balong-m3mcu-console-lightning-the-path-to-ring-0/
 - https://blog.ret2.io/2017/11/16/dangers-of-the-decompiler/
 - https://puri.sm/posts/primer-to-reverse-engineering-intel-fsp/
 - https://quequero.org/2017/07/arm-exploitation-iot-episode-1/
 - https://quequero.org/2017/09/arm-exploitation-iot-episode-2/
 - https://quequero.org/2017/11/arm-exploitation-iot-episode-3/
 - http://kakaroto.homelinux.net/2017/11/introduction-to-reverse-engineering-and-assembly/
 - https://rdomanski.github.io/Reverse-engineering-of-ARM-Microcontrollers/
 - http://grangeia.io/2015/11/30/hacking-tomtom-runner-pt3/
 - [Reverse Engineering using the Linux Operating System](http://reverse.lostrealm.com/)
 - [Breaking State-of-the-Art Binary Code Obfuscation](https://recon.cx/2018/brussels/resources/slides/RECON-BRX-2018-Breaking-state-of-the-art-binary-code-obfuscation.pdf)
 - RECON Bruxelles 2018 [slide](https://recon.cx/2018/brussels/slides/)
 - [BOLO: Reverse Engineering — Part 1 (Basic Programming Concepts)](https://medium.com/@danielabloom/bolo-reverse-engineering-part-1-basic-programming-concepts-f88b233c63b7)
 - [Starting Embedded Reverse Engineering: FreeRTOS, libopencm3 on STM32F103C8T6](https://blog.3or.de/starting-embedded-reverse-engineering-freertos-libopencm3-on-stm32f103c8t6.html)
 
## Hardware

### Links

 - [zeptobars](https://zeptobars.com/en/)
 - [visual6502](http://visual6502.org/)
 - [siliconpr0n](http://siliconpr0n.org/)
 - [CSCI 4974 / 6974 Hardware Reverse Engineering](http://security.cs.rpi.edu/courses/hwre-spring2014/)
 - [UPC UBEE EVW3226 WPA2 Password Reverse Engineering](https://deadcode.me/blog/2016/07/01/UPC-UBEE-EVW3226-WPA2-Reversing.html)
 - [im-me LCD Interface Hacked](https://daveshacks.blogspot.it/2010/01/im-me-lcd-interface-hacked.html)
 - [Reverse Engineering Flash Memory for Fun and Benefit](https://www.blackhat.com/docs/us-14/materials/us-14-Oh-Reverse-Engineering-Flash-Memory-For-Fun-And-Benefit-WP.pdf)
 - [Reverse Engineering the TP-Link HS110](https://www.softscheck.com/en/reverse-engineering-tp-link-hs110/)
 - [Embedded Devices Security Firmware Reverse Engineering](https://media.blackhat.com/us-13/US-13-Zaddach-Workshop-on-Embedded-Devices-Security-and-Firmware-Reverse-Engineering-Slides.pdf)
 - [Reversing the parrot skycontroller firmware](http://thecyberrecce.net/2017/01/09/reversing-the-parrot-skycontroller-firmware/)
 - [Reverse Engineering the TP-Link HS110](https://www.softscheck.com/en/reverse-engineering-tp-link-hs110/)
 - [depcb](https://github.com/unixdj/depcb): PCB Reverse Engineering tool
 - [Reversing the 76477 "Space Invaders" sound effect chip from die photos](http://www.righto.com/2017/04/reverse-engineering-76477-space.html)
 - [NMOS IC Reverse Engineering](https://www.wdj-consulting.com/blog/nmos-sample.html)
 - [Video](https://www.youtube.com/watch?v=aHx-XUA6f9g) Reading Silicon: How to Reverse Engineer Integrated Circuits
 - [Pwn2Win 2017 - Shift Register](http://blog.dragonsector.pl/2017/10/pwn2win-2017-shift-register.html)
 - [Silicon die analysis: inside an op amp with interesting "butterfly" transistors](http://www.righto.com/2018/06/silicon-die-analysis-op-amp-with.html)


## Software

### Java

 - [Introduction to Radare Java Reverse Engineering](http://deeso.github.io/posts/2014/04/radare-java-intro/)

It is possible to edit a single class file and save it, after that you can reput it into the jar with

```
$ jar uf jar-file input-file(s)
```

If you want to quickly find class names you can launch this oneliner 

```
$ for f in $(ls /path/to/jars/*); do echo '-- '$f' --';strings -10 $f;done | less
```

### Android 

 - http://www.juanurs.com/Bypassing-Android-Anti-Emulation-Part-II/

### Links

 - [Reverse engineering and removing Pokémon GO’s certificate pinning](https://eaton-works.com/2016/07/31/reverse-engineering-and-removing-pokemon-gos-certificate-pinning/)
 - [Toy decompiler for x86-64 written in Python](https://yurichev.com/writings/toy_decompiler.pdf)
 - [Finding the actual Thumb code in firmware](https://reverseengineering.stackexchange.com/questions/5945/finding-the-actual-thumb-code-in-firmware)
 - [Reverse Engineering Exercises](https://github.com/rotlogix/arm_reverse_engineering_exercises) for ARM
 - [Android application reversing 101](https://www.evilsocket.net/2017/04/27/Android-Applications-Reversing-101/)

### Binwalk

```
$ git clone https://github.com/devttys0/binwalk && cd binwalk
$ sudo ./deps.sh
$ sudo python setup.py install
```

### Plasma

Interactive disassembler for x86/ARM/MIPS. Generates indented pseudo-code with colored syntax code.

This is the [github repo](https://github.com/joelpx/plasma). The installation instructions are strange
but a simple

```
$ pip3 install -r requirements.txt
$ ./install.sh --update
```

(use ``update`` also the first time otherwise it will clone ``capstone`` without reason).

```
$ plasma -i /opt/low-level/docs/code/payload-eater_x86
plasma> help
analyzer
      Analyzer status.
dump SYMBOL|0xXXXX|EP [NB_LINES]
      Print contents at the specified address.
exit
      Exit
frame_size [SYMBOL|0xXXXX|EP] frame_size
      Change the frame size of a function, the function will be re-analyzed.
functions
      Print the function list.
help
      Display this help.
hexdump SYMBOL|0xXXXX|EP [NB_LINES]
      Dump memory in hexa.
history
      Display the command history.
info
      Information about the current binary.
jmptable INST_ADDR TABLE_ADDR NB_ENTRIES SIZE_ENTRY
      Create a jump table referenced at TABLE_ADDR and called
      from INST_ADDR.
memmap
      Open a qt window to display the memory.
mips_set_gp ADDR
      Set the register $gp to a fixed value. Note that it will
      erase all defined memory.
py [!][FILE]
      Run an interactive python shell or execute a script.
      Global variables api and args will be passed to the script.
      The character ! is an alias to the scripts directory.
push_analyze_symbols
      Force to analyze the entry point, symbols and a memory scan will be done.
rename OLD_SYM NEW_SYM
      Rename a symbol.
save
      Save the database.
sections
      Print all sections.
sym [SYMBOL 0xXXXX] [| FILTER]
      Print all symbols or set a new symbol.
      You can filter symbols by searching the word FILTER.
      If FILTER starts with -, the match is inversed.
x [SYMBOL|0xXXXX|EP]
      Decompile and print on stdout. By default it will be main.
      The decompilation is forced, it dosn't check if addresses
      are defined as code.
v [SYMBOL|0xXXXX|EP|%VISUAL]
      Visual mode: if no address is given, previous visual is
      reopen. You can keep up to 3 visuals. Use %1, %2 or %3
      to select the visual.

      Main shortcuts:
      c       create code
      b/w/d/Q create byte/word/dword/qword
      a       create ascii string
      p       create function
      o       set [d|q]word as an offset
      *       create an array
      x       show xrefs
      r       rename
      space   highlight current word (ctrl-k to clear)
      ;       edit inline comment (enter/escape to validate/cancel)
      U       undefine

      Options:
      I       switch to traditional instruction string output (3 modes)
      M       show/hide mangling
      B       show/hide bytes

      Navigation:
      |       split the window
      j       jump to an address or a symbol
      /       binary search: if the first char is ! you can put an
              hexa string example: /!ab 13 42
              the search is case sensitive.
      n/N     next/previous search occurence
      g       top
      G       bottom
      z       set current line on the middle
      %       goto next bracket
      { }     previous/next paragraph
      tab     switch between dump/decompilation
      enter   follow address
      escape  go back
      u       re-enter
      q       quit
xrefs SYMBOL|0xXXXX|EP
      Print cross references to the specified address.
```

### Vivisect

This the [github](https://github.com/pdasilva/vivisect) page.

### Capstone

[Home page](http://www.capstone-engine.org/)

Below a random dump of the instruction to cross compile it
for ARM

```
# apt-get install gcc-arm-linux-gnueabi
$ git clone https://github.com/aquynh/capstone && cd capstone
$ CROSS=arm-linux-gnueabi- ./make.sh
 ...
$ file libcapstone.so
libcapstone.so: ELF 32-bit LSB  shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, BuildID[sha1]=d3aa90b9edfef4bdd461ac5908c7a2ec08b7d199, not stripped
```
