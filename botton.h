#ifndef BOTTON_H
#define BOTTOM_H
//开始菜单的按钮

//开始游戏
void botton_start(int x,int y,int w,int h);
//游戏设置
void botton_setting(int x,int y,int w,int h);
//关于游戏
void botton_about(int x,int y,int w,int h);
//退出游戏
void botton_exit(int x,int y,int w,int h);


//游戏界面的按钮

//暂停，音效，重玩
void botton_pause(int x,int y,int w,int h);
void botton_voice(int x,int y,int w,int h);
int botton_reset(int x,int y,int w,int h);

//设置界面的按钮
void print_volume(int x1, int y1, int x2, int w, int h, int volume);		//显示音量箭头和当前值，坐标1是左按钮，2是右
void print_level(int x3, int y3, int x4, int w, int h, int level);		//显示难度箭头和当前值，坐标3是左按钮，4是右
void print_menu(int x5, int y5, int w, int h);			//返回菜单按钮

//左右下移，掉落 view
int botton_up(int x, int y, int w, int h);
int botton_moveleft(int x,int y,int w,int h);
int botton_moveright(int x,int y,int w,int h);
int botton_movedown(int x,int y,int w,int h);
int botton_movetobottom(int x,int y,int w,int h);


//关于游戏的按钮

//游戏规则按钮
void botton_aboutrule(int x,int y,int w,int h);
//开发人员按钮
void botton_aboutdevelopers(int x,int y,int w,int h);
#endif