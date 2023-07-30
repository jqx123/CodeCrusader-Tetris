class game
{

public:
    game();
    ~game();
    // 游戏的入口函数，点击运行程序后被调用的程序
    void play();
    // 游戏的运行规则，点击开始游戏后的逻辑
    void startgame();
    // 游戏的设置界面逻辑
    void setting();

    // 退出游戏逻辑
    void exitgame();

    // 初始化游戏参数，包括绘出panel，准备随机方块，画出最高分，画出现有分0
    void init();
    // 更新界面,更新init的所有项
    void updateWindow();

    // 以下函数更新界面专用
    //  画出分数
    void drawScore();
    // 更新最高分
    void updateHighestScore();

    // 死亡界面
    void gameover();
    // 游戏结束或暂停的返回界面
    void pauseorover();
    //更新游戏难度
    void updateDiff(int difficulty);
};