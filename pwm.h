#ifndef _PMW_H
#define _PMW_H
#include"reg52.h"
/*typedef unsigned char u8;
typedef unsigned int u16;*/
#define u8 unsigned char
#define u16 unsigned int

sbit pwm=P2^0;

extern u16 k,pwm_i,j,dat;//k�����γ�ռ�ձȣ�i��j�ֱ����������ȼ�ʱ����ʱʱ���ʱ
extern u16 seg[2];//�˴�Ϊռ�ձȵ�ֵ
extern u8 flag0;//flag1;//flag0Ϊ�����γ�pwm���εģ�flag1Ϊ���ڽ���ָ�ʼ��
extern int dev,t_dev;
extern float fl_dev;
void pwm_ini0tial();
void delay(unsigned int z);
void Engine(int );

#endif