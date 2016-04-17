# Reversing

## Hardware

### Links

 - [CSCI 4974 / 6974 Hardware Reverse Engineering](http://security.cs.rpi.edu/courses/hwre-spring2014/)

## Software

### Radare2

```
$ docker pull radare/radare2
$ docker run -it -v /path/to/dir/containing/binary/:/build /bin/bash
root@8c41772329f6:/# r2 /build/binary
 -- One does not simply write documentation.
[0x00000000]>
```

### Links

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
