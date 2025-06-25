#include "LPC17xx.h"  
long long int i;
uint8_t j;
int y;
unsigned int dig_count = 0;

unsigned int dig_value[5] = {0, 0, 0, 0, 0};

void GPIO_Init(void);
void delay_ms(int ms);
void display(void);

unsigned int select_segment[5] = {0, 0<<15, 1<<15, 2<<15, 3<<15};
unsigned char seven_seg[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

int main(void) {
    GPIO_Init();  
     while (1) {
			 dig_value[1]++;
			 if (dig_value[1] > 15) {
					dig_value[2]++; 
					dig_value[1] = 0;			 
					if (dig_value[2] > 15) {
							dig_value[3]++; 
							dig_value[2] = 0;
							if (dig_value[3] > 15) {
									dig_value[4]++; 
									dig_value[3] = 0;
									if (dig_value[4] > 15) {
										 dig_value[4] = 0;
									}
								}
							}
			 }

			while(dig_count < 4) {
					dig_count++;
					display();
			}
			dig_count = 0;
			delay_ms(10000);
    }
}



void GPIO_Init(void) {
	LPC_PINCON->PINSEL0&=0x3F0000FF;
	LPC_PINCON->PINSEL1&=0xFFFFFFC0;
	LPC_GPIO0->FIODIR=0xFF<<4 | 0xF<<15;
}

void delay_ms(int ms) {
	for(i=0;i<ms;i++);
}

void display(void) {
	
    LPC_GPIO0->FIOCLR = 0xFF << 4; 
    LPC_GPIO0->FIOCLR = 0xF << 15;

    LPC_GPIO0->FIOSET = select_segment[dig_count] | (seven_seg[dig_value[dig_count]] << 4);
    delay_ms(100000); 

}
