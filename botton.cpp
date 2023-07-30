#include "botton.h"
#include<graphics.h>
#include<cstdio>

// 开始菜单的按钮

// 开始游戏
void botton_start(int x, int y, int w, int h) {
	IMAGE img;
	loadimage(&img, _T("res/start.png"), w, h);
	putimage(x, y, &img);
}
// 游戏设置
void botton_setting(int x, int y, int w, int h) {
	IMAGE img;
	loadimage(&img, _T("res/setting.png"), w, h);
	putimage(x, y, &img);
}
// 关于游戏
void botton_about(int x, int y, int w, int h) {
	IMAGE img;
	loadimage(&img, _T("res/about.png"), w, h);
	putimage(x, y, &img);
}
// 退出游戏
void botton_exit(int x, int y, int w, int h) {
	IMAGE img;
	loadimage(&img, _T("res/exit.png"), w, h);
	putimage(x, y, &img);
}

// 游戏界面的按钮

// 暂停，音效，重玩
void botton_pause(int x, int y, int w, int h) {
	char s[] = "暂停";
	ExMessage msg = { 0 };
	int W = textwidth(s);
	int H = textheight(s);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	while (true) {
		if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {}
		BeginBatchDraw();
		if (msg.message == WM_LBUTTONDOWN && msg.x > x && msg.x<x + w && msg.y>y && msg.y < y + h) {
			setfillcolor(RGB(70, 70, 70));
			fillroundrect(x, y, x + w, y + h, 10, 10);
		}
		else {
			setfillcolor(WHITE);
			fillroundrect(x, y, x + w, y + h, 10, 10);
		}
		outtextxy((w - W) / 2 + x, (h - H) / 2 + y, s);
		EndBatchDraw();
	}
	getchar();
}
void botton_voice(int x, int y, int w, int h) {
	char s[] = "音量";
	ExMessage msg = { 0 };
	int W = textwidth(s);
	int H = textheight(s);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	while (true) {
		if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {}
		BeginBatchDraw();
		if (msg.message == WM_LBUTTONDOWN && msg.x > x && msg.x<x + w && msg.y>y && msg.y < y + h) {
			setfillcolor(RGB(70, 70, 70));
			fillroundrect(x, y, x + w, y + h, 10, 10);
		}
		else {
			setfillcolor(WHITE);
			fillroundrect(x, y, x + w, y + h, 10, 10);
		}
		outtextxy((w - W) / 2 + x, (h - H) / 2 + y, s);
		EndBatchDraw();
	}
	getchar();
}
int botton_reset(int x, int y, int w, int h) {
	char s[] = "重新开始";
	ExMessage msg = { 0 };
	int W = textwidth(s);
	int H = textheight(s);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	while (true) {
		if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {}
		BeginBatchDraw();
		if (msg.message == WM_LBUTTONDOWN && msg.x > x && msg.x<x + w && msg.y>y && msg.y < y + h) {
			setfillcolor(RGB(70, 70, 70));
			fillroundrect(x, y, x + w, y + h, 10, 10);
		}
		else {
			setfillcolor(WHITE);
			fillroundrect(x, y, x + w, y + h, 10, 10);
		}
		outtextxy((w - W) / 2 + x, (h - H) / 2 + y, s);
		EndBatchDraw();
	}
	getchar();
}

//设置界面的按钮

//显示音量箭头和当前值，坐标1是左按钮，2是右，w和h是左右按钮的宽和高
void print_volume(int x1, int y1, int x2, int w, int h, int volume) {
	wchar_t s[] = L"音量：";
	settextstyle(h, 0, _T("黑体"));
	settextcolor(BLACK);
	outtextxy(x1 - 25, y1, s);
	//左按钮
	IMAGE imgl;					//存储左贴图的对象
	loadimage(&imgl, _T("res/decline.png"), w, h);	//载入贴图
	putimage(x1, y1, &imgl);		//放置按钮贴图

	//右按钮
	IMAGE imgr;					//存储右贴图的对象
	loadimage(&imgr, _T("res/plus.png"), w, h);	//载入贴图
	putimage(x2, y2, &imgr);		//放置按钮贴图

	//volume数值显示
	wchar_t n[];
	sprintf(n, "%d", volume);
	settextstyle(h, 0, _T("黑体"));
	settextcolor(BLACK);
	outtextxy(x1 + 20, y1, n);			//假设数值在x1右侧20个单位的位置
}

//显示难度箭头和当前值，坐标3是左按钮，4是右
void print_level(int x3, int y3, int x4, int w, int h, int level) {
	wchar_t s[] = L"难度：";
	settextstyle(h, 0, _T("黑体"));
	settextcolor(BLACK);
	outtextxy(x3 - 25, y3, s);
	//左按钮
	IMAGE imgl;					//存储左贴图的对象
	loadimage(&imgl, _T("res/decline.png"), w, h);	//载入贴图
	putimage(x3, y3, &imgl);		//放置按钮贴图

	//右按钮
	IMAGE imgr;					//存储右贴图的对象
	loadimage(&imgr, _T("res/plus.png"), w, h);	//载入贴图
	putimage(x4, y4, &imgr);	//放置按钮贴图

	//level数值显示
	wchar_t n[];
	sprintf(n, "%d", level);
	settextstyle(h, 0, _T("黑体"));
	settextcolor(BLACK);
	outtextxy(x3 + 20, y3, n);			//假设数值在x1右侧20个单位的位置
}

//返回菜单按钮(直接借用了“游戏规则”按钮的代码)
void print_menu(int x5, int y5, int w, int h) {			
	rectangle(x5, y5, x5 + w, y5 + h);
	setbkmode(TRANSPARENT);
	wchar_t s[] = L"返回菜单";
	settextstyle(h, 0, _T("黑体"));
	settextcolor(BLACK);
	outtextxy(x, y, s);
	if (MouseHit())
	{
		MOUSEMSG msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= x5 && msg.x <= x5 + w && msg.y >= y5 && msg.y <= y5 + h)
		{
			settextcolor(WHITE);
		}
	}
	closegraph();
}

// 左右下移，掉落 view
int botton_up(int x, int y, int w, int h) {
	IMAGE img;					//存储贴图的对象
	loadimage(&img, _T("res/up.png"), w, h);	//载入贴图
	putimage(x, y, &img);		//放置按钮贴图
	if (MouseHit())				//检测鼠标
		/*或许应该把检测放在外面？
		若检测到单击或键盘，则传入相应的值，
		在该函数中仅检测对应标志值来决定是否做出反应？*/
	{
		MOUSEMSG msg = GetMouseMsg();
		if (WM_LBUTTONDOWN == msg.uMsg && msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
		{
			return 1;			//收到单击
		}
	}
	return 0;		//未收到单击
}
int botton_moveleft(int x, int y, int w, int h) {
	IMAGE img;
	loadimage(&img, _T("res/left.png"), w, h);
	putimage(x, y, &img);
	if (MouseHit())
	{
		MOUSEMSG msg = GetMouseMsg();
		if (WM_LBUTTONDOWN == msg.uMsg && msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
		{
			return 1;
		}
	}
	return 0;
}
int botton_moveright(int x, int y, int w, int h) {
	IMAGE img;
	loadimage(&img, _T("res/right.png"), w, h);
	putimage(x, y, &img);
	if (MouseHit())
	{
		MOUSEMSG msg = GetMouseMsg();
		if (WM_LBUTTONDOWN == msg.uMsg && msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
		{
			return 1;
		}
	}
	return 0;
}
int botton_movedown(int x, int y, int w, int h) {
	IMAGE img;
	loadimage(&img, _T("res/down.png"), w, h);
	putimage(x, y, &img);
	if (MouseHit())
	{
		MOUSEMSG msg = GetMouseMsg();
		if (WM_LBUTTONDOWN == msg.uMsg && msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
		{
			return 1;
		}
	}
	return 0;
}
int botton_movetobottom(int x, int y, int w, int h) {
	IMAGE img;
	loadimage(&img, _T("res/space.png"), w, h);
	putimage(x, y, &img);
	if (MouseHit())
	{
		MOUSEMSG msg = GetMouseMsg();
		if (WM_LBUTTONDOWN == msg.uMsg && msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
		{
			return 1;
		}
	}
	return 0;
}

// 关于游戏的按钮

// 游戏规则按钮
void botton_aboutrule(int x, int y, int w, int h)
{
<<<<<<< HEAD
    rectangle(x, y, x + w, y + h);
    setbkmode(TRANSPARENT);
    wchar_t s[] = L"游戏规则";
    settextstyle(h, 0, _T("黑体"));
    settextcolor(BLACK);
    outtextxy(x,y,s);
    
        if (MouseHit()) 
        {
            MOUSEMSG msg = GetMouseMsg(); 
            if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= x && msg.x <= x+w && msg.y >= y && msg.y <= y+h)
            {
                settextcolor(WHITE); // 设置文本颜色为白色
            }
        }
    
    closegraph();

}
// 开发人员按钮
void botton_aboutdevelopers(int x, int y, int w, int h)
{
<<<<<<< HEAD
    rectangle(x, y, x + w, y + h);
    setbkmode(TRANSPARENT);
    wchar_t s[] = L"开发人员";
    settextstyle(h, 0, _T("黑体"));
    settextcolor(BLACK);
    outtextxy(x, y, s);
  
        if (MouseHit())
        {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
            {
                settextcolor(WHITE); // 设置文本颜色为白色
            }
        }
    
    closegraph();
}
