#include "game.h"
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
}

// 游戏结束或暂停的返回界面
void game::pauseorover()
{
}
