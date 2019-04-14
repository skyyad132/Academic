.model small
print macro m 
  lea dx, m 
  mov ah, 09h 
  int 21h 
endm

.data
  file1 db 20 dup(0) ; it is 0 not '0'. I spent 2 hours looking for this stupid bug
  file2 db 20 dup(0)
  fhandle1 dw ?
  fhandle2 dw ?
  buff db 100,0,100 dup('0') 
  count dw ?

  namesread db 10,13, "File names read$"
  fileopen db 10,13, "File opened successfully$"
  fileclose db 10,13, "File closed$"
  filecopy db 10,13, "File copied successfully$"
  filecreated db 10,13, "File created successfully$"
  FileOpenError db 10,13, "Could not open file$"
  FileCloseError db 10,13, "Could not close file$"
  FileReadError db 10,13, "Could not read file$"
  FileCreateError db 10,13, "Could not create file$"

.code 
  start: 
    mov ax, @data
    mov ds, ax 

    mov si, 82h
    lea di, file1 

    read1:
      mov al, es:[si] 
      cmp al, " "
        je next 
      mov [di], al 
      inc si
      inc di 
      jmp read1 

      next: 
        inc si 
        lea di, file2 

    read2:
      mov al, es:[si]
      cmp al, 0dh 
        je read_success 
      mov [di], al 
      inc si
      inc di 
      jmp read2 

    read_success:
      print namesread 

  ; now opening file 1 in read mode 
  ; 3dh, al = 00 (read mode), dx = filename .. after ax = filehandle
  open1:
    mov ah, 3dh  
    mov al, 00 
    lea dx, file1
    int 21h 
      jnc open_success1 
    print FileOpenError 
    jmp exit
    open_success1:
      mov fhandle1, ax 
      print fileopen 

  ; now creating file
  ; ah = 3ch, dx = filename, cx = 0 
  mov ah, 3ch 
  xor cx, cx 
  lea dx, file2 
  int 21h 
    jnc create_success 
  print FileCreateError 
  jmp exit 

  create_success:
    print filecreated 

; now open file 2 in write mode 
; ah = 3dh, dx = filename, al = 01 (write mode) .. after filehandle in ax
mov ah, 3dh 
lea dx, file2 
mov al, 01h 
int 21h 
  jnc open_success2
print FileOpenError
jmp exit

open_success2:
  mov fhandle2, ax 
  print fileopen

; now reading from file 1 and then writing to file 2 
; for reading
; ah = 3fh, bx = filehandle, cx = no of bytes to read, dx = buffer to which read the contents of file 2
; .. after ax contains byte read. if ax = 0, file read completely
; carry generated on error
fread_write:
  mov ah, 3fh 
  mov bx, fhandle1 
  mov cx, 100 
  lea dx, buff 
  int 21h 
   jc read_error
  cmp ax, 0000h
    je close 

; now writing read characters to file 2
; for writing 
; ah = 40h, bx = filehandle, cx = no of bytes to write from buffer, dx = buffer address
; .. after ax containt byte written. 
  mov count, ax

  mov ah, 40h 
  mov bx, fhandle2 
  mov cx, count
  lea dx, buff 
  int 21h 
  jmp fread_write

read_error:
  print FileReadError 
  jmp exit

; now closing the files
; ah = 3eh, bx = filehandle
; carry generated on error
close:
  mov ah, 3eh 
  mov bx, fhandle1 
  int 21h 
    jc close_error

  mov ah, 3eh 
  mov bx, fhandle2 
  int 21h
    jc close_error

  print fileclose 
  jmp exit 
close_error:
  print FileCloseError
  jmp exit 

exit:
  mov ah, 4ch 
  int 21h 

end start 
end