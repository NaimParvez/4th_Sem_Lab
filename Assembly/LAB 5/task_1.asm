; take input a number and check if it is even or odd.


.MODEL SMALL
.STACK 100
.DATA
    MSG0 DB 0DH,0AH,'enter a number $'
    MSG1 DB 0DH,0AH,'its an even number $'
    MSG2 DB 0DH,0AH,'its an odd number $'
.CODE
MAIN PROC
              MOV AX,@DATA
              MOV DS,AX
              MOV AH,9
              LEA DX,MSG0
              INT 21H

              MOV AH,1
              INT 21H
              MOV BL,AL

              AND BL,01H
              CMP BL,00H
              JZ  printeven
              JNZ printodd
    printeven:LEA DX,MSG1
              MOV AH,9
              INT 21H
              JMP EXIT
    printodd: LEA DX,MSG2
              MOV AH,9
              INT 21H
              JMP EXIT

            
    EXIT:     MOV AH,4CH
              INT 21H
MAIN ENDP
END MAIN


