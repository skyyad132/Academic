org 00h 	;start of program
ljmp start	;long jump

delay:mov r2,#0ffh	;move 0ffh to r2

here:djnz r2,here	;decrement r2 till it becomes to 0 and jump to lable loop
     ret		;return

start:mov a,#00h		;move 00h to accumulator

	up1:mov p1,a	;mov contents of accumulator to port 1
	    inc a	;increment accumulator by 1

	cjne a,#0ffh,up1	
	lcall delay		;long call to delay function

	up2:mov p1,a 		;move contents of accumulator to port 1
	    dec a		;decrement accumulator by 1

	cjne a,#00h,up2
	jmp start		;jump to start

end   				;end of program