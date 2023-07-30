#include "panel.h"
#include "cubePoint.h"
#include <cstdlib>
#include <ctime>
#include <string>

#define PENAL_SIZE (10 * 30 * sizeof(int))
#define CUBE_SIZE (4 * 4 * sizeof(int))

#define DOWN 0
#define LEFT 1
#define RIGHT 2

// 恢复设置（方块会探索下一个位置是否合法，不合法需恢复面板）
bool panel::recoverPenal()
{
    int b[4][4] = {0};
    int x, y;
    memcpy(b, m_block->getArray(), 4 * 4 * sizeof(int));
    m_block->getLocate(&x, &y);
    for (int i = -1; i < 3; ++i)
        for (int j = -1; j < 3; ++j)
            m_penal[x + i][y + j] = b[i + 1][j + 1];
    return true;
}

// 是否着陆(是否碰到下边)
bool panel::isAttachBottom()
{
    int cube_x, cube_y;
    // 获取方块数组
    int b[4][4] = {0};
    bool flag = false;
    memcpy(b, m_block->getArray(), (4 * 4 * sizeof(int)));
    // 拿到相对地图坐标(左上)
    m_block->getLocate(&cube_x, &cube_y);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // 方块与Y轴下一个均为1时返回true
            if (b[i][j] == 1 && m_penal[cube_x + i][cube_y + j + 1] == 1)
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
    int cube_x, cube_y;
    int b[4][4] = {0}; // 获取方块数组
    int flag = false;
    m_block->getLocate(&cube_x, &cube_y);
    memcpy(b, m_block->getArray(), CUBE_SIZE);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (b[i][j] == 1 && m_penal[cube_x + i - 1][j + cube_y] == 1)
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
    int cube_x, cube_y;
    int b[4][4] = {0}; // 获取方块数组
    int flag = false;
    m_block->getLocate(&cube_x, &cube_y);
    memcpy(b, m_block->getArray(), CUBE_SIZE);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (b[i][j] == 1 && m_penal[cube_x + i + 1][j + cube_y] == 1)
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

// 随机获取方块形状
string panel::randomShape()
{
    string BlockType;
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

// 用方块数组给面板数组赋值
bool panel::setPenal()
{
    int b[4][4] = {0}; // 获取方块数组
    int x, y;
    m_block->getLocate(&x, &y);
    memcpy(b, m_block->getArray(), CUBE_SIZE);
    for (int i = x; i < x + 4; i++)
        for (int j = y; j < y + 4; j++)
        {
            m_penal[i][j] += b[i - x][j - y];
            if (m_penal[i][j] > 1)
            {
                cout << "game over" << endl;
                // 加分数统计排行榜等
                system("stty icanon echo");
                exit(0);
            }
        }
    return true;
}

// 方块动过后要把遗留面板信息擦除
bool panel::erasePenal()
{
    int blk[4][4] = {0};
    int x, y;
    m_block->getLocate(&x, &y);
    memcpy(blk, m_block->getArray(), 4 * 4 * sizeof(int));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m_penal[i + x][j + y] -= blk[i][j];
        }
    }
    return true;
}

// 随机创建方块的方法
void panel::createCube()
{
    m_block = new BlockFactory(randomShape());
    m_block->shape();
    m_block->setLocate(1, 0);
    setPenal();
    // m_block->showblock();
}

//!!!
// 键盘响应
void keyEvent()
{
}

// 移动的方法,移动的过程中对m_penal的改变
void panel::move(int dir)
{
    erasePenal();
    switch (dir)
    {
    case DOWN:
        if (false == isAttachBottom())
        {
            m_block->move(DOWN);
            setPenal();
            m_block->showblock(1);
        }
        else
        {
            recoverPenal();
            m_block->showblock(1);
            erase();
            stop();
        }
        break;
    case LEFT:
        if (false == isAttachLeft())
        {
            m_block->move(LEFT);
            setPenal();
            m_block->showblock(1);
        }
        else
        {
            recoverPenal();
            m_block->showblock(1);
        }

        break;
    case RIGHT:
        if (false == isAttachRight())
        {
            m_block->move(RIGHT);
            setPenal();
            m_block->showblock(1);
        }
        else
        {
            recoverPenal();
            m_block->showblock(1);
        }
        break;
    default:
        break;
    }
}

// 旋转的方法。。。如果能旋转，那么旋转，否则不转,调用rotate
void panel::can_roll()
{
    // 取出方块的值，先放到一个数组中
    int i, j;
    int flag = 0;
    int b[3][3] = {0}; // 获取方块数组
    int temp[3][3] = {0};
    int x, y;
    m_block->getLocate(&x, &y);
    memcpy(b, m_block->getArray(), CUBE_SIZE);
    erasePenal();
    // 旋转数组
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            temp[2 - j][i] = b[i][j];
        }
    // 判断旋转后是否会与面板重合
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (temp[i][j] == 1 && m_penal[x + i][y + j] == 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    // 如果不重合则旋转方块，设置面板的值
    if (flag == 0)
    {
        m_block->rotate();
    }
    setPenal();
    m_block->showblock(0);
}

// 方块停止
void panel::stop()
{
    delete m_block;
    createCube();
}

// 擦除满行
void panel::erase()
{
    int i, j;
    int flag = 0;
    for (i = 30; i > 0; i--)
    {
        for (j = 1; j < 10; j++)
        {
            if (m_penal[i][j] == 0)
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
        for (j = 1; j < 16; j++)
        {
            m_penal[i][j] = m_penal[i - 1][j];
        }
    // 刷新面板
    CubePoint p;
    for (i = 1; i < 23; i++)
        for (j = 1; j < 16; j++)
        {
            if (m_penal[i][j] == 1)
            {
                p.setLocate(i, j);
                p.setColor(1);
                p.printPoint();
            }
            if (m_penal[i][j] == 0)
            {
                p.setLocate(i, j);
                p.setColor(CLEAR);
                p.printPoint();
            }
        }
}