    /* call write(1, 'miao', 3) */
    jmp miao
start:
    pop rsi
    push (SYS_write) /* 1 */
    pop rax
    push 1
    pop rdi
    push 50
    pop rdx
    syscall

    ret
miao:    call start
.ascii "miao\0"
