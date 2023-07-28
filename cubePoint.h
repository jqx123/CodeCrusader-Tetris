#ifndef CUBEPOINT_H_
#define CUBEPOINT_H_

#include<iostream>
using namespace std;
enum color{
	CLEAR = 0,
	BLACK = 30,
};

/*
 * 显示面板我们看作是很多方形的小点组成
 * 每个点显然有个坐标值
 * 每个点有一个颜色
 * 这种思维来设计更为合理
 */
class CubePoint{
public:
	int color;
	int x;
	int y; //每个方格点有颜色属性，坐标属性

	CubePoint()
	{
		color = CLEAR;
		x = 0;
		y = 0;
	}
	CubePoint(int a,int b,int c)
	{
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
};
#endif

