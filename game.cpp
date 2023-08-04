#include "game.h"
#include "cubePoint.h" //print
#include "common.h"	   //Score


void startview()
{
	IMAGE img3;
	loadimage(&img3, "res/start.png", 500, 750);
	putimage(0, 0, &img3);
}

void exitgame() {
	settextcolor(RED);
	settextstyle(30, 0, _T("微软雅黑"));
	outtextxy(150, 460, _T("exit!"));
}


void settinggame() {
	IMAGE img4;
	loadimage(&img4, "res/rules.png", 500, 750);
	putimage(0, 0, &img4);
}

void aboutgame() {
	IMAGE img5;
	loadimage(&img5, "res/about.png", 500, 750);
	putimage(0, 0, &img5);
}

