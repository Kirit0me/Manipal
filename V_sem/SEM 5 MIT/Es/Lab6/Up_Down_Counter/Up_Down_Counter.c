#include "LPC17xx.h"  
long long int i;
uint8_t j;
int y;
void GPIO_Init(void);

void up(){
	LPC_GPIO0->FIOPIN = j<<15;
	j++;
	for(i = 0; i < 10; i++);
}

void down() {
	LPC_GPIO0->FIOPIN = j<<15;
	j--;
	for(i = 0; i < 10; i++);
}


int main(void) {
    
    GPIO_Init();  
    
    while (1) {
				y = LPC_GPIO0->FIOPIN&=1<<10;
			if(y) up();
			else down();
          
    }
}

void GPIO_Init(void) {
	LPC_PINCON->PINSEL0&=0x3FCFFFFF;
	LPC_PINCON->PINSEL1&=0xFFFF3000;
	LPC_GPIO0->FIODIR=0xFF<<15 | 0x0<<10;
}
