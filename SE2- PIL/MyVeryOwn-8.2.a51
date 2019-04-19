; Generation of square wave of 50% duty cycle, 2KHz on P1.0  
; (Timer 1 is used in mode 2- 8 BIT AUTO RELOAD MODE )

PORTPIN EQU P1.0 
org 00h 
  ljmp start 

org 1bh ; isr address of timer 1
  clr tf1 
  clr tr1 
  cpl portpin 
  setb tr1 
  reti ; return from isr of timer1

start:
  setb ea ; enable of interrupts
  setb et1 ; enable timer1 interrupts
  mov tmod, #20H ; timer 1, mode 1
  mov th1, #1ah ; timer value = 1ah, load count in timer register
  setb tr1 ; run timer, when tf1 = 1, control gets transferred to isr of timer 1

here: sjmp here
end