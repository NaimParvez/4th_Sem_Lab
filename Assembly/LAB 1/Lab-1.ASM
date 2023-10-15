.MODEL SMALL
.STACK 100H
.DATA
  A    DW 2
  B    DW 5
  SUM  DW ?
.CODE
MAIN PROC
       MOV Ax, @DATA
       MOV DS,Ax
       MOV Ax,A
       ADD Ax,5
       MOV SUM,Ax
       MOV Ax,4CH
       MOV AH,1
       INT 21H
       MOV AH, 2
       MOV DL, '?'
       INT 21H
MAIN ENDP
END MAIN
