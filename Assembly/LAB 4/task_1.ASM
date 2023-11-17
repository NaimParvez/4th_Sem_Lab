
; take input 2 char and print in ascending order
.MODEL SMALL
.CODE
MAIN PROC
            MOV  AH,2
            MOV  DL,'?'
            INT  21H 

            MOV  AH,1   ;1st char
            INT  21H        
            MOV  BL,AL


            MOV AH,1    ;2nd char
            INT  21H 
            MOV CL,AL       
            ;INT 21H

            CMP  BL,CL
            JG   exchange    
            JMP  print

    exchange:  
            XCHG BL,CL      ;exchange
            
    print:
            MOV  AH,2
            MOV  DL, 0AH   
            INT  21H

            ADD  BL,20H
            MOV  DL,BL
            INT  21H

            ADD  CL,20H
            MOV  DL,CL
            INT  21H

            MOV  AH,4CH
            INT  21H
MAIN ENDP
END MAIN