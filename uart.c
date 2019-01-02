#include<reg51.h>
#include"uart.h"
void ser_init()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
}
void tx(unsigned char value)
{
	SBUF=value;
	while(TI==0);
	TI=0;
}
char rx()
{
	char value;
	while(RI==0);
	RI=0;
	value=SBUF;
	return value;
}
void trx_string(unsigned char *str)
{
	while(*str)
		tx(*str++);
}
