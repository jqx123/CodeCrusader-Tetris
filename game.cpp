#include "game.h"
#include <string>
#define VOLUME_NUM 9		//不知道分多少个等级，9是临时值
#define LEVEL_NUM 9			//不知道分多少个等级，9是临时值

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
void game::setting(int & volume, int & level)
{
	int x1, x2, y1;	//volume左右按钮的基准坐标
	int x3, x4, y3;	//level左右按钮的基准坐标
	int w1, h1;			//按钮大小
	int x5, y5, w2, h2;	//返回菜单的基准坐标
	while (1) {			//在当前界面等待输入
		print_volume(x1, y1, x2, w1, h1, volume);		//显示音量箭头和当前值，坐标1是左按钮，2是右
		print_level(x3, y3, x4, w1, h1, level);		//显示难度箭头和当前值，坐标3是左按钮，4是右
		print_menu(x5, y5, w2, h2);			//显示返回菜单按键
		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg && msg.x >= x5 && msg.x <= x5 + w && msg.y >= y5 && msg.y <= y5 + h)
			{
				return;			//返回上层菜单
			}
			if (WM_LBUTTONDOWN == msg.uMsg && msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
			{
				volume = (volume + 1) % VOLUME_NUM;				//MOD1为音量等级个数
			}
			if (WM_LBUTTONDOWN == msg.uMsg && msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
			{
				volume = (volume - 1) % VOLUME_NUM;
			}
			if (WM_LBUTTONDOWN == msg.uMsg && msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
			{
				level = (level + 1) % LEVEL_NUM;					//MOD2为难度等级个数
			}
			if (WM_LBUTTONDOWN == msg.uMsg && msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
			{
				level = (level - 1) % LEVEL_NUM;
			}
		}
	}
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
