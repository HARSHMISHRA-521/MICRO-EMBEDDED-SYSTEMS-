#include<LPC17xx.H>
 void delay(void);
 int main()
 {
 LPC_PINCON->PINSEL0 &=0xFF0000FF;
 LPC_GPIO0->FIODIR |=0x00000FF0;
 LPC_GPIO0->FIOMASK=0XFFFFF00F;
 while(1)
 {
  LPC_GPIO0->FIOPIN=0X00000FF0;
  delay();
  LPC_GPIO0->FIOCLR=0X00000FF0;
  delay();
  }
  }
  void delay(void)
  {
  unsigned int i=0;
  for(i=0;i<=9500;i++);
  }