.MODEL SMALL
.STACK 100H
.DATA

    CR   EQU 0DH
    LF   EQU 0AH
    MSG1 DB  'enter 1st digit: $'
    MSG2 DB  0AH,'enter 2nd digit: $'
    MSG3 DB  0DH,0AH,'the substraction of $'
    MSG4 DB  ' and $'
    MSG5 DB  ' is: $'
    ;CHAR    DB  ?,'$'

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
    
    ;print 1st number
         MOV DL,BL
         MOV AH,2
         INT 21H

    ;MASSAGE 4
         LEA DX, MSG4
         MOV AH,9
         INT 21H
    
    ;print 2nd number
    
         MOV DL,BH
         MOV AH,2
         INT 21H
   
    ;MASSAGE 5
         LEA DX, MSG5
         MOV AH,9
         INT 21H
    ;substraction
         SUB BL,BH
    ;display result
         ADD BL,48       ; or ADD BL,30H
         MOV DL,BL
         MOV AH,2
         INT 21H
    

         MOV AH,4CH
         INT 21H
MAIN ENDP
    END MAIN


