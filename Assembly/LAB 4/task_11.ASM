
.MODEL SMALL
.CODE
MAIN PROC
             MOV AH,2
             MOV DL,'?'
             INT 21H

             MOV AH,1
             INT 21H
             MOV BL,AL
             
             INT 21H
        
             CMP BL,AL
             JG  exchange
             JMP print

    exchange:
            MOV AH,2
            MOV DL, 0AH
            INT 21H

            ADD AL, 32
            MOV AH,2
            MOV DL,AL
            INT 21H

            ADD BL, 32
            MOV AH,2
            MOV DL,BL
            INT 21H

            MOV AH,4CH
            INT 21H
    print:   
             MOV AH,2
             MOV DL, 0AH
             INT 21H

             ADD BL, 20H
             MOV AH,2      ; convert to lowercase
             MOV DL,BL
             INT 21H

             ADD AL, 20H  
             MOV AH,2      ; convert to lowercase
             MOV DL,AL
             INT 21H

             MOV AH,4CH
             INT 21H
MAIN ENDP
END MAIN