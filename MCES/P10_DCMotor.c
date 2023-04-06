#include<LPC17xx.h>			//DC MOTOR
void ClockWise(void);
void AClockWise(void);
int i=0,m=0;
int main(void)
{
	 LPC_PINCON->PINSEL1=0x00000000;
	 LPC_PINCON->PINSEL3=0x00000000;
	 LPC_GPIO0->FIODIR|=0x04000000;
	 LPC_GPIO1->FIODIR|=0x01000000;

	 for(m=0;m<5;m++)
	 {
	 	ClockWise();
		for(i=0;i<300000;i++);
		AClockWise();
		for(i=0;i<300000;i++);
	 }

}

void ClockWise(void)
{
	 LPC_GPIO1->FIOCLR=0x01000000;
	 for(i=0;i<100000;i++);
	 LPC_GPIO0->FIOSET=0x04000000;
	 LPC_GPIO1->FIOSET=0x01000000;
}

void AClockWise(void)
{
	 LPC_GPIO1->FIOCLR=0x01000000;
	 for(i=0;i<100000;i++);
	 LPC_GPIO0->FIOCLR=0x04000000;
	 LPC_GPIO1->FIOSET=0x01000000;
}