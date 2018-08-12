# Formats

 - [CyberChef](https://gchq.github.io/CyberChef/) A simple, intuitive web app for analysing and decoding data without having to deal with complex tools or programming languages. CyberChef encourages both technical and non-technical people to explore data formats, encryption and compression.

## Endianess

 - [How Endianness Effects Bitfield Packing](http://mjfrazer.org/mjfrazer/bitfields/)

## Numeric format

 - [The secret life of NaN](https://anniecherkaev.com/the-secret-life-of-nan)

## Character encoding

 - [A tutorial on character code issues](https://www.cs.tut.fi/~jkorpela/chars.html)

### Notation

**Caret notation** is a notation for unprintable control characters in ASCII encoding.
The notation consists of a caret (^) followed by a capital letter.

### ASCII

Stands for ``American Standard Code for Information Interchange``, it's a 7bits code.

ASCII reserves the first 32 codes (numbers 0–31 decimal) for control characters: codes
originally intended not to represent printable information, but rather to control devices
(such as printers) that make use of ASCII, or to provide meta-information about data streams
such as those stored on magnetic tape.

### Unicode

Unicode is not an encoding but is a classification of characters: though each one is identified
by a number, this number is not used directly in its representation: 'UTF-8' is particular representation
where for compatibility purpose the ASCII set is maintained as is.

#### Links

 - http://www.cl.cam.ac.uk/~mgk25/unicode.html
 - http://canonical.org/~kragen/strlen-utf8.html
 - http://nedbatchelder.com/text/unipain/unipain.html
 - http://farmdev.com/talks/unicode/
 - http://www.joelonsoftware.com/articles/Unicode.html
 - http://www.2ality.com/2013/09/javascript-unicode.html
 - http://the-pastry-box-project.net/oli-studholme/2013-october-8/
 - http://www.utf8everywhere.org/
 - https://speakerdeck.com/mathiasbynens/hacking-with-unicode
 - http://agiliq.com/blog/2014/11/character-encoding-and-unicode/
 - http://eev.ee/blog/2015/09/12/dark-corners-of-unicode/
 - http://reedbeta.com/blog/programmers-intro-to-unicode/

For testing purpose use

    “Iñtërnâtiônàlizætiøn” looks like E2 80 9C 49 C3 B1 74 C3 AB 72 6E C3 A2 74 69 C3 B4 6E C3 A0 6C 69 7A C3 A6 74 69 C3 B8 6E E2 80 9D in UTF-8 in hex.

An implementation of ``strlen()`` is the following:

```c
# original from <http://canonical.org/~kragen/strlen-utf8.html>
.global strlen_utf8
strlen_utf8:
        push %esi
        cld
        mov 8(%esp), %esi
        xor %ecx, %ecx
loopa:  dec %ecx
loopb:  lodsb
        shl $1, %al
        js loopa         # x1xxxxxx
        jc loopb         # 1xxxxxxx
        jnz loopa        # 00xxxxxx
        mov %ecx, %eax
        not %eax
        pop %esi
        ret
```

## Zip

 - [Zip Files All The Way Down](http://research.swtch.com/zip)

## JPEG

 - [Polyglot JPG](http://blog.portswigger.net/2016/12/bypassing-csp-using-polyglot-jpegs.html)

## PNG

## PDF

 - [Reference](https://wwwimages2.adobe.com/content/dam/acom/en/devnet/pdf/PDF32000_2008.pdf)
 - Let's write a PDF file [speakerdeck](https://speakerdeck.com/ange/lets-write-a-pdf-file)
 - [PDF file format basic structure](http://resources.infosecinstitute.com/pdf-file-format-basic-structure/)
 - https://www.aldeid.com/wiki/Analysis-of-a-malicious-pdf
 - http://esec-lab.sogeti.com/posts/2009/06/26/at-least-4-ways-to-die-opening-a-pdf.html
 - https://www.osdefsec.com/analyzing-malicious-pdf/
 - http://eternal-todo.com/tools/peepdf-pdf-analysis-tool

## H264

 - [H.264 is Magic](https://sidbala.com/h-264-is-magic/)

## JSON

 - [Parsing JSON is a Minefield](http://seriot.ch/parsing_json.html)

## ELF

An ``ELF`` file is identified by four magic bytes ``\x7FELF``; it has an header
that gives general information about the types of ``ELF`` file that can be

 - Relocatable file
 - Executable
 - Shared objects/library

the architecture and the entry point.

It defines a series of sections and segments (**program header** and **section header**), respectively describing
the execution and the linking for the file.

The kernel loads in memory only the ``PT_LOAD`` type and if is defined an interpreter (in
the section ``PT_INTERP``) call the interpreter to do its job (i.e. resolve the dynamic sections).

 - [Specification](http://www.skyfree.org/linux/references/ELF_Format.pdf)
 - [Cheating the ELF](documents/subversiveld.pdf)
 - [LIEF](https://lief-project.github.io) The purpose of this project is to provide a cross platform library which can parse, modify and abstract ELF, PE and MachO formats
 - [Why doesn't `strip` remove section headers from ELF executables?](https://unix.stackexchange.com/questions/267070/why-doesnt-strip-remove-section-headers-from-elf-executables)

### Relocation

### Core dumps

 - [core(5) man page](http://man7.org/linux/man-pages/man5/core.5.html)
 - [core File Format](https://www.ibm.com/support/knowledgecenter/ssw_aix_61/com.ibm.aix.files/core.htm)

### TLS

 - [https://www.akkadia.org/drepper/tls.pdf](https://www.akkadia.org/drepper/tls.pdf)
 - [Thread Local Storage](http://wiki.osdev.org/Thread_Local_Storage)
 
### Dwarf
 
  - https://www.ibm.com/developerworks/aix/library/au-dwarf-debug-format/index.html
  - http://www.dwarfstd.org/doc/Debugging%20using%20DWARF-2012.pdf
  - https://stackoverflow.com/questions/5954140/dumping-c-structure-sizes-from-elf-object-file
  - http://wiki.dwarfstd.org/index.php?title=DWARF_FAQ
  - https://landley.net/kdocs/ols/2007/ols2007v2-pages-35-44.pdf

### Links

 - Anatomy of a program in memory [POST](http://duartes.org/gustavo/blog/post/anatomy-of-a-program-in-memory/)
 - Cheating ELF [PDF](https://grugq.github.io/docs/subversiveld.pdf)
 - [Dissection of an ELF file](https://github.com/mewrev/dissection)
 - [Reversing an ELF from the ground up](http://anee.me/reversing-an-elf/)
 - [Source code of binfmt_elf](http://lxr.linux.no/linux+v3.1.4/fs/binfmt_elf.c#L559)
 - [How programs get run: ELF binaries](https://lwn.net/Articles/631631/)
 - [A Whirlwind Tutorial on Creating Really Teensy ELF Executables for Linux](http://www.muppetlabs.com/~breadbox/software/tiny/teensy.html)
 - [Executable and Linkable Format](https://0xax.gitbooks.io/linux-insides/content/Theory/ELF.html)
 - [Writeup about reversing ELF](http://pwning.fun//writeup/2017/11/03/HitconCTF2017-Everlasting-Imaginative-Void.html) with forged sections/segments
 - [Executable and Linkable Format 101 - Part 1 Sections and Segments](http://www.intezer.com/executable-linkable-format-101-part1-sections-segments/)
 - [Executable and Linkable Format 101. Part 2: Symbols](http://www.intezer.com/executable-linkable-format-101-part-2-symbols/)
 - [Shared libraries and execute permissions](https://www.technovelty.org/linux/shared-libraries-and-execute-permissions.html)

## Miscellanea

 - [500 Byte Images: The Haiku Vector Icon Format](http://blog.leahhanson.us/post/recursecenter2016/haiku_icons.html)
