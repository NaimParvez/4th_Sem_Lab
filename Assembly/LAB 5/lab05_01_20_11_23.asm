.MODEL SMALL
.STACK 100H

.DATA
MSG1  DB "ENTER A MASSAGE: $"
MSG2  DB 0AH, 0DH, "REVERSED: $"

.CODE
MAIN PROC
  MOV AX, @DATA
  MOV DS, AX
      
  MOV AH, 9
  LEA DX, MSG1
  INT 21H
  
  XOR CX, CX
INPUT:
    MOV AH, 1
    INT 21H
    CMP AL, 0DH
    JE END_INPUT 
    XOR AH, AH
    
    ; Convert lowercase to uppercase
    CMP AL, 'a'
    JL NOT_LOWERCASE
    CMP AL, 'z'
    JG NOT_LOWERCASE
    SUB AL, 20H ; Convert to uppercase
    NOT_LOWERCASE:
    
    PUSH AX
    INC CX
    JMP INPUT
    
END_INPUT: 
  
  CMP CX, 0
  JE PRINT
  
  MOV BX, 50H
  
  REVERSE:
    POP DX
    XCHG BX, SP
    PUSH DX
    XCHG BX, SP
    LOOP REVERSE
     
  PRINT:
  MOV AH, 9
  LEA DX, MSG2
  INT 21H
  
  XCHG BX, SP
  MOV AH, 2
  
  WHILE:
    XOR CX, CX  
    
    WORD: 
      CMP SP, 50H
      JGE N_WORD
      POP DX
      CMP DX, 20H
      JE N_WORD
      
      ; Convert lowercase to uppercase
      CMP DX, 'a'
      JL NOT_LOWERCASE_WORD
      CMP DX, 'z'
      JG NOT_LOWERCASE_WORD
      SUB DX, 20H ; Convert to uppercase
      NOT_LOWERCASE_WORD:
      
      XCHG BX, SP
      PUSH DX
      INC CX
      XCHG BX, SP 
      
      JMP WORD
      
    N_WORD:
    
    XCHG BX, SP
    
    PRINT_WORD:    
    POP DX
      
    INT 21H
    LOOP PRINT_WORD
    XCHG BX, SP
    
    CMP SP, 50H
    JGE BR_WHILE
    MOV DL, 20H
    INT 21H 
    
    JMP WHILE
    
  BR_WHILE:   
        
  ;EXIT
  MOV AH, 4CH
  INT 21H
  MAIN ENDP

END MAIN