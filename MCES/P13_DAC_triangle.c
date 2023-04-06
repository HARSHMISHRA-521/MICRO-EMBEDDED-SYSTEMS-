 #include<LPC17xx.H>
 int main()
 {
 unsigned long int temp=0x00000000;
 unsigned int i=0;
 LPC_PINCON->PINSEL0 &=0xFF0000FF;
 LPC_GPIO0->FIODIR |=0x00000FF0;
 LPC_GPIO0->FIOMASK=0XFFFFF00F;
 while(1)
 {
 for(i=0;i!=0xFF;i++)
 {
 temp=i;
 temp=temp<<4;
 LPC_GPIO0->FIOPIN=temp;
 }
 for(i=0xFF;i!=0;i--)
 {
 temp=i;
 temp=temp<<4;
 LPC_GPIO0->FIOPIN=temp;
 }
 }
 }