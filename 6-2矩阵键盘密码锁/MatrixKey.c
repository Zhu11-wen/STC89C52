#include <REGX52.H>
#include "Delay.h"

/**
	* @brief  矩阵键盘读取按键键码
	* @param  五
	* @retval KeyNumber 按下按键的键码值
				如果按键按下不放，程序会停留在此函数，松手的一瞬间返回按键键码，没有按键按下时，返回0
	*/
unsigned char MatrixKey()
{
	unsigned char KeyNumber=0;
	
	P1=0xff;//默认所有矩阵按键为高电平
	P1_3=0;//第一列为0
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=1;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=5;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=9;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=13;}
	
	P1=0xff;//默认所有矩阵按键为高电平
	P1_2=0;//第二列为0
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=2;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=6;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=10;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=14;}
	
	P1=0xff;//默认所有矩阵按键为高电平
	P1_1=0;//第三列为0
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=3;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=7;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=11;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=15;}
	
	P1=0xff;//默认所有矩阵按键为高电平
	P1_0=0;//第四列为0
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=4;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=8;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=12;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=16;}
	
	return KeyNumber;
}