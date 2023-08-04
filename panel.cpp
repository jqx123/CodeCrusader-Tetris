#include <cstdlib>
#include <ctime>
#include <string>
#include "panel.h"
#include "cubePoint.h"
#include "game.h"

#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define PENAL_SIZE (10 * 20 * sizeof(int))


#define DOWN 0
#define LEFT 1
#define RIGHT 2


/*
* 
* 
// 恢复设置（方块会探索下一个位置是否合法，不合法需恢复面板）
bool panel::recoverPenal()
{
    int b[4][4] = {0};
    int x, y;
   // memcpy(b, m_block->getArray(), 4 * 4 * sizeof(int));
    now_block->getLocate(&x, &y);
    for (int i = -1; i < 3; ++i)
        for (int j = -1; j < 3; ++j)
            m_panel[x + i][y + j] = b[i + 1][j + 1];
    return true;
}



*/

// 是否着陆(是否碰到下边)
bool panel::isAttachBottom()
{
    int flag = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (now_block->block->bk[i][j] == 1 && m_panel[now_block->block->x + i+1 ][now_block->block->y + j] == 1)
            {
                flag = true;
                break;

            }
        }
        if (flag == true)
            break;
    }
    return flag;
}

// 是否碰到左边
bool panel::isAttachLeft()
{
    int cube_x=now_block->block->x, cube_y= now_block->block->y;
    int flag = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (now_block->block->bk[i][j] == 1 && m_panel[cube_x + i ][cube_y+j-1] == 1)
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            break;
    }
    return flag;
}

// 是否碰到右边
bool panel::isAttachRight()
{
    int cube_x = now_block->block->x, cube_y = now_block->block->y;
    //BlockFactory* tempblock = new BlockFactory(*m_block);
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (now_block->block->bk[i][j] == 1 && m_panel[cube_x + i ][cube_y + j+1] == 1)
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            break;
    }
    return flag;
}

bool panel::isAttachBlock() {
    // 取出方块的值，先放到一个数组中
    int flag = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (now_block->block->bk[i][j] == 1 && m_panel[now_block->block->x + i+1][now_block->block->y + j] == 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 1)
    {
        return true;
    }
    else {
        return false;
    }

}

// 随机获取方块形状
std::string panel::randomShape()
{
    std::string BlockType;
    switch (rand() % 7 + 1)
    {
    case 1:
        BlockType = "LongBlock";
        break;
    case 2:
        BlockType = "SquareBlock";
        break;
    case 3:
        BlockType = "ZBlock";
        break;
    case 4:
        BlockType = "SBlock";
        break;
    case 5:
        BlockType = "LBlock";
        break;
    case 6:
        BlockType = "JBlock";
        break;
    case 7:
        BlockType = "TBlock";
        break;
    default:
        return NULL;
    }
    return BlockType;
}



// 随机创建方块的方法
void panel::createCube()
{
    //now_block = new BlockFactory(randomShape());
    now_block = next_block;
    now_block->shape();
    now_block->setLocate(1, 1);
    setPenal();
    // m_block->showblock();
    next_block = new BlockFactory(randomShape());
    next_block->shape();
    next_block->setLocate(1, 1);
}


// 旋转的方法,调用rotate
bool panel::can_roll()
{
    // 取出方块的值，先放到一个数组中
    int flag = 0;
    //now_block->getLocate(&x, &y);
    BlockFactory* tempblock = new BlockFactory(*now_block);
    // 旋转数组
    tempblock->rotate();
    // 判断旋转后是否会与面板重合
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tempblock->block->bk[i][j] == 1 && m_panel[now_block->block->x + i][now_block->block->y + j] == 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 0)
    {
        return true;
    }
    else {
        return false;
    }
}

// 方块停止
void panel::stop()
{
    delete now_block;
    createCube();
}

// 擦除满行
void panel::erase()
{
    int i, j;
    int flag = 0;
    for (i = 20; i > 0; i--)
    {
        for (j = 1; j < 11; j++)
        {
            if (m_panel[i][j] == 0)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            // 该行上面的图形整体坐落
            down(i);
            i++;
        }
        flag = 0;
    }
}

// 擦除完上面的图形整块坠落
void panel::down(int level)
{
    int i, j;
    int flag = 1;
    for (i = level; i > 1; i--)
        for (j = 1; j < 20; j++)
        {
            m_panel[i][j] = m_panel[i - 1][j];
        }
    score += level * 10;

    /*
    // 刷新面板
    CubePoint p;
    for (i = 1; i < 23; i++)
        for (j = 1; j < 16; j++)
        {
            if (m_panel[i][j] == 1)
            {
                p.setLocate(i, j);
                p.setColor(1);
                p.printPoint();
            }
            if (m_panel[i][j] == 0)
            {
                p.setLocate(i, j);
                p.setColor(CLEAR);
                p.printPoint();
            }
        }
    */
}

void panel::showscore(int num) {
    p.printnum(score);
}

/*
initgraph(500, 750, EW_SHOWCONSOLE);
IMAGE img;
loadimage(&img, _T("res/background.png"), 500, 750);
putimage(0, 0, &img);

CubePoint p;
p.printnum(123456);

getchar();
*/

void panel::showtime() {
    p.printtime();
}


void panel::showpanel() {
    for (int i = 1; i < 21; i++) {
        for (int j = 1; j < 11; j++) {
            p.setLocate(xbase +  j  * cube_size, ybase +i * cube_size);
            p.setColor(m_panel[i][j]);
            p.printPoint();
        }
    }
}

// 用方块数组给面板数组赋值
bool panel::setPenal()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <  4; j++)
        {
            m_panel[now_block->block->x+i][now_block->block->y+j] += now_block->block->bk[i][j];
        }
    }
    return true;
}

bool panel::erasePenal()
{
    for (int i =0; i < 4; i++) {
        for (int j =0; j < 4; j++)
        {
            m_panel[now_block->block->x+i][now_block->block->y+j] -= now_block->block->bk[i][j];
        }
    }
    return true;
}

bool panel::gameOver()
{
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            if (m_panel[i][j] == 1)
            {
                return true;
            }
        }
    }
    return false;
}


bool panel::haveblock() {
    bool flag = false;
    for (int j = 1; j <11; j++)
    {
      if (m_panel[20][j] == 1)
       {
         flag= true;
       }
      if (flag == true) {
          break;
      }
    }
    return flag;
}


// 绘制页面1的函数
void dieview()
{

    settextcolor(RED);
    settextstyle(30, 0, _T("微软雅黑"));
    outtextxy(150, 460, _T("gameover"));
    outtextxy(150, 500, _T("return to menu"));
}




void BGM() {
    mciSendString("open res/music.mp3", 0, 0, 0);
    mciSendString("play res/music.mp3", 0, 0, 0);
}


void startgame(panel p) {

    initgraph(500, 750, EW_SHOWCONSOLE);
    IMAGE img;
    loadimage(&img, _T("res/background.png"), 500, 750);
    putimage(0, 0, &img);

    BlockFactory* block = new BlockFactory("LongBlock");
    block->shape();
    block->setLocate(16, 1);
    //block->showblock();

    p.now_block = block;
    p.setPenal();
    p.next_block = new BlockFactory("SBlock");
    p.next_block->shape();
    p.next_block->setLocate(1, 1);


    int cflag = 0;

    //game g = game();

    ExMessage msg;
    while (cflag == 0) {
        BeginBatchDraw();

        if (peekmessage(&msg, EM_MOUSE)) {
            switch (msg.message) {
            case WM_LBUTTONDOWN:
                //转
                if (msg.x >= 319 && msg.x <= 332 + 60 && msg.y >= 509 && msg.y <= 509 + 60) {
                    p.erasePenal();
                    if (p.can_roll()) {
                        p.now_block->rotate();
                        p.setPenal();

                    }
                }
                //左
                if (msg.x >= 248 && msg.x <= 248 + 60 && msg.y >= 562 && msg.y <= 562 + 60) {
                    p.erasePenal();
                    if (!p.isAttachLeft()) {
                        p.now_block->move(1);
                    }
                    p.setPenal();

                }
                //右
                if (msg.x >= 400 && msg.x <= 400 + 60 && msg.y >= 576 && msg.y <= 576 + 60) {
                    p.erasePenal();
                    if (!p.isAttachRight()) {
                        p.now_block->move(2);
                    }
                    p.setPenal();

                }

                //下
                if (msg.x >= 315 && msg.x <= 315 + 60 && msg.y >= 634 && msg.y <= 634 + 60) {
                    p.erasePenal();
                    if (!p.isAttachBottom()) {
                        p.now_block->move(0);

                        if (p.isAttachBlock()) {
                            p.setPenal();
                            p.erase();// 生成方块前 做整行消除判定

                            if (p.haveblock() && p.gameOver()) {
                                cleardevice();
                                dieview();

                                while (cflag == 0) {
                                    if (peekmessage(&msg, EM_MOUSE)) {
                                        switch (msg.message) {
                                        case WM_LBUTTONDOWN:
                                            if (msg.x >= 150 && msg.x <= 150 + 60 && msg.y >= 480 && msg.y <= 480 + 60) {
                                                p.viewflag = 0;
                                                cflag = 1;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            p.createCube();
                        }
                        else {
                            p.setPenal();
                        }

                    }
                }
                break;
            default:
                break;
            }
        }
        else {
            Sleep(500);
            p.erasePenal();
            if (!p.isAttachBottom()) {
                p.now_block->move(0);

                if (p.isAttachBlock()) {
                    p.setPenal();
                    p.erase();// 生成方块前 做整行消除判定

                    if (p.haveblock() && p.gameOver()) {
                        cleardevice();
                        dieview();

                        while (cflag == 0) {
                            if (peekmessage(&msg, EM_MOUSE)) {
                                switch (msg.message) {
                                case WM_LBUTTONDOWN:
                                    if (msg.x >= 150 && msg.x <= 150 + 60 && msg.y >= 480 && msg.y <= 480 + 60) {
                                        p.viewflag = 0;
                                        cflag = 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    p.createCube();
                }
                else {
                    p.setPenal();
                }

            }
        }
        p.showscore(p.score);
        p.showtime();
        p.showpanel();
        p.next_block->shownextblock();

        EndBatchDraw();
    }

}

void panel::gameview(panel p) {

    initgraph(500, 750, EW_SHOWCONSOLE);
    BGM();
    ExMessage msg;

    while (true) {
        if (viewflag == 0) {
            startview();
            while (viewflag == 0) {
                if (peekmessage(&msg, EM_MOUSE)) {
                    switch (msg.message) {
                    case WM_LBUTTONDOWN:
                        if (msg.x >= 150 && msg.x <= 150 + 30 && msg.y >= 109 && msg.y <= 109 + 40) {
                            viewflag = 1;
                        }
                        if (msg.x >= 150 && msg.x <= 150 + 30 && msg.y >= 177 && msg.y <= 177 + 40) {
                            viewflag = 2;
                        }
                        if (msg.x >= 150 && msg.x <= 150 + 30 && msg.y >= 247 && msg.y <= 247 + 40) {
                            viewflag = 3;
                        }
                        if (msg.x >= 0 && msg.x <= 0 + 30 && msg.y >= 0 && msg.y <= 0 + 40) {
                            viewflag = 4;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        else if (viewflag == 1) {
            if (viewflag == 1) {
                startgame(p);
            }
        }
        else if (viewflag == 2) {
            settinggame();
            while (viewflag == 2) {
                if (peekmessage(&msg, EM_MOUSE)) {
                    switch (msg.message) {
                    case WM_LBUTTONDOWN:
                        if (msg.x >= 313 && msg.x <= 313 + 30 && msg.y >= 372 && msg.y <= 372 + 40) {
                            viewflag = 0;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        else if (viewflag == 3) {
            exitgame();
        }
        else {
            aboutgame();
            while (viewflag == 4) {
                if (peekmessage(&msg, EM_MOUSE)) {
                    switch (msg.message) {
                    case WM_LBUTTONDOWN:
                        if (msg.x >= 304 && msg.x <= 304 + 30 && msg.y >= 383 && msg.y <= 383 + 40) {
                            viewflag = 0;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
}




