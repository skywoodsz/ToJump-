#include"com.h"
#include"pwm.h"
uchar flag=0,num=0;
uchar rd[10];
uint g_dat;
int i;
//���ڳ�ʼ��
void ComInit();
void Com()
{
	//���ڳ�ʼ��
	ComInit();
	while(1)
	{
		
		P1=0X00;
		if(flag==1)
		{
			ES=0;
			//flag=0;
			//��������
			for(i=0;i<3;i++)
			{
				SBUF=rd[i];//��������
				while(!TI);
				TI=0;//��Ҫ��
				//num=0;
			}
			//������װ
			g_dat=rd[0]*100+rd[1]*10+rd[2]*1;
			//g_dat=rd[0]*1000+rd[1]*100+rd[2]*10+rd[3]*1;
			//g_time=g_dat*1.35;
			//���ݴ����pwm����
			//k=g_dat;
			//���ж��
			Engine(g_dat);
			//��������
			flag=0;
			ES=1;
		}
	}
}
void timer4() interrupt 4
{
	//��������
	if(RI)
	{
		RI=0;
		rd[num++]=SBUF;
		//�����ݽ��յ���λʱ�ı䷽��
			if(num==3)
		{
			num=0;
			flag=1;
		}
	}
}
//���ڳ�ʼ��
void ComInit()
{
	//TMOD=0X20;//����T1��ʱ��������ʽ2��8λ�Զ���װ
	TMOD=0X21;//���ö�ʱ��0 1
	/*TH1=0Xe6;
	TL1=0Xe6;//2400Bd
	*/
	//Timer0Init();
	
	TH1=0Xfa;
	TL1=0Xfa;//������=9600Bd
	
	/*TH1=0XF3;
	TL1=TH1;*///4800Bd
	PCON=0X80;//SMOD=1
	TR1=1;
	
	SM0=0;
	SM1=1;//ѡ�񴮿�ͨ�ŷ�ʽ1
	REN=1;//�����ڽ�������
	ES=1;//�򿪴����ж�
	EA=1;//�����ж�
}