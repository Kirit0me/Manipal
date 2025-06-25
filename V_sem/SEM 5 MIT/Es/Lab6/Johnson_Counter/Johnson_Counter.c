#include "LPC17xx.h"  
int i;
uint8_t j;
void GPIO_Init(void);

int main(void) {
    
    GPIO_Init();  
    
    while (1) {
			for(j=15; j<23; j++){
        LPC_GPIO0->FIOSET = 1<<j;
				for(i = 0; i < 10; i++);
			}
			for(j=15; j<23; j++){
        LPC_GPIO0->FIOCLR = 1<<j;
				for(i = 0; i < 10; i++);
			}
          
    }
}

void GPIO_Init(void) {
	LPC_PINCON->PINSEL0&=0x3FFFFFFF;
	LPC_PINCON->PINSEL1&=0xFFFF3000;
	LPC_GPIO0->FIODIR=0xFF<<15;
}
