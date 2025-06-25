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
	MOV	R0, #0x10
	MOV	R1, #010
	ADD	R2, #33
	ADD R2, R1
	LDR	R4, =0x22222222
STOP
	B STOP
NUM EQU 10
SRC DCD 8, 0x123456, 34567891
