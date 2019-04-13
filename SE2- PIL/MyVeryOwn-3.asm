disp macro msg  
  mov ah, 09h
  lea dx, msg
  int 21h
endm

.model small
.stack 100h

.data
  str1 db 25 dup("$") 
  str2 db 25 dup("$")

  msg1 db 10,13, "Menu$"
  msg2 db 10,13, "1.Enter string$"
  msg3 db 10,13, "2.Length$"
  msg4 db 10,13, "3.Reverse$"
  msg5 db 10,13, "4.Palindrome$"
  msg6 db 10,13, "5.Exit$"
  msg7 db 10,13, "Enter choice : $"
  msg8 db 10,13, "Wrong Choice $"
  msg9 db 10,13, "Enter the string : $"
  msg10 db 10,13, "Reverse string is : $"
  msg11 db 10,13, "length is : $"
  msg12 db 10,13, "String is palindrome$"
  msg13 db 10,13, "String is NOT a palindrome$"

.code

accept proc near 
  disp msg9 ; Enter the string
  lea dx, str1 ; str1 contains the location of address where the string 1 is stored
  mov ah, 0AH ; 0AH to accept the string and store in address pointed by dx register
  int 21h
  ; string entered by user will be stored where dx is the pointed
  ret ; returning to the main procedure
accept endp

leng proc near
  disp msg11 ; length is : 
  ; str1 contains the address of the string 
  ; and by default next address to str1 contains lenght of the string
  ; if the string is WELCOME then following will be the scenario
  ; str1 - 7 - W - E - L - C - O - M - E 
  ; and remaining of 25 places will have $ sign
  mov dl, str1+1 ; str1+1 contains the length of the string 
  add dl, 30h ; making it ascii to print
  mov ah, 02h ; ascii value stored in dl register is printed on the screen 
  int 21h 
  ret ; return from where it is called
leng endp

reverse proc near 
  disp msg10 ; Reverse string is : 
  xor ch, ch ; it will make register ch zero. xor with itself is 0
  mov cl, str1+1 ; str1+1 contains the lenght of the string. cl will contain 7 since string is WELCOME 
  sub cl, 01h ; cl = 06
  lea si, str1+2 ; si will point at str1+2. i.e. first character of first string i.e. pointing to W
  lea di, str2+2 ; di will point to first character of string 2
  ; NOTE - use lea for si and di
  ; since ch = 0 (by xor) and cl = 6 (by moving str1+1 and decrementing by one)
  ; we can say cx = 0006H

  rep movsb ; move string byte 
  ; character pointed by si copied to the address pointed by di   
  ; movsb first copies W to di 
  ; but to copy all characters we need to repeat instruction
  ; rep will be repeated until CX becomes 0000. 
  ; On each iteration si incremented by 1, di incremented by 1, cx decremented by 1
  ; we want si pointing to last character of si, not the next of it- 
  ; that is why we initially decremented cl by 1 after feeding it lenght of str1
  
  mov cl, str1+1 ; original length will be transferred to cl. i.e. cl = 7 now
  lea di, str2+2 ; load effective address. now di is updated and it is pointing to first character of str2 
  
  loop1: ; real reversing starts here, previous was only to make si point last location
    mov dx, [si] ; si points to last character, si -> E, so now dx contain letter 'E'
    mov [di], dx ; character in dx is copied to location di is pointing at, i.e. at first at E will be first character of str2
    mov ah, 02h ; contents of dx is printed - it will print E
    int 21h 
    
    dec si ; decrement si 
    inc di ; increment di
    dec cl ; as we have copied a character, decrement cl 
    
    cmp cl, 00h 
    jne loop1 ; jump if not equal to
    ret 
reverse endp


pall proc near 
  lea dx, str1+2 ; dx will point to first character of str1 
  ; in palindrome we check original string and reversed string
  ; if original string and reversed string is equal, then the string is palindrome, else not
  call reverse 
  ; str1 is original string and str2 is  
  lea si, str1+2 ; si will point to first character from str1 
  lea di, str2+2 ; di will point to first character from str2 
  ; we just have to compare all the characters between two strings. If they are equal, that means they are palindrome
  mov cl, str1+1 ; length. Needed to know how many characters to compare

  loop2: 
    mov al, byte ptr[si] ; whatever character pointed by si is moved to al register. in first, al = W (from WELCOME in str1)
    mov bl, byte ptr[di] ; whatever character pointed by di is moved to dl register. in first, bl = E (from EMOCLEW in str2)
    dec cl ; as we have copied one character, decrement cl by 1
    cmp cl, 00h ; compare with 00h
      je loopx ; jump if equal
    cmp al, bl ; compare al, bl 
      je loop3 ; jump if equal. in our case, W != E, so won't jump to loop3, so won't go to directly to loop3, it will execute next line
    loopx:
      cmp cl, 00h 
        je loop4
      disp msg13 ; string is not a palindrome
        jmp loop5 

    loop4: disp msg12
    
    loop5: ret 

    loop3: 
      inc si ; si will point to next character from string 1
      inc di ; di will point to next character from string 2
      jmp loop2    
pall endp

start:          ; program starts executing at here
  mov ax, @data 
  mov ds, ax 

  menu:         ; prints menu
    disp msg1
    disp msg2
    disp msg3
    disp msg4
    disp msg5
    disp msg6
    disp msg7

  mov ah, 01h 
  int 21h ; entered choice is in al register
  mov bl, al ; move value in al to bl register

  cmp bl, 31h; compare bl with ascii value of 1 
    je acc ; jump if equal to acc label
  cmp bl, 32h 
    je len 
  cmp bl, 33h
    je rev
  cmp bl, 34h 
    je pallindrome
  cmp bl, 35h
    je ter 

  disp msg8 

  acc: 
    call accept ; control will be transferred to accept procedure
    jmp menu 

  len: 
    call leng
    jmp menu 

  rev:
    call reverse 
    jmp menu 
  
  pallindrome:
    call pall 
    jmp menu 

  ter: 
    mov ah, 4ch 
    int 21h 

end start 
end