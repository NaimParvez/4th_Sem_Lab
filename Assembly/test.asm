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

    MOV AX,45A3H
    MOV BH,97H
    DIV BH
    ADD AL,0BH
    SHR AL,2
    NEG AL
    MOV AH,2
    MOV DL,AL
    INT 21H
    MOV AH,4CH
    INT 21H
    MAIN ENDP
    END MAIN