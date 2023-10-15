section
          .text
global
          _start
_start:
    mov edx, len
    mov есх, msg
    mov ebx, 1
               4
    mov
          eax,
     int
          0x80
    mov
          eax, 1
     int
          0x80
 section
          .data
      db "Hello World!"
msg
 len equ $ - msg
