#ifndef CUBEPOINT_H_
#define CUBEPOINT_H_
#include <graphics.h>
#include "common.h"


/*
 * 显示面板我们看作是很多方形的小点组成
 * 每个点显然有个坐标值
 * 每个点有一个颜色
 */
class CubePoint{
public:
	int color;
	int x;
	int y; //每个方格点有颜色属性，坐标属性


	IMAGE i0;
	IMAGE i1;
	IMAGE i2;
	IMAGE i3;
	IMAGE i4;
	IMAGE i5;
	IMAGE i6;
	IMAGE i7;
	IMAGE i8;
	IMAGE i9;

	IMAGE img0;
	IMAGE img1;

	CubePoint()
	{
		loadimage(&img0, _T("res/cube0.png"), 16, 16, true);
		loadimage(&img1, _T("res/cube1.png"), 16, 16, true);
		loadimage(&i0, _T("res/p0.png"), 10, 18, 1);
		loadimage(&i1, _T("res/p1.png"), 10, 18, 1);
		loadimage(&i2, _T("res/p2.png"), 10, 18, 1);
		loadimage(&i3, _T("res/p3.png"), 10, 18, 1);
		loadimage(&i4, _T("res/p4.png"), 10, 18, 1);
		loadimage(&i5, _T("res/p5.png"), 10, 18, 1);	
		loadimage(&i6, _T("res/p6.png"), 10, 18, 1);
		loadimage(&i7, _T("res/p7.png"), 10, 18, 1);
		loadimage(&i8, _T("res/p8.png"), 10, 18, 1);
		loadimage(&i9, _T("res/p9.png"), 10, 18, 1);


		color = CLEAR;
		x = 0;
		y = 0;

	}
	CubePoint(int a,int b,int c)
	{
		loadimage(&img0, _T("res/cube0.png"), 16, 16, true);
		loadimage(&img1, _T("res/cube1.png"), 16, 16, true);

		color = a;
		x = b;
		y = c;

	}
	void setLocate(int x,int y){this->x = x;this->y = y;}
	void setColor(int color){this->color = color;}
	
	int getColor(){return color;}
	void getLocate(int&x,int &y){x = this->x;y = this->y;}
	//打印点的方法
	void printPoint();

	//显示分数
	void printnum(int num);

	//显示时间
	void printtime();


};
#endif

