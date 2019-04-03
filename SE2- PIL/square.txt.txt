org 00h		;start of program
ljmp start	;long jump

delay:mov r2,#0f5h	;move 0f5h to r2

here:djnz r2,here	;decrement r2 till it becomes 0
     ret  		;return

start:mov a,#0ffh	;move 0ffh to accumulator
      mov p1,a          ;move content of accumulator to port 1
      lcall delay	;long call to delay function
      mov a,#00h	;move 00h to accumulator
      mov p1,a		;move content of accumulator to port 1
      lcall delay	;long call to delay function
      sjmp start	;short jump to start

end			;end of program
