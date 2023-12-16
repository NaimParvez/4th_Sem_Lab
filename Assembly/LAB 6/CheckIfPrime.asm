
.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 0DH,0AH,'Enter a decimal number: $'
    MSG2 DB 0DH,0AH,'NOT PRIME $'
    MSG3 DB 0DH,0AH,'PRIME $'
    NUM DW ?
    Restore DW ?
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
    DEC BX
    MOV CX,BX
    MOV AX,NUM
    print_loop:

        CMP CX,1
        JE print_yes


        XOR DX,DX
        MOV Restore,AX
        DIV CX
        ; ADD DL,'0'
        ; MOV AH,2
        ; INT 21H
        ; MOV DL,0
        MOV AX,Restore
        
        CMP DX,0
        JE print_not
        DEC CX 
        JNE print_loop

    print_not:
       LEA DX,MSG2
       MOV AH,09H
       INT 21H
       jmp EXIT

    print_yes:
       LEA DX,MSG3
       MOV AH,09H
       INT 21H
       jmp EXIT

EXIT:
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN