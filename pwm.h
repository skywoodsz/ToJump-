#ifndef _PMW_H
#define _PMW_H
#include"reg52.h"
/*typedef unsigned char u8;
typedef unsigned int u16;*/
#define u8 unsigned char
#define u16 unsigned int

sbit pwm=P2^0;

extern u16 k,pwm_i,j,dat;//k用来形成占空比，i和j分别用作脉冲宽度计时和延时时间计时
extern u16 seg[2];//此处为占空比的值
extern u8 flag0;//flag1;//flag0为允许形成pwm波形的，flag1为串口接收指令开始的
extern int dev,t_dev;
extern float fl_dev;
void pwm_ini0tial();
void delay(unsigned int z);
void Engine(int );

#endif