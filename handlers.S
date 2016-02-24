    .code64
    .global handler_empty, handler_pop, handler
    .extern pit_handler

handler:
    push %rax
    push %rcx
    push %rsi
    push %rdi
    push %r8
    push %r9
    push %r10
    push %r11

    call pit
    
    push %r11
    push %r10
    push %r9
    push %r8
    push %rdi
    push %rsi
    push %rcx
    push %rax

    iretq

handler_empty:
    iretq

handler_pop:
    add $8, %rsp
    iretq
