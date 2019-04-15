org 00h 
ljmp start 
; p2.0 = chip select active low
; p2.1 = read
; p2.2 = write 
; p2.3 = intr active low - gives 0 when adc is done
; p1.0 - p1.7 = db0 - db7 - output from adc 
delay:
  mov r0, #0ffh 
  mov r1, #0ffh 
  here: djnz r1, here
        mov r1, #0fh 
        djnz r0, here 
        ret
  
  start:
    ; chip select on port p1.0
    ; making p1.0 connected to adc cs to select adc
    clr p2.0 

    ; now asking for write on p2.2
    ; wr starts operation after getting low to high
    clr p2.2 
    lcall delay 
    setb p2.2 
    lcall delay 

    waitforintr:
      jnb p2.3, readdac ; wait till adc is done. jump if zero
      sjmp waitforintr 

    readdac:
      ; taking data from adc by starting read
      ; rd on p2.1 starts after a high to low 
      setb p2.1 
      call delay 
      clr p2.1 
      call delay 


    ; display output of adc on led 
    ; output of adc is connected to p1
    ; leds are connected to p2
      mov a, p1
      cpl a 
      mov p2, a

      loop:sjmp loop 
end
