#ifndef PANEL_H
#define PANEL_H
#include "block.h"

enum MARK{
	GAME_STOP = -1,
	GAME_PAUSE = 0,
	GAME_RUN = 1
};

class panel
{
private:
    int m_penal[10][30];
    // int m_color[24][17];
    BlockFactory *m_graph;
    BlockFactory *nextGraph;
    MARK mark;

public:
    // 恢复设置（方块会探索下一个位置是否合法，不合法需恢复面板）
    //李金岷
    bool recoverPenal();
    
    // 是否着陆(是否碰到下边)
    //邓锴
    bool isAttachBottom();

    // 是否碰到左边
    //段先林
    bool isAttachLeft();

    // 是否碰到右边
    //孟玲
    bool isAttachRight();

    // 随机生成方块
    //曾葚
    char randomShape();

    // 用方块数组给面板数组赋值
    //魏斐洋
    bool setPenal();

    // 方块动过后要把遗留面板信息擦除
    //许宏林
    bool erasePenal();

    // 随机创建方块的方法
    void createCube();

    // 移动的方法,移动的过程中对m_penal的改变
    void move(int dir);

    // 旋转的方法。。。如果能旋转，那么旋转，否则不转
    void can_roll();

    // 方块停止
    void stop();

    // 擦除满行
    void erase();

    // 擦除完上面的图形整块坠落
    void down(int level);
};
#endif