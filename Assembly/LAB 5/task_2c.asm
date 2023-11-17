 
 ;input a number and count the number of ones in its binary representation

.MODEL SMALL
.STACK 100
.DATA
    MSG1 DB 0DH,0AH,'Enter the number: $'
    MSG2 DB 0DH,0AH,'Number of ones: $'
    NUM DW ?
    ONE_COUNT DB 0
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
    JE  END_WHILE
    SUB AL, '0'; convert char to number
    SHL BX, 1  
    OR  BX, AX 
    MOV AH, 1
    INT 21H
    JMP WHILE_
END_WHILE:
    MOV NUM, BX

    LEA DX,MSG2
    MOV AH,09H
    INT 21H

    MOV CX, 16
    JMP WHILE_1

WHILE_1:      
    MOV AX, NUM
    AND AX, 1
    CMP AX, 1 
    JNE NEXT_DIGIT
    INC ONE_COUNT
NEXT_DIGIT:
    SHR NUM, 1
    LOOP WHILE_1

    MOV AH, 02H
    dec ONE_COUNT
    MOV DL, ONE_COUNT
    ADD DL, 30H
    INT 21H

    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN