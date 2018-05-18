#include"com.h"
#include"pwm.h"
uchar flag=0,num=0;
uchar rd[10];
uint g_dat;
int i;
//串口初始化
void ComInit();
void Com()
{
	//串口初始化
	ComInit();
	while(1)
	{
		
		P1=0X00;
		if(flag==1)
		{
			ES=0;
			//flag=0;
			//发送数据
			for(i=0;i<3;i++)
			{
				SBUF=rd[i];//发送数据
				while(!TI);
				TI=0;//重要！
				//num=0;
			}
			//数据组装
			g_dat=rd[0]*100+rd[1]*10+rd[2]*1;
			//g_dat=rd[0]*1000+rd[1]*100+rd[2]*10+rd[3]*1;
			//g_time=g_dat*1.35;
			//数据传输给pwm程序
			//k=g_dat;
			//运行舵机
			Engine(g_dat);
			//开启接收
			flag=0;
			ES=1;
		}
	}
}
void timer4() interrupt 4
{
	//接收数据
	if(RI)
	{
		RI=0;
		rd[num++]=SBUF;
		//当数据接收到三位时改变方向
			if(num==3)
		{
			num=0;
			flag=1;
		}
	}
}
//串口初始化
void ComInit()
{
	//TMOD=0X20;//启用T1定时器工作方式2，8位自动重装
	TMOD=0X21;//启用定时器0 1
	/*TH1=0Xe6;
	TL1=0Xe6;//2400Bd
	*/
	//Timer0Init();
	
	TH1=0Xfa;
	TL1=0Xfa;//波特率=9600Bd
	
	/*TH1=0XF3;
	TL1=TH1;*///4800Bd
	PCON=0X80;//SMOD=1
	TR1=1;
	
	SM0=0;
	SM1=1;//选择串口通信方式1
	REN=1;//允许串口接收数据
	ES=1;//打开串口中断
	EA=1;//打开总中断
}