#include<iostream>
using namespace std;

class Cursor{
public:
		void saveCur();				//保存光标位置
		void moveCur(const int x,const int y);	//移动光标位置到（x,y）坐标
		void resumeCur();			//恢复光标位置
};


void Cursor::moveCur(const int x,const int y)
{
	int i;
	for(i = 0; i < y; i++)
		printf("\33[2C");
	for(i = 0; i < x; i++)
		printf("\33[1B");
}
void Cursor::saveCur()
{
	//save cur and move to destination
	printf("\33[s");	
}
void Cursor::resumeCur()
{
	printf("\33[u");
}


//测试代码
// int main(int argc,char *argv[])
// {
// 	Cursor cur;
// 	system("clear");
// 	cur.saveCur();
// 	cur.moveCur(10,9);
// 	printf("a");
// 	cur.resumeCur();
// 	return 0;
// }
