	AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
	DCD	0X10001000; Stack pointer value when stack is empty
	DCD	Reset_Handler; Reset Vectors
	ALIGN	
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV	R0, #10
	MOV	R1, #0X100000
	LDR	R2, =0X1FFFF1
	MOV R3, #-3
	MOV R4, #2_1010
	MOV R5, #3_1010
STOP
	B STOP
NUM EQU 10
SRC DCD 8, 0x123456, 34567891