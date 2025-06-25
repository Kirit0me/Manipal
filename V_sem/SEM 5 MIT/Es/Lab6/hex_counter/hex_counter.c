#include "LPC17xx.h"  
long long int i;
uint8_t j = 0;
void GPIO_Init(void);


unsigned char seven_seg[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
int main(void) {
	GPIO_Init();
	while(1) {
		LPC_GPIO0->FIOPIN=seven_seg[j]<<4;
		for(i=0;i<10;i++);
		j=(j+1)%16;
	}
}

void GPIO_Init(void)
{
	LPC_PINCON->PINSEL0&=0xFF0000FF;
	LPC_GPIO0->FIODIR=0xFF<<4;
}