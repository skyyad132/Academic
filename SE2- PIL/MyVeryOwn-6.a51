org 00h
ljmp start ; long jump to start

org 41h 

arr: db 1h, 20h, 30h, 40h, 50h ; define byte array of 5 hex numbers
        
delay:  
		mov r3, #0x10 ; add delay function
		mov r4, #0x00
		mov r5, #0x00
		
    loop:   
        djnz r5, loop
        djnz r4, loop
        djnz r3, loop
        ret
        
start:  
		call addn	; call to addition
	    call display
		here: sjmp here ; Telling uC to wait 
		
addn:   
		mov r0, #00h ;sum 
	  mov r1, #00h ;carry
	  mov r2, #05h ;counter
		mov dptr, #41h ;since array start at 41h
        
		up:
			  clr a ; clear the accumulator to 0
				movc a, @a + dptr ; move the value at dptr to accumulator
				add a, r0 ; add the accumulator and r0. This translate to sum + array[i] where sum is in r0 and array[i] is in accumulator
				jnc dn ; if no carry is generated, then jump to dn to add next number. 
				; if carry generated, it will increment carry bit and go to dn anyways.
				inc r1 ; increment carry bit 
				dn:
			   	mov r0, a ; mov the previous calculated sum to r0 so accumulator becomes free to take next term from array
					inc dptr ; increment dptr to point to next term in the array
					djnz r2, up ; add all numbers until r2 gets decreased to zero. if r2 is zero next ret statement is run
				ret ; will return to calling routine, in this case the start. start then will call the display 
		
display: 
		mov a, r1 ; first show carry on the leds
		cpl a ; since led shows complemented bits, complement a so that it shows correct output
		mov p2, a ; move accumulator value to port 2 which is connected to led
		 
		call delay ; call delay to occur between showing carry and sum
		 
	    mov a, r0 ; showing the sum on leds
		cpl a ; since led shows complemented bits, complement a so that it shows correct output
		mov p2, a ; move accumulator value to port 2 which is connected to led
		 
		ret ; return to start. Then uC will remain idle by doing here: sjmp here until the power is cut off.
end