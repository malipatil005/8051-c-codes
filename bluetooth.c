#include<reg51.h>
#include"uart.h"
sbit led=P1^0;
void delay()
{
	int i,j;
	for(i=0;i<200;i++)
	{
		for(j=0;j<200;j++);
	}
}

void main()
{
	unsigned char value;
	led=0;
	ser_init();
	while(1)
	{
		value=rx();
		if(value=='1')
		{
			led=1;delay();trx_string("\n LED ON ");}
		else if(value=='0'){
			led=0;delay();trx_string("\n LED OFF ");}
		else
			trx_string("\n please enter correct choice ");
	}
}