#include <LPC17xx.h>
int j =0;

int main() {
	LPC_PINCON->PINSEL0&=0xFF0000FF;
	LPC_GPIO0->FIODIR=0xFF<<4;
	while(1){
		LPC_GPIO0->FIOSET = 0xFF << 4;
		for(j=0;j<5;j++);
		LPC_GPIO0->FIOCLR = 0xFF << 4;
		for(j=0;j<5;j++);
	}
}