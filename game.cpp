#include "game.h"
#include <string>
#include<graphics.h>
#include"panel.h"
using namespace std;

// 游戏的入口函数，点击运行程序后被调用的程序
void game::play()
{
}

// 游戏的运行规则，点击开始游戏后的逻辑
void game::startgame()
{
}

// 游戏的设置界面逻辑
void game::setting()
{
}

// 退出游戏逻辑
void game::exitgame()
{
}

// 初始化游戏参数，包括绘出panel，准备随机方块，画出最高分，画出现有分0
void game::init()
{
	// 初始化窗口
	initgraph(BG_WIDTH, BG_HEIGHT);
	IMAGE panel_img;
	// 加载背景图片
	loadimage(&panel_img, "res/");
	// 画出最高分和当前分数0
	settextstyle(TEXT_HEIGHT, TEXT_WIDTH, _T("Arial"));
	char maxScoreText[20];
	sprintf(maxScoreText, "最高分: %d", MAX_SCORE);
	outtextxy(MAX_SCORE_X, MAX_SCORE_Y, _T(maxScoreText));
	outtext(NOW_SCORE_X, NOW_SCORE_Y, _T("当前得分: 0"));
	// 实例化panel
	panel* p = new panel();
	// 创建随机方块
	p->createCube();
	// 将方块数组赋值到面板数组上
	p->setPenal();
}
// 随机函数，用于生成随机方块,init专用
string random()
{
}

// 更新界面,更新init的所有项
void game::updateWindow()
{
}

// 画出分数
void game::drawScore()
{
}

// 更新最高分
void game::updateHighestScore()
{
}

// 死亡界面
void game::gameover()
{
}

// 游戏结束或暂停的返回界面
void game::pauseorover()
{
}
