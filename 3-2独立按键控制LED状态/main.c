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
	while(1)
	{
	if(P3_1==0)//按键按下
	{
		Delay(20);//按下消除抖动
		while(P3_1==0);//二次检测，确实按下
		Delay(20);//松手消除抖动
			P2_0=~P2_0;//P2_0本身为高电平即为1，取反为0
	}
	}
}