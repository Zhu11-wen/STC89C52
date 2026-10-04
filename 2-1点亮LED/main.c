#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "LCD1602.h"

unsigned char Sec,Min,Hour;
void main()
{
	LCD_Init();
	Timer0Init();
	LCD_ShowString(1,1,"Clock");
	LCD_ShowString(2,3,":");
	LCD_ShowString(2,6,":");
	while(1)
	{
		LCD_ShowNum(2,1,Hour,2);//中断函数中不要执行过长的任务
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,7,Sec,2);
	}
}


void Timer0_Routine() interrupt 1 //中断程序
{
	static unsigned int T0Count;//局部变量静态
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000)
	{
			T0Count=0;
			Sec++;
			if(Sec>=60)
			{
				Sec=0;
				Min++;
				if(Min>=60)
				{
					Min=0;
					Hour++;
					if(Hour>=24)
					{
						Hour=0;
					}
				}
			}		
	}
}