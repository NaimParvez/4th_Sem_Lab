.MODEL SMALL
.STACK 100h
.DATA
    MSG1 DB 0DH, 0AH, 'Enter an 8-bit Binary Number: $'
    MSG2 DB 0DH, 0AH, 'Reversed Number: $'
    MSG3 DB 0DH, 0AH, 'Number of Zeros: $'
    INPUT DB 9 DUP('$') ; Buffer for 8 digits and carriage return
    ZERO_COUNT DB 0      ; Variable to store the count of zeros
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    LEA DX, MSG1
    MOV AH, 09H
    INT 21H

    MOV CX, 8          ; To read 8 bits
    MOV BX, 0          ; Initialize BX to store the reversed number
    MOV ZERO_COUNT, 0  ; Initialize zero count

INPUT_LOOP:
    MOV AH, 1   ; Read a character
    INT 21H

    CMP AL, 0DH ; Check for carriage return
    JE REVERSE

    AND AL, 01H ; Consider only the lowest bit

    SHL BX, 1   ; Shift BX left to make space for the new bit
    OR BL, AL   ; OR AL with BX to place the new bit

    ; Increment ZERO_COUNT if the entered bit is 0
    CMP AL, 0
    JNE CONTINUE_INPUT
    INC ZERO_COUNT

CONTINUE_INPUT:
    LOOP INPUT_LOOP

REVERSE:
    LEA DX, MSG2
    MOV AH, 09H
    INT 21H

    MOV CX, 8   ; Reset loop counter for display

DISPLAY_LOOP:
    MOV DL, '0' ; Default character is '0'

    TEST BL, 1 ; Check if the least significant bit is set
    JZ DISPLAY_ZERO

    MOV DL, '1' ; If LSB is set, character is '1'

DISPLAY_ZERO:
    MOV AH, 02H     ; Display character function
    INT 21H

    SHR BX, 1       ; Shift BX to retrieve the next bit

    ; Count the number of zeros in the reversed number
    TEST BH, 1      ; Test the least significant bit of the reversed number
    JZ INCREMENT_ZERO_COUNT ; If it's zero, jump to INCREMENT_ZERO_COUNT

    JMP CONTINUE_DISPLAY

INCREMENT_ZERO_COUNT:
    INC ZERO_COUNT  ; Increment zero count

CONTINUE_DISPLAY:
    LOOP DISPLAY_LOOP

    ; Move to a new line before displaying the zero count
    MOV AH, 02H
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H

    ; Display the message
    MOV AH, 09H
    LEA DX, MSG3
    INT 21H

    ; Convert the zero count to ASCII before displaying
    MOV AL, ZERO_COUNT  ; Move the zero count to AL
    ADD AL, 30H         ; Add 30H to convert to ASCII1  
    MOV DL,AL     ; Convert count to ASCII
    MOV AH, 02H         ; Display the zero count
    INT 21H

    ; Move to a new line after displaying the zero count
    MOV AH, 02H
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H

    MOV AH, 4CH    ; Exit program
    INT 21H

MAIN ENDP
END MAIN