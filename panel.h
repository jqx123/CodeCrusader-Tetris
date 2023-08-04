#ifndef PANEL_H
#define PANEL_H
#include "block.h"
#include "cubePoint.h"

enum MARK {
    GAME_STOP = -1,
    GAME_PAUSE = 0,
    GAME_RUN = 1
};

class panel
{
public:
    //int x;
    //int y;
    int m_panel[22][12];
    int viewflag =0;
    int score = 0;
    // int m_color[24][17];

    BlockFactory *now_block;
    BlockFactory *next_block;
    MARK mark;
    CubePoint p;
    panel() {
        p = CubePoint();
        for (int i = 0; i < 22; i++) {
            for (int j = 0; j < 12; j++) {
                m_panel[i][j] = 0;
            }
        }
        for (int i = 0; i < 12; i++) {
            m_panel[0][i] = 1;
            m_panel[21][i] = 1;
        }
        for (int i = 0; i < 22; i++) {
            m_panel[i][0] = 1;
            m_panel[i][11] = 1;
        }
        score = 0;
        now_block = NULL;
        next_block = NULL;
    }
    ~panel() {
        now_block = NULL;
        next_block = NULL;
    };
    // 恢复设置（方块会探索下一个位置是否合法，不合法需恢复面板）
    //李金岷
    //bool recoverPenal();
    
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
    std::string randomShape();

    bool isAttachBlock();

    // 方块动过后要把遗留面板信息擦除
    //许宏林
    //bool erasePenal();

    // 随机创建方块的方法
    void createCube();

    // 移动的方法,移动的过程中对m_penal的改变
    void move(int dir);

    // 旋转的方法。。。如果能旋转，那么旋转，否则不转
    bool can_roll();

    // 方块停止
    void stop();

    // 擦除满行
    void erase();

    // 擦除完上面的图形整块坠落
    void down(int level);

    void showscore(int num);

    void showtime();


    // 用方块数组给面板数组赋值
    //魏斐洋

    //设置棋盘
    bool setPenal();

    //展示棋盘
    void showpanel();

    bool erasePenal();

    bool gameOver();

    bool haveblock();

    void gameview(panel p);

    


};


#endif