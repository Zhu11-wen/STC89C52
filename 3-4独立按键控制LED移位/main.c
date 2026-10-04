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
unsigned char LEDNum;//定义全局变量，初始值为0000 0000
void main()
{
	P2=~0x01;//0000 0001取反1111 1110
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			LEDNum++;//LEDNum递增
			if(LEDNum>=8)
			{
				LEDNum=0;
			}
			P2=~(0x01<<LEDNum);//取反（0000 0001向左移LEDNum位）,目前LEDNum为0
		}
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			if(LEDNum==0)//按第一次，全局变量LEDNum为0
			{
				LEDNum=7;//即按第一此，LEDNum赋值为7
			}
			else
			{
			LEDNum--;
			}
			P2=~(0x01<<LEDNum);//0000 0001左移7位1000 0000，取反0111 1111，亮最后一个灯
		}
	}
}