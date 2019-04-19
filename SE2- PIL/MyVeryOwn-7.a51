org 00h
ljmp start

org 100h
multiplicand_lb : db 0ffh
multiplicand_hb : db 0ffh
multiplier : db 0ffh

start : 
      lcall mult
	    lcall dist
	    here : sjmp here

; MULTIPLICATION ALGORITHM:
; 1) Initialize pointer to internal memory and copy the memory location content (input)of corresponding location to corresponding internal registers
; 2) Initialize memory pointer to internal memory to store the output
; 3) Load the lower byte of the 16 bit number into accumulator A and 8 bit number into register B
; 4) Multiply them using instruction MUL AB
; 5) Store lower byte of product in internal memory
; 6) Store the higher byte of product in one of general purpose register
; 7) Get higher byte of 16 bit number into accumulator and 8 bit number into register B
; 8) Multiply them using instruction MUL AB.
; 9) Add lower byte of the product with higher byte of previous multiplication.
; 10) Store the result into internal memory.
; 11) Add carry with the higher byte and store it into memory.

mult : 
     mov dptr,#multiplicand_lb ; loading the lower 8 bit of multiplicant to dptr so as to move them to a
	   clr a
	   movc a, @a+dptr ; moving lower bit of multiplier to a
	   mov b, a ; moving a to b. b = ff
	   
	   mov dptr,#multiplier ; immediate addresing
	   clr a ; a = 00
	   movc a,@a+dptr ; a = ff
	   
     mul ab ; after multiplication lower byte (mult) in a, higher byte (carry) in b
	   mov r0,a ; lowest byte of multiplication. It's value will not change 
	   mov r7,b ; r7 for carry
	   
	   ; now multiplying multiplier with higher byte of multiplicand
     mov dptr,#multiplicand_hb
	   clr a
	   movc a,@a+dptr 
	   mov b,a ; b = multiplicand higher byte
	   
	   mov dptr,#multiplier
	   clr a 
	   movc a,@a+dptr ; a = multiplier
	  
     mul ab ; a = lower byte, b = higher byte
	  
     add a,r7 ; add lower byte of multiplicand to r7, i.e. carry from previous multiplier * multiplicand_lb multiplication
	   jnc down ; jump if carry not generated
	   inc b ; if carry generated, increment b, which is carry from previous multiplication
	   
     down : 
        mov r1,a ; middle byte
	      mov r2,b ; carry
		 ret
dist : 
     mov a,r2 ; carry : 01
	   cpl a
	   mov p2,a
	   lcall delay
	   
	   mov a,r1 ; middle byte : ff
	   cpl a
	   mov p2,a
	   lcall delay
	   
	   mov a,r0 ; lower byte : fe
	   cpl a
	   mov p2,a
	   lcall delay
	   
	   ret
	   
delay : 
    mov r3,#10h
		mov r4,#0h
		mov r5,#0h
		
    loop :  
        djnz r5,loop		
        djnz r4,loop
        djnz r3,loop
		
		ret
		
end