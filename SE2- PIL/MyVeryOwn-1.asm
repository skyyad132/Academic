.model small
.data
  array db 08h, 08h, 06h, 09h, 09h
  result db 00h
  cnt db 05h

.stack 100h

.code
  main proc
    mov ax, @data
    mov ds, ax

    lea si, array

    add_up
      mov al, [si]
      add result, al
      inc si
      dec cnt
      jnz add_up

    mov BL, result

    ; masking the lsb
    AND result, 0F0h
    SHR result, 04h
    cmp result, 09h
    JA add1
    ADD result, 30h
    jmp add2
    add1:
      add result, 37h
    add2:
       mov ah, 02h
       mov dl, result
       int 21h

    ; masking the msb
    AND BL, 0fh
    CMP BL, 09H
    JA add3
    add BL, 30h
    jmp add4
    add3 add BL, 37h
    add4 mov ah, 02h
          mov dl, BL
          int 21h

    mov ah, 4ch
    int 21h
  main endp
end
