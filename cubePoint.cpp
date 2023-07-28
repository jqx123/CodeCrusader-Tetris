#include"cubePoint.h"
#include<stdio.h>
#include<graphics.h>



void CubePoint::printPoint()
{
	IMAGE img0;
	loadimage(&img0, "D:\\CodeCrusader\\CodeCrusader-Tetris\\res\\cube0.png",16,16,true);
	IMAGE img1;
	loadimage(&img1, "D:\\CodeCrusader\\CodeCrusader-Tetris\\res\\cube1.png", 16, 16, true);

	switch(color)
	{
		case 0:putimage(this->x, this->y,&img0); break;
		case 1: putimage(this->x,this->y,&img1); break;
		/*
		 case RED       :printf("\033[41;31m  \033[0m");break;
		 case GREEN     :printf("\033[42;32m  \033[0m");break;
		 case YELLOW    :printf("\033[43;33m  \033[0m");break;
		 case BLUE      :printf("\033[44;34m  \033[0m");break;
		 case PURPLE    :printf("\033[45;35m  \033[0m");break;
		 case DEEP_GREEN:printf("\033[46;36m  \033[0m");break;
		 case WHITE     :printf("\033[47;37m  \033[0m");break;
		 */
		
		 default:
		 break;
	}
}

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

//测试代码
