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
	LDR R0, =SRC
	LDR R1, [R0]
	LDR R2, [R0, #4]
STOP
	B STOP
NUM EQU 10
SRC DCD 8, 0x123456, 34567891