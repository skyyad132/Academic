org 00h 	;start of program
ljmp start	;long jump

send_dac:
        mov p1, a	;move content of accumulator to port 1
        ret		;return

start:mov r0,#00h	;move 00h to r0
     
    up1:
        mov a, r0   	;move contents of r0 to accumulator
	    lcall send_dac	;long call to send_doc function
	    inc r0		;increment r0

        cjne r0, #0ffh, up1
        
    up2:
        mov a,r0		;move contents of r0 to accumulator
        lcall send_dac	;long call to send_dac function
        dec r0		;decrement r0

        cjne r0,#00h,up2
        sjmp start		;short jump
    
    here: sjmp here			;short jump

end				;end of program