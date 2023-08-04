#define _CRT_SECURE_NO_WARNINGS //VS中必须定义,否则报错
#include <stdio.h>
#include <time.h>
#include <graphics.h>
#include "cubePoint.h"


//画出像素点


void CubePoint::printPoint()
{
	switch (color)
	{
	case 0:
		putimage(this->x, this->y, &img0);
		break;
	case 1:
		putimage(this->x, this->y, &img1);
		break;
	default:
		break;
	}
}

int numxbase = 325;
int numybase = 118;
int num_cubexsize = 10;
int num_cubeysize = 18;


//打印份数
void CubePoint::printnum(int num)
{

	int number[6];
	for (int i = 0; i < 6; i++) {
		number[i] = num % 10;
		num = num / 10;
		switch (number[i])
		{
		case 0:
			putimage(numxbase + (5- i ) * num_cubexsize, numybase, &i0);
			break;
		case 1:
			putimage(numxbase + (5 - i) * num_cubexsize, numybase, &i1);
			break;
		case 2:
			putimage(numxbase + (5 - i) * num_cubexsize, numybase, &i2);
			break;
		case 3:
			putimage(numxbase + (5 - i) * num_cubexsize, numybase, &i3);
			break;
		case 4:
			putimage(numxbase + (5 - i) * num_cubexsize, numybase, &i4);
			break;
		case 5:
			putimage(numxbase + (5 - i) * num_cubexsize, numybase, &i5);
			break;
		case 6:
			putimage(numxbase + (5 - i) * num_cubexsize, numybase, &i6);
			break;
		case 7:
			putimage(numxbase + (5 - i) * num_cubexsize, numybase, &i7);
			break;
		case 8:
			putimage(numxbase + (5 - i) * num_cubexsize, numybase, &i8);
			break;
		case 9:
			putimage(numxbase + (5 - i) * num_cubexsize, numybase, &i9);
			break;
		default:
			break;
		}
	}
	
}

//打印时间
void CubePoint::printtime() {
		time_t timer0;
		time(&timer0);
		struct tm* plocaltime = localtime(&timer0);
		//plocaltime->tm_hour, plocaltime->tm_min, plocaltime->tm_sec

		int hourxbase = 338;
		int hourybase = 405;
		int minxbase = 371;
 		
		int hour=plocaltime->tm_hour;
		int number[2];
		for (int i = 0; i < 2; i++) {
			number[i] = hour % 10;
			hour = hour / 10;
			switch (number[i])
			{
			case 0:
				putimage(hourxbase + (1 - i) * num_cubexsize, hourybase, &i0);
				break;
			case 1:
				putimage(hourxbase + (1 - i) * num_cubexsize, hourybase, &i1);
				break;
			case 2:
				putimage(hourxbase + (1 - i) * num_cubexsize, hourybase, &i2);
				break;
			case 3:
				putimage(hourxbase + (1 - i) * num_cubexsize, hourybase, &i3);
				break;
			case 4:
				putimage(hourxbase + (1 - i) * num_cubexsize, hourybase, &i4);
				break;
			case 5:
				putimage(hourxbase + (1 - i) * num_cubexsize, hourybase, &i5);
				break;
			case 6:
				putimage(hourxbase + (1 - i) * num_cubexsize, hourybase, &i6);
				break;
			case 7:
				putimage(hourxbase + (1 - i) * num_cubexsize, hourybase, &i7);
				break;
			case 8:
				putimage(hourxbase + (1 - i) * num_cubexsize, hourybase, &i8);
				break;
			case 9:
				putimage(hourxbase + (1 - i) * num_cubexsize, hourybase, &i9);
				break;
			default:
				break;
			}
		}

		int min = plocaltime->tm_min;
		for (int i = 0; i < 2; i++) {
			number[i] = min % 10;
			min = min / 10;
			switch (number[i])
			{
			case 0:
				putimage(minxbase + (1 - i) * num_cubexsize, hourybase, &i0);
				break;
			case 1:
				putimage(minxbase + (1 - i) * num_cubexsize, hourybase, &i1);
				break;
			case 2:
				putimage(minxbase + (1 - i) * num_cubexsize, hourybase, &i2);
				break;
			case 3:
				putimage(minxbase + (1 - i) * num_cubexsize, hourybase, &i3);
				break;
			case 4:
				putimage(minxbase + (1 - i) * num_cubexsize, hourybase, &i4);
				break;
			case 5:
				putimage(minxbase + (1 - i) * num_cubexsize, hourybase, &i5);
				break;
			case 6:
				putimage(minxbase + (1 - i) * num_cubexsize, hourybase, &i6);
				break;
			case 7:
				putimage(minxbase + (1 - i) * num_cubexsize, hourybase, &i7);
				break;
			case 8:
				putimage(minxbase + (1 - i) * num_cubexsize, hourybase, &i8);
				break;
			case 9:
				putimage(minxbase + (1 - i) * num_cubexsize, hourybase, &i9);
				break;
			default:
				break;
			}
		}
}

/*
		 case RED       :printf("\033[41;31m  \033[0m");break;
		 case GREEN     :printf("\033[42;32m  \033[0m");break;
		 case YELLOW    :printf("\033[43;33m  \033[0m");break;
		 case BLUE      :printf("\033[44;34m  \033[0m");break;
		 case PURPLE    :printf("\033[45;35m  \033[0m");break;
		 case DEEP_GREEN:printf("\033[46;36m  \033[0m");break;
		 case WHITE     :printf("\033[47;37m  \033[0m");break;
		 其他颜色
*/

/*
int main()
{
	initgraph(600, 600);
	setbkcolor(WHITE);
	cleardevice();
	CubePoint p=CubePoint();
	p.setLocate(0,0);
	p.setColor(1);

	p.printPoint();

	p.setLocate(0, 16);
	p.setColor(0);

	p.printPoint();
	getchar();
	return 0;
}
*/

// 测试代码
