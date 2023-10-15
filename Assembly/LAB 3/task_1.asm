.MODEL SMALL
.STACK 100H
.DATA

    CR   EQU 0DH
    LF   EQU 0AH
    MSG1 DB  'enter 1st digit: $'
    MSG2 DB  0AH,'enter 2nd digit: $'
    MSG3 DB  0DH,0AH,'enter 3rd digit $'
     

.CODE
MAIN PROC
                MOV AX,@DATA
                MOV DS,AX
    ; show massage 1
                LEA DX,MSG1
                MOV AH,9
                INT 21H
    ; input 1st digit
                MOV AH,1
                INT 21H
                MOV BL,AL
    ;show massage 2
                LEA DX,MSG2
                MOV AH,9
                INT 21H
    ; input 2nd digit
                MOV AH,1
                INT 21H
                MOV BH,AL

    ;massage 3
                LEA DX, MSG3
                MOV AH,9
                INT 21H
    
    ; input 3rd digit
                MOV AH,1
                INT 21H
                MOV AH,AL
    ;MOV AH,AL

                CMP BL,BH
                JG  compare_1_3
                jmp compare_2_3

    compare_1_3:
                cmp BL,AL
                JG  printbl
                jmp ptintal
    compare_2_3:
                CMP BH,AL
                JG  printbh
                jmp printal

    printbl:    
                ADD BL,48          
                MOV DL,BL
                MOV AH,2
                INT 21H
                jmp final
    printal:    
                ADD AL,48          
                MOV DL,AL
                MOV AH,2
                INT 21H
                jmp final

    printbh:    
                ADD BH,48          
                MOV DL,BH
                MOV AH,2
                INT 21H
                jmp final


    final:      
                MOV AH,4CH
                INT 21H

MAIN ENDP
    END MAIN

 