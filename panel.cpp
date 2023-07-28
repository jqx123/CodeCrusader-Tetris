#include "panel.h"
// 恢复设置（方块会探索下一个位置是否合法，不合法需恢复面板）
bool panel::recoverPenal() {}
// 是否着陆(是否碰到下边)
bool panel::isAttachBottom() {}

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
char panel::randomShape() {}

// 用方块数组给面板数组赋值
bool panel::setPenal() {}

// 方块动过后要把遗留面板信息擦除
bool panel::erasePenal() {}

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