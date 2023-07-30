#include "game.h"
#include"cubePoint.h"  //print
#include"common.h"  //Score
#include<Windows.h>  //Sleep
#include<graphics.h>
#include <string>
#include"common.h"
#include<graphics.h>
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
	//绘制一个矩形用于展示分数，位置为右上角，但是坐标和宽度暂时未知
	rectangle(x, y, x + w, y + h);
	//将Score转化为wchar
	std::wstring ScoreStr = std::to_wstring(Score);
	const wchar_t* ScoreWStr = ScoreStr.c_str();
	settextstyle(20, 0, _T("宋体"));
	//展示Score分数
	int textWidth = textwidth(ScoreWStr);
	int textHeight = textheight(ScoreWStr);
	int offsetX = (w - textWidth) / 2;
	int offsetY = (h - textHeight) / 2;
	outtextxy(x + offsetX, y + offsetY, ScoreWStr);
}

// 更新最高分
void game::updateHighestScore()
{
}

// 死亡界面
void game::gameover()
{
	CubePoint* p = new CubePoint();
	//从下往上一排排全部赋值成黑色方块
	for (int i = 29; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			p->setLocate(i, j);
			p->setColor(BLACK);
			p->printPoint();
		}
		Sleep(40);
	}

	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			p->setLocate(i, j);
			p->setColor(CLEAR);
			p->printPoint();
		}
		Sleep(40);
	}
	//打印恐龙图案，游戏分数 score 是最终得分四个字
	IMAGE dinosaur,score;
	loadimage(&dinosaur, _T("res/dinosaur.png"), width, height); 	//宽高待定
	loadimage(&score, _T("res/score.png"), width, height); 	//宽高待定
	putimage(x, y, &dinosaur); 	//坐标待定
	putimage(x, y, &score); 	//坐标待定
	//width 0， 自适应
	settextstyle(height, 0, _T("黑体")); 	//高待定
	settextcolor(BLACK);
	TCHAR* score_str;
	_stprintf(score_str, _T("%d"), Score); 
	Score = 0;  //Score 清空
	outtextxy(x, y, score_str);	  //坐标待定
	outtextxy(x, y, _T("按 esc 返回主菜单..."));	  //坐标待定（右下角）
	ExMessage m;
	while (1)
	{
		m = getmessage(EX_KEY);

		switch (m.message)
		{
		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
			{
				return;  //return 回到主循环
			}
			break;
		}
	}
}

// 游戏结束或暂停的返回界面
void game::pauseorover()
{
}
