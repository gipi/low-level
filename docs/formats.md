# Formats

 - [Linux Foundation Referenced Specifications](https://refspecs.linuxfoundation.org/)
 - [CyberChef](https://gchq.github.io/CyberChef/) A simple, intuitive web app for analysing and decoding data without having to deal with complex tools or programming languages. CyberChef encourages both technical and non-technical people to explore data formats, encryption and compression.

## Endianess

 - [How Endianness Effects Bitfield Packing](http://mjfrazer.org/mjfrazer/bitfields/)

## Numeric format

 - [One hot](https://en.wikipedia.org/wiki/One-hot) is an encoding such that only one bit is one, all the other are zero
 - [The secret life of NaN](https://anniecherkaev.com/the-secret-life-of-nan)
 - [Float toy](https://evanw.github.io/float-toy/)

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
 - [Hacking GitHub with Unicode's dotless 'i'](https://eng.getwisdom.io/hacking-github-with-unicode-dotless-i/)

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

## Regex

![](/images/regex.png)

## Compression related (Zip, GZip)

The most common compression formats are all using the ``DEFLATE`` algorithm defined in
[RFC 1951](https://www.ietf.org/rfc/rfc1951.txt), in particular ``ZLIB`` (defined in
[RFC 1950](https://www.ietf.org/rfc/rfc1950.txt) and ``GZip`` (defined in
[RFC 1952](https://tools.ietf.org/html/rfc1952)); the ``Zip`` format instead is defined
[here](https://pkware.cachefly.net/webdocs/casestudies/APPNOTE.TXT).

### Links

 - [LZ77&LZ78](https://en.wikipedia.org/wiki/LZ77_and_LZ78)
 - [LZW](https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Welch)
 - [LZSS](https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Storer%E2%80%93Szymanski)
 - [LZMA](https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Markov_chain_algorithm)
 - [Dissecting the GZIP format](http://www.infinitepartitions.com/art001.html)
 - [Zip Files All The Way Down](http://research.swtch.com/zip)
 - [The structure of a PKZip file](https://users.cs.jmu.edu/buchhofp/forensics/formats/pkzip.html)
 - [A better zip bomb](https://www.bamsoftware.com/hacks/zipbomb/)
 - [How to make compressed file quines, step by step](https://blog.matthewbarber.io/2019/07/22/how-to-make-compressed-file-quines)
 - [YouFLATE](https://github.com/XlogicX/YouFLATE) An interactive tool that allows you to DEFLATE (compress) data using your own length-distance pairs, not merely the most efficient ones as is default with DEFLATE.
 - [infgen](https://github.com/madler/infgen) Deflate disassember to convert a deflate, zlib, or gzip stream into a readable form.

## JPEG

 - [Unraveling the JPEG](https://parametric.press/issue-01/unraveling-the-jpeg/)
 - [Polyglot JPG](http://blog.portswigger.net/2016/12/bypassing-csp-using-polyglot-jpegs.html)

## PNG

 - [PNG Merge](http://wiki.yobi.be/wiki/PNG_Merge) this is a Poc (Proof of Concept) to create a PNG file that contains different images somehow entangled together. 

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

This is a prime that is also an ``ELF``:

```
7f454c46010101000000000000000000020003000100000054800408340000000000000000000000340020000100000000000000010000000000000000800408008004085b0000005b0000000500000000100000b32a31c040cd80597ec9b11d
```

 - [Specification](http://www.skyfree.org/linux/references/ELF_Format.pdf)
 - [Cheating the ELF](documents/subversiveld.pdf)
 - [LIEF](https://lief-project.github.io) The purpose of this project is to provide a cross platform library which can parse, modify and abstract ELF, PE and MachO formats
 - [Why doesn't `strip` remove section headers from ELF executables?](https://unix.stackexchange.com/questions/267070/why-doesnt-strip-remove-section-headers-from-elf-executables)
 - [0pack](https://github.com/Luis-Hebendanz/0pack) A novel technique to hide code from debuggers
 - [Analyzing ELF Binaries with Malformed Headers Part 1 - Emulating Tiny Programs](https://binaryresearch.github.io/2019/09/17/Analyzing-ELF-Binaries-with-Malformed-Headers-Part-1-Emulating-Tiny-Programs.html)

### Relocation

Relocations are the entities used by the linking process, dynamic or not

 - [Study of ELF loading and relocs](http://netwinder.osuosl.org/users/p/patb/public_html/elf_relocs.html)

### Core dumps

 - [core(5) man page](http://man7.org/linux/man-pages/man5/core.5.html)
 - [core File Format](https://www.ibm.com/support/knowledgecenter/ssw_aix_61/com.ibm.aix.files/core.htm)
 - [slide](https://averageradical.github.io/Linux_Core_Dumps.pdf) Linux Core Dumps

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
 - [Custom ELF program headers—what, why and how](https://www.cs.kent.ac.uk/people/staff/srk21/blog/2017/02/14/)
 - Introduction to the ELF Format
   - [ELF Header](https://blog.k3170makan.com/2018/09/introduction-to-elf-format-elf-header.html)
   - [Understanding Program Headers](https://blog.k3170makan.com/2018/09/introduction-to-elf-format-part-ii.html)
   - [Section Header Table](https://blog.k3170makan.com/2018/09/introduction-to-elf-file-format-part.html)
   - [Section Types and Special Sections](https://blog.k3170makan.com/2018/10/introduction-to-elf-format-part-iv.html)
   - [Understanding C start up .init_array and .fini_array sections](https://blog.k3170makan.com/2018/10/introduction-to-elf-format-part-vi.html)

## MS-DOS&PE

 - [A closer look at Portable Executable MS-DOS Stub](https://marcin-chwedczuk.github.io/a-closer-look-at-portable-executable-msdos-stub)

## Mach-O

 - [Mach-O File Format: Introduction](https://h3adsh0tzz.com/2020/01/macho-file-format/)

## QRcode

 - [Wikipedia page](https://en.wikipedia.org/wiki/QR_code)

## Compact disc

 - [Compact Disc Structure](https://byuu.net/compact-discs/structure)
 - [Origins and successors of the Compact Disc](https://sci-hub.se/https://doi.org/10.1007/978-1-4020-9553-5)

## Miscellanea

 - [500 Byte Images: The Haiku Vector Icon Format](http://blog.leahhanson.us/post/recursecenter2016/haiku_icons.html)
