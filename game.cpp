#include "game.h"
#include <string>
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
    HWND hwnd = NULL; 
    LPCWSTR lpText = L"你确定要退出游戏吗？"; // 消息框文本
    LPCWSTR lpCaption = L"确认退出"; // 消息框标题
    UINT uType = MB_YESNO | MB_ICONQUESTION; // 消息框类型，包含“是”和“否”按钮

    int nResult = MessageBox(hwnd, lpText, lpCaption, uType); 

    if (nResult == IDYES) 
    {
        exit(0);
    }
    else if (nResult == IDNO) 
    {
        play();
    }

   

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
