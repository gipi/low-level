# Formats

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

## JPEG

## PNG

## PDF

 - Let's write a PDF file [speakerdeck](https://speakerdeck.com/ange/lets-write-a-pdf-file)

## ELF

Three main types of ``ELF`` files

 - Relocatable file
 - Executable
 - Shared objects/library

### Relocation

### Links

 - Anatomy of a program in memory [POST](http://duartes.org/gustavo/blog/post/anatomy-of-a-program-in-memory/)
 - Cheating ELF [PDF](https://grugq.github.io/docs/subversiveld.pdf)
 - [Dissection of an ELF file](https://github.com/mewrev/dissection)
 - [Reversing an ELF from the ground up](http://anee.me/reversing-an-elf/)

## Miscellanea

 - [500 Byte Images: The Haiku Vector Icon Format](http://blog.leahhanson.us/post/recursecenter2016/haiku_icons.html)
