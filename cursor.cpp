#include "cursor.h"
#include<iostream>
using namespace std;

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


// //测试代码
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
