#include "panel.h"
#include<cstdlib>
#include<ctime>
// 恢复设置（方块会探索下一个位置是否合法，不合法需恢复面板）
bool panel::recoverPenal() {
	int b[4][4] = { 0 };
	int x, y;
	memcpy(b, m_graph->getArray(), CUBE_SIZE);
	m_graph->getLocate(&x, &y);
	for (int i = -1; i < 3; ++i)
		for (int j = -1; j < 3; ++j)
			m_penal[x + i][y + j] = b[i + 1][j + 1];
	return true;
}

// 是否着陆(是否碰到下边)
bool panel::isAttachBottom() {
    //获取方块数组
    int b[4][4] = { 0 };
    memcpy(b, m_graph->getArray(), (4 * 4 * sizeof(int)));
    //拿到相对地图坐标(左上)
    int X, Y;
    m_graph->getLocate(&X, &Y);
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            //方块与Y轴下一个均为1时返回true
            if (b[i][j] == 1 && m_penal[X+i][Y+i-1] == 1) {
                flag = true;
                break;
            }
        }
        if (flag == true)break;
    }
    return flag;
}
// 是否碰到左边
bool panel::isAttachLeft() {}

// 是否碰到右边
bool panel::isAttachRight() 
{
    int x, y;
    int cube_x, cube_y;
    int b[4][4] = { 0 };
    int flag = flase;
    m_graph->getLocate(&cube_x, &cube_y);
    memcpy(b, m_graph->getArray(), (4*4*sizeof(int));
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (b[i][j] == 1 && m_penal[i + cube_x][j + cube_y + 1] == 1)
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
string panel::randomShape() {
	string BlockType;
    srand(static_cast<unsigned int>(time(0)));
    switch (rand() % 7 + 1) {
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
bool panel::setPenal() {}

// 方块动过后要把遗留面板信息擦除
bool panel::erasePenal() {
	int blk[4][4] = {0};
	int x, y;
	m_graph->getLocate(&x, &y); 
	memcpy(blk, m_graph->getArray(), 4 * 4 * sizeof(int));
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			m_penal[i + x][j + y] -= blk[i][j];
		}
	}
	return true;
}

// 随机创建方块的方法
void panel::createCube() {}

//!!!
// 键盘响应
void keyEvent() {}
// 移动的方法,移动的过程中对m_penal的改变
void panel::move(int dir) {}

// 旋转的方法。。。如果能旋转，那么旋转，否则不转,调用rotate
void panel::can_roll() {}

// 方块停止
void panel::stop() {}

// 擦除满行
void panel::erase() {}

// 擦除完上面的图形整块坠落
void panel::down(int level) {}