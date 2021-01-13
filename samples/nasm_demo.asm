        global    hello_world
        global    add
        global    print_it
        global    nth_char
        section   .text
add:
        mov rax, rdi ;; move the first argument into rax
        add rax, rsi ;; add the second argument to that value
                     ;; and store in rax
        ret          ;; return value in rax

hello_world:
        mov rax, 1              ;; sys_write - see http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
        mov rdi, 1              ;; stdout file handle is 1, by convention
        mov rsi, message        ;; the message we want to print
        mov rdx, 13             ;; print 13 characters of data
        syscall
        ret
message:
        db        "NASM Rocks!", 0xA, 0xD

print_it:
    mov rdx, rsi
    mov rsi, rdi
    mov rax, 1
    mov rdi, 1
    syscall
    ret

nth_char:
    mov rax, rdi
    add rax, rsi
    mov rax, [rax]
    ret
