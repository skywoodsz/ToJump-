#ifndef _COM_H
#define _COM_H

#include"reg52.h"
#define uchar unsigned char
#define uint unsigned int
extern uchar flag,num;
extern uchar rd[10];
extern uint g_dat;
extern int i;
extern uint k,key3,n;
extern uchar dir;
//extern void Engine();
void ComInit();
void Com();
#endif