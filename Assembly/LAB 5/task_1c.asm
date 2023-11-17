; number odd or even

.MODEL SMALL
.STACK 100
.DATA
    MSG1 DB 0DH,0AH,'enter a number $'
    MSG2 DB 0DH,0AH,'its an even number $'
    MSG3 DB 0DH,0AH,'its an odd number $'
.CODE
MAIN PROC
              MOV AX,@DATA
              MOV DS,AX

              LEA DX,MSG1
              MOV AH,09H
              INT 21H


              XOR BX, BX
              MOV AH, 1
              INT 21H

    WHILE_:   
              CMP AL, 0DH
              JE  WHILE_1
              AND AL,0FH
              SHL BL,1
              OR  BL,AL
              INT 21H
              JMP WHILE_

    WHILE_1:  
              AND BL,01B
              CMP BL,00B
              JZ  printeven
              JNZ printodd
    printeven:LEA DX,MSG2
              MOV AH,9
              INT 21H
              JMP EXIT
    printodd: LEA DX,MSG3
              MOV AH,9
              INT 21H
              JMP EXIT

            
    EXIT:     MOV AH,4CH
              INT 21H
MAIN ENDP
END MAIN