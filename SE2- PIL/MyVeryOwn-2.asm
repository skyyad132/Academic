disp macro msg ; macro to display message
  mov dx, offset msg ; lea dx, msg
  mov ah, 09h
  int 21h
endm
.model small
.stack 100h
  .data 
    msg1 db 10,13, "Enter 5 digit bcd number$"
    msg2 db 10,13, "Equivalent hexadecimal number$"
    msg3 db 10,13, "Enter your choice$"
    msg4 db 10,13, "Equivalent bcd number is$"
    msg5 db 10,13, "Enter hex number$"
    msg6 db 10,13, "Menu$"
    msg7 db 10,13, "1.Bcd to hex$"
    msg8 db 10,13, "2.hex to bcd$"
    msg9 db 10,13, "3.exit$"
    msg10 db 10,13, "------------------------"
    msg11 db 10,13, "Invalid entry$"

    arr dw 2710h, 03e8h, 0064h, 000ah, 0001h

    cnt db 05 ; count

    count db 00h 

    res dw 0000h 

    op1 dw ? ; intermediate variable

.code

bh1 proc near ; bcd to hex, 65530 enter
disp msg1 ; enter 5 digit bcd number
lea si, arr ; si points to arr[0] i.e. 2710H

back: mov ah, 01h 
      int 21h ; to read first digit entered by user 
      ; will be stored in al register
      cmp al, 30h ; to check if it is valid or not
        jb invalid1
      cmp al, 39h 
        jg invalid1 ; if not valid 
      cmp al, 39h 
        jbe next1
      sub al, 07h

next1:  
      sub al, 30h ; ascii to original
      ; al will now contain 0y
      mov ah, 00h ; (ah:al = 0006h) i.e. ax = 06
      mov cx, [si] ; cx = 2710h 
      mul cx ; ax = ax * cx :: 0006 * 2710 = ea60h 
      add res, ax ; res = 0000, ax = ea60 so after res = ea60 
      ; above previous result is added
      inc si 
      inc si ; because data stored in array is 16 bit, so increment twice
      ; si points to second element of array 03e8
      dec cnt ; as one element processing is done, we will decrement count by one
      ; cnt = 4
      jnz back ; as all elements are not processed go back
 
      ; Like that
      ; it will read all the five digits
      ; everytime it will multiply the digit with value in cx register
      ; add the multiplication in previous resullt
      ; increment si to the next position
      ; decrement count
      ; go up for processing of the next digit
      
      ; final result in res i.e. fffa 
      disp msg2 ;equivalent hex number is 
      jmp dis 
ret1: ret
invalid1: disp msg11 
          ret ; return to main program

bh1 endp







bh2 proc near ; hex to bcd

  disp msg5; enter hex number
  mov cx, 0404h ; ch contains the counter and cl contains the amount by which rotation will take place
  mov dx, 0000h; at the end, dx will contain the value input by user

  back6:
    mov ah, 01h 
    int 21h
    ; lets take number as 1234H
    ; al now contains 1
    cmp al, 30h ; whether number is valid hex number or not
    ; valid means should contain values from
    ; 0 to 9 
    ; a to f or A to F
    jb invalid 
    cmp al, 39h 
    jg next6 ; it can be a character 
    sub al, 30h ; number between 0 to 9
    jmp below 


  next6:
    cmp al, 41h ;  check if between a to f
    jb invalid
    cmp al, 46h 
    ja next7 
    sub al, 37h 
    jmp below 
  
  next7:
    cmp al, 61h ; check if between A to F
    jb invalid 
    cmp al, 66h 
    ja invalid 
    sub al, 57h 

  below:
     rol dx, cl; rotate left dx by 4 bits
     ; dx = 0000h after rotate = 0000h
     mov ah, 00h
     ; (ah:ah) = ax = 0001 since al was already 1 as taken by user
     add dx, ax ; dx = 0001h 
     dec ch ; we are done with first digit
     jnz back6 ; go to read next number
     mov op1, dx ; op1 = 1234 
     disp msg4; equivalent bcd num is

     ; we have to display it's equivalent decimal
     mov ax, op1 ;  ax = 1234h and it will be converted to 4660h auto i think after performing division

  up:
     mov dx, 0000h ; dx = 0000h 
     mov bx, 000ah
     ; we have to divide this number by 10 to get each digit separately
     div bx 
     ; div bx instr oprn 
     ;    (DX:AX) / BX
     ;    quotient = AX
     ;    remainder = DX
     push dx ; push remainder to stack 
     inc count ; count will be used at the time of printing 
     cmp ax, 0000h 
     ;repeat till we get 0000h in ax 
     jnz up  

  back5:
    pop dx ; popped will be stored in dx register
    add dl, 30h ; convert decimal number to its ascii value
    mov ah, 02h 
    int 21h ; prints value in dl 
    dec count 
    jnz back5 
    ret ; return to main start

  invalid:
    disp msg11
    ret

bh2 endp






start:
  mov ax, @data
  mov ds, ax 

menu:
  disp msg6 
  disp msg7
  disp msg8 
  disp msg9
  disp msg3
  
  mov ah, 01h 
  int 21h ; user will enter a value  
  ; value stored in al register 

  mov bl, al ; user choice in bl
  cmp bl, 31h 
  jne next ; jump if not equal, ch not 1, compare with two
  call bh1 
  jmp menu  

next:
  cmp bl, 32h 
  jne last 
  call bh2 
  jmp menu 


dis:
  mov cx, 0404h  ; ch contains counter and cl contains rotate value
  mov bx, res ; result moved to bx register
  ; bx = fffah 

  back1:
    rol bx, cl ; cl = 4
    ; bx = 1111 1111 1111 1010 
    ; bx rotated by r
    ; after rotate bx = 1111 1111 1010 1111 
    mov dl, bl
    ; dl = af
    and dl, 0fh ; masking operation
    ; dl = 0f
    cmp dl, 09h 
    ; if it is <= add 30
    ; if it is > 9 add 37 to convert to ascii value
    jbe next3 
    add dl, 07h

    next3:
      add dl, 30h 
      mov ah, 02h ; print number on the screen whole ascii value is in dl
      int 21h 
      dec ch ; counter variable
      jnz back1 
      jmp ret1


last:
  mov ah, 4ch 
  int 21h 

end start 
end