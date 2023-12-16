.MODEL SMALL
.STACK 100H
.DATA
    MSG1    DB 0DH,0AH,'Enter a decimal number $'
    MSG2    DB 0DH,0AH,'The number is not prime.$'
    MSG3    DB 0DH,0AH,'The number is prime.$'
    NUM     DW ?
    Restore DW ?
.CODE

INDEC PROC
    ; READS A NUMBER IN RANGE -32768 TO 32767
                PUSH BX
                PUSH CX
                PUSH DX
    ; PRINT PROMPT
@BEGIN:
                MOV  AH, 2
                MOV  DL, ':'
                INT  21H            ; PRINT '?'
                
                XOR  BX, BX
                XOR  CX, CX
                MOV  AH, 1
                INT  21H            ; READ CHARACTER IN AL
                CMP  AL, '-'
                JE   @MINUS
                CMP  AL, '+'
                JE   @PLUS
                JMP  @REPEAT2
@MINUS:
                MOV  CX, 1
@PLUS:
                INT  21H            ; READ A CHARACTER IN AL
@REPEAT2:
                CMP  AL, '0'
                JNGE @NOT_DIGIT
                CMP  AL, '9'
                JNLE @NOT_DIGIT
                
    ; CONVERT CHARACTER TO NUMBER
                AND  AL, 000FH
                PUSH AX
                MOV  AX, 10
                MUL  BX
                POP  BX
                ADD  BX, AX
    ; READ NEXT CHARACTER
                MOV  AH, 1
                INT  21H
                CMP  AL, 0DH
                JNE  @REPEAT2
                MOV  AX, BX
                OR   CX, CX
                JE   @EXIT
                NEG  AX
@EXIT:
                POP  DX
                POP  CX
                POP  BX
                RET
@NOT_DIGIT:
                MOV  AH, 2
                MOV  DL, 0DH
                INT  21H
                MOV  DL, 0AH
                INT  21H
                JMP  @BEGIN
INDEC ENDP

MAIN PROC
                MOV  AX,@DATA
                MOV  DS,AX

                LEA  DX,MSG1
                MOV  AH,09H
                INT  21H

                CALL INDEC
                MOV  Restore, AX
                MOV  CX, 2
    CHECK_PRIME:
                CMP  CX, AX
                JGE  PRIME
                XOR  DX, DX
                
                DIV  CX
                MOV  AX, Restore
                CMP  DX, 0
                JE   NOT_PRIME
                INC  CX
                JMP  CHECK_PRIME

    NOT_PRIME:  
                LEA  DX, MSG2
                MOV  AH, 09H
                INT  21H
                JMP  EXIT

    PRIME:      
                LEA  DX, MSG3
                MOV  AH, 09H
                INT  21H
                JMP  EXIT

    EXIT:       
                MOV  AH, 4CH
                INT  21H
MAIN ENDP
END MAIN