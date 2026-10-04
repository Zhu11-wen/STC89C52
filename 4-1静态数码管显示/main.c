#include <REGX52.H>

unsigned char NixieTable []={
	0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
	0x7F, // 8
	0x6F, // 9
};//数组定义要加分号
void Nixie(unsigned char Location,unsigned char Number)
{
	switch(Location)//数码管顺序从左到右
	{
		case 1:
			P2_4=1;
			P2_3=1;
			P2_2=1;
			break;
		case 2:
			P2_4=1;
			P2_3=1;
			P2_2=0;
			break;
		case 3:
			P2_4=1;
			P2_3=0;
			P2_2=1;
			break;
		case 4:
			P2_4=1;
			P2_3=0;
			P2_2=0;
			break;
		case 5:
			P2_4=0;
			P2_3=1;
			P2_2=1;
			break;
		case 6:
			P2_4=0;
			P2_3=1;
			P2_2=0;
			break;
		case 7:
			P2_4=0;
			P2_3=0;
			P2_2=1;
			break;
		case 8:
			P2_4=0;
			P2_3=0;
			P2_2=0;
			break;
	}
	P0=NixieTable[Number];
}
void main()
{		
	Nixie(2,3);
	while(1)
	{
			
	}
}
