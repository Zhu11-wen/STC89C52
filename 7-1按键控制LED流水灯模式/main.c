#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>


unsigned char KeyNum,LEDMode;
void main( )
{
	 P2=0xFE;//亮第一个灯
	 Timer0Init();//中断开始，执行中断程序
   while(1)
  {
		KeyNum=Key();
		if(KeyNum)
		{
			if(KeyNum==1)//只用K1控制
			{
				LEDMode++;
				if(LEDMode>=2)LEDMode=0;
			}
		}
  }
}

void Timer0_Routine() interrupt 1 //中断程序
{
	static unsigned int T0Count;//局部变量静态
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=500)
	{
			T0Count=0;
			if(LEDMode==0)
				P2=_crol_(P2,1);
			if(LEDMode==1)
				P2=_cror_(P2,1);
	}

}