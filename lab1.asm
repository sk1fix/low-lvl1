%include "io64.inc"

section .bss
    strn resb 256            ; Буфер для строки
    len resd 1               ; Длина строки

section .data
    prompt db "Enter a string (max 255 characters): ", 0
    inverted_msg db "Inverted string: ", 0
    even_msg db "String of even elements: ", 0

section .text
    global main

main:
    ; Выводим приглашение к вводу
    PRINT_STRING prompt

    ; Ввод строки
    GET_STRING strn, 256

    ; Определяем длину строки
    mov ecx, 0
strlen_loop:
    cmp byte [strn + ecx], 0
    je strlen_end
    inc ecx
    jmp strlen_loop
strlen_end:
    mov [len], ecx

    ; Вывод инвертированной строки
    PRINT_STRING inverted_msg
    mov esi, [len]
    dec esi
inverted_loop:
    cmp esi, -1
    jl end_inverted
    mov al, [strn + esi]
    PRINT_CHAR al
    dec esi
    jmp inverted_loop
end_inverted:
    NEWLINE

    ; Вывод строки с четными символами
    PRINT_STRING even_msg
    mov esi, 1
even_loop:
    cmp esi, [len]
    jge end_even
    mov al, [strn + esi]
    PRINT_CHAR al
    add esi, 2
    jmp even_loop
end_even:
    NEWLINE

    ; Завершение программы
    xor rax, rax
    ret
