.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 0DH,0AH,'Enter a decimal number: $'
    MSG2 DB 0DH,0AH,'The number is not prime.$'
    MSG3 DB 0DH,0AH,'The number is prime.$'
    NUM DW ?
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
    SUB AL, '0'
    SHL BX, 1
    ADD BX, AX
    MOV AH, 1
    INT 21H
    JMP WHILE_
END_WHILE:
    MOV NUM, BX

    MOV AX, NUM
    MOV CX, 2
CHECK_PRIME:
    CMP CX, AX
    JGE PRIME
    XOR DX, DX
    DIV CX
    CMP DX, 0
    JE NOT_PRIME
    INC CX
    JMP CHECK_PRIME

NOT_PRIME:
    LEA DX, MSG2
    MOV AH, 09H
    INT 21H
    JMP EXIT

PRIME:
    LEA DX, MSG3
    MOV AH, 09H
    INT 21H

EXIT:
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN