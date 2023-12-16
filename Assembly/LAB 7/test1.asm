.MODEL SMALL
.STACK 100H

.DATA
    str1 DB "HELLO WORLD"
    str2 DB 11 DUP(?)
    MSG1 DB "REVERSED: $"
    MSG2 DB 0AH, 0DH, "No. of vowel: $"

.CODE
MAIN PROC
                MOV   AX, @DATA
                MOV   DS, AX
                MOV   ES, AX
      
                LEA   SI ,str1
                MOV   DI ,offset str2 
                MOV   CX , 10
                CLD
                point:
                    INC SI
                    JCXZ break
                    LOOP point

                break:
                MOV AH,9
                LEA DX,MSG1
                INT 21H
                XOR BL,BL
                MOV   CX , 11
                print:
                    MOV DL,[SI]
                    MOV AL,DL
                    MOV AH,2
                    INT 21H
                    CMP AL,'A'
                    JE  vowel
                    CMP AL,'E'
                    JE  vowel
                    CMP AL,'I'
                    JE  vowel
                    CMP AL,'O'
                    JE  vowel
                    CMP AL,'U'
                    JE  vowel
                    CMP AL,'a'
                    JE  vowel
                    CMP AL,'e'
                    JE  vowel
                    CMP AL,'i'
                    JE  vowel
                    CMP AL,'o'
                    JE  vowel
                    CMP AL,'u'
                    JE  vowel
                    here:
                    DEC SI
                    INC DI
                    JCXZ End
                    LOOP print
                vowel:
                    INC BL
                    JMP here
End:
                DEC BL
                MOV AH,9
                LEA DX,MSG2
                INT 21H
                ADD BL,30H
                MOV DL,BL
                MOV AH,2
                INT 21H
                
                MOV AH,4CH
                INT 21H

MAIN ENDP
END MAIN

