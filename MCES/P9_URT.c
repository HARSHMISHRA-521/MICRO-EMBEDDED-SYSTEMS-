#include<LPC17xx.h>
void delay(unsigned int r1);
void UART0_Init(void);
unsigned int i;
unsigned char*ptr,arr[]=" Hello world\r";
#define THR_EMPTY 0x20
int main(void)
{
UART0_Init();
while(1)
{
ptr=arr;
while(*ptr!='\0')
{
while((LPC_UART0->LSR & THR_EMPTY)!=THR_EMPTY);
LPC_UART0->THR=*ptr++;
}
for(i=0;i<=60000;i++);
}}
void UART0_Init(void)
{
LPC_SC->PCONP |=0x00000008;
LPC_PINCON->PINSEL0=0x00000050;
LPC_UART0->LCR=0x00000083;
LPC_UART0->DLM=0x00;
LPC_UART0->DLL=0x1A;
LPC_UART0->LCR=0x00000003;
LPC_UART0->FCR=0x07;
}
