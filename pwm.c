#include"com.h"
#include<pwm.h>
#include"reg52.h"
//#include<math.h>
//sbit pwm=P2^0;
//#define u8 unsigned char
//#define u16 unsigned int


u16 k=11,pwm_i=1,j=1,dat;//k�����γ�ռ�ձȣ�i��j�ֱ����������ȼ�ʱ����ʱʱ���ʱ
u16 seg[]={11,17};//�˴�Ϊռ�ձȵ�ֵ
u8 flag0=0;//flag1;//flag0Ϊ�����γ�pwm���εģ�flag1Ϊ���ڽ���ָ�ʼ��


/*u8 k=11,pwm_i=0;
u16 dat=0;*/
int dev,t_dev;
float fl_dev;
void pwm_ini0tial()//��ʱ��0��ʼ��
{
	//TMOD=0X21;//ѡ��16λ�Ķ�ʱ��
	TH0=0XFF;//0.1ms���һ��
	TL0=0XA3;
	ET0=1;//�򿪶�ʱ��0�ж�����
	EA=1;//�����ж�
	
	TR0=1;//������ʱ��
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
	pwm_ini0tial();//�γ�pwm��Ҫһ�����ڣ�ÿ20ms�γ�һ��֧�ֶ������ռ�ձ�
	//ͨ����ʱ����ȷʵ��
	/*if(k==11)
	{
		P1=1;
	}
	else
	+{
		P1=0;
	}*/
		if(flag==1)//flag1�ڴ��ڷ���һ�����ݺ���1
		{
			delay(160);
			k=seg[1];
			delay(160);
			pwm_i=1;
			
			j=1;
			//delay(300);
			//delay(dat);
			//����
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
	//static u16 pwm_i=1,j=1;//����һ��ȫ�ֱ���
	TH0=0XFF;
	TL0=0XA3;
	//TH0=0xff;
	//TL0=0X9C;//��װ
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
	if(pwm_i<=k+1)//��1��ԭ���ǿ��ǵ�һ�ζ�ʱ��ִ��δ����pwm���һ����ƽ********************
	//�����ת30��
	{
		pwm=1;
	}
	else
	{
		pwm=0;
	}
	if(pwm_i>=201)//һ���������
	{
		pwm_i=1;//��0
	}

}
		
