#include <REGX52.H>

void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms)
	{	
	
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
		xms--;
	}
}


void main()
{
	unsigned char LEDNum=0;//初始为0000 0000
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			//初始P2都是高电平1111 1111
			LEDNum++;//0000 0001
			P2=~LEDNum;//取反赋值1111 1110;
		}
	}
	
}