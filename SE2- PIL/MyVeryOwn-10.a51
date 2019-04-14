org 00h
ljmp start


delay:
    mov r0,#0FFH
	  mov r1,#0FFH
	  
here:
    djnz r1,here
    mov r1,#0fH
	  djnz r0,here
	  
	  ret
start:
    clr p2.0
	  clr p2.2
	  lcall delay
	  setb p2.2
	  lcall delay
	  
	  
waitforintr:
        jnb p2.3,readadc
				sjmp waitforintr
				
readadc:setb p2.1
		call delay
		clr p2.1
		call delay
		
		
		mov a,p1
		cpl a
		mov p2,a
		
		
loop:sjmp loop

end