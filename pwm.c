#include"com.h"
#include<pwm.h>
#include"reg52.h"
//#include<math.h>
//sbit pwm=P2^0;
//#define u8 unsigned char
//#define u16 unsigned int


u16 k=11,pwm_i=1,j=1,dat;//k用来形成占空比，i和j分别用作脉冲宽度计时和延时时间计时
u16 seg[]={11,17};//此处为占空比的值
u8 flag0=0;//flag1;//flag0为允许形成pwm波形的，flag1为串口接收指令开始的


/*u8 k=11,pwm_i=0;
u16 dat=0;*/
int dev,t_dev;
float fl_dev;
void pwm_ini0tial()//定时器0初始化
{
	//TMOD=0X21;//选择16位的定时器
	TH0=0XFF;//0.1ms溢出一次
	TL0=0XA3;
	ET0=1;//打开定时器0中断允许
	EA=1;//打开总中断
	
	TR0=1;//开启定时器
}
void  delay(unsigned int z)
{
		int x,y;
		for(x=z;x>0;x--)
			for(y=113;y>0;y--);

}
void Engine(int dat)
{
	/*pwm_i=0;
	dat=dat/20;*/
	pwm_ini0tial();//形成pwm需要一定周期，每20ms形成一个支持舵机运行占空比
	//通过定时器精确实现
	/*if(k==11)
	{
		P1=1;
	}
	else
	+{
		P1=0;
	}*/
		if(flag==1)//flag1在串口发送一次数据后置1
		{
			delay(160);
			k=seg[1];
			delay(160);
			pwm_i=1;
			
			j=1;
			//delay(300);
			//delay(dat);
			//误差补偿
			dev=dat/100;
			t_dev=dat/10;
			fl_dev=t_dev/10;
			switch(dev)
			{
				case(1):dat+=120;break;
				case(2):dat+=100;break;
				case(3):dat+=65;break;
				case(4):dat+=41;break;
				//case(5):dat+=15;break;
				case(6):dat-=5;break;
				case(7):dat-=8;break;
				case(8):dat-=25;break;
				case(9):dat-=90;break;
				default:dat+=0;
			}
			if((fl_dev>=7.0)&&(fl_dev<=7.2))dat-=10;
			if((fl_dev>=3.1)&&(fl_dev<=3.4))dat-=20;
			if((fl_dev>=5.7)&&(fl_dev<=6.0))dat-=10;
			if((fl_dev>=3.6)&&(fl_dev<=3.9))dat-=28;
			if((fl_dev>=2.6)&&(fl_dev<=2.9))dat-=40;
			if((fl_dev>=4.1)&&(fl_dev<=4.9))dat-=20;
			if((fl_dev>=7.6)&&(fl_dev<=8.0))dat-=25;
			if((fl_dev>=8.1)&&(fl_dev<=8.5))dat+=25;
			while(j<=(dat-135)*10);
			
			k=seg[0];
			delay(160);
			//flag1=0;
		}
	}

void timer0() interrupt 1
{
	//TR0=0;
	//static u16 pwm_i=1,j=1;//定义一个全局变量
	TH0=0XFF;
	TL0=0XA3;
	//TH0=0xff;
	//TL0=0X9C;//重装
	pwm_i++;
	j++;

	/*if(pwm_i<=k)
	{
		pwm=1;
	}
	else
	{
		pwm=0;
	}
	pwm_i++;
	if(pwm_i>=200)
	{
		if(dat<0)
		{
			k=11;
		}
		else
		{
			dat--;
		}
		pwm_i=0;
		
	}
		//TR0=1;*/
	if(pwm_i<=k+1)//加1的原因是考虑第一次定时器执行未能向pwm输出一个电平********************
	//舵机旋转30°
	{
		pwm=1;
	}
	else
	{
		pwm=0;
	}
	if(pwm_i>=201)//一个周期完成
	{
		pwm_i=1;//清0
	}

}
		
