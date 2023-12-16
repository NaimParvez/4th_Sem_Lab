.MODEL SMALL
.STACK 100H

.DATA
    str1 DB "HELLO WORLD$"
    str2 DB 11 DUP(?)
    MSG1 DB 0AH, 0DH, "REVERSED: $"
    MSG2 DB 0AH, 0DH, "No. of vowel: $"

.CODE
MAIN PROC
                MOV   AX, @DATA
                MOV   DS, AX
                MOV   ES, AX
      
                LEA   SI ,str1
                LEA   DI ,str2
                STD
                MOV   CX ,11
    reverse:    
                MOV   AL , [SI]
                MOV   [DI], AL
                INC   DI
                INC   SI
                LOOP  reverse
        
                MOV   CX ,11
                LEA   SI ,str2
                LEA   DI ,str1
                CLD
    print:      
    ; MOV   AL , [SI]
    ; MOV   [DI], AL
    ; INC   DI
    ; INC   SI
    ; LOOP  print
    ; MOV   AH ,9
    ; LEA   DX ,MSG1
    ; INT   21H
    ; LEA   DX ,str1
    ; INT   21H
    ; LEA   DX ,MSG2
    ; INT   21H
    ; LEA   DX ,str1
    ; MOV   CX ,11
    ; MOV   AH ,0
    ; MOV   AL ,0
    ; CLD
                MOV   DL, [SI]
                MOV   AH,2
                INT   21H
                INC   SI
                LOOP  print

    vowel:      
                LODSB
                CMP   AL ,'A'
                JE    vowel_count
                CMP   AL ,'E'
                JE    vowel_count
                CMP   AL ,'I'
                JE    vowel_count
                CMP   AL ,'O'
                JE    vowel_count
                CMP   AL ,'U'
                JE    vowel_count
                JMP   vowel
    not_vowel:  
                LOOP  vowel
                JMP   exit
    vowel_count:
                INC   AL
                LOOP  vowel
                JMP   exit

    exit:       
                MOV   DL,AL
    ;ADD DL,30H
                MOV   AH,2
                INT   21H
                MOV   AH, 4CH
                INT   21H
MAIN ENDP
END MAIN