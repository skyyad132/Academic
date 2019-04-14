PORTPIN EQU P1.0
ORG OOH
LJMP START
ORG 1BH;                 ;  ISR ADDR OF TIMER 1
CLR TF1
CLR TR1
CPL PORTPIN
      SETB TR1      ;run timer
      RETI     ;ret from ISR of timer1

START: 
    SETB EA         ;enable all interrupts
    SETB ET1        ;enable timer0 int
    MOV TMOD,#20H   ;Timer 1, mode 1(16-bit)
    MOV TH1,#1AH    ;Timer value = 1AH,load cnt in timer reg
    SETB TR1        ;Run timer, when TF1 = 1, control gets transferred to ISR of Timer1
    HERE: SJMP HERE
END      
