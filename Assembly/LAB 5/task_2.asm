;input as binary and count the number of ones


.MODEL SMALL
.STACK 100
.DATA
    MSG1 DB 0DH,0AH,'enter the number: $'
    MSG2 DB 0DH,0AH,'number of ones: $'
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
              AND AL,0FH
              SHL BL,1
              OR  BL,AL
              INT 21H
              JMP WHILE_
    END_WHILE:
                 
                  LEA DX,MSG2
                  MOV AH,09H
                  INT 21H
    
                  MOV CX, 16
                  MOV BX, 0
                  jmp WHILE_1

    WHILE_1:      
                  
                  SHL BL,1
                  RCL BL,1
                    
                    LOOP WHILE_1
                    MOV AH, 02H
                    MOV DL, BL
                    INT 21H
                    MOV AH, 4CH
                    INT 21H
MAIN ENDP
END MAIN
                