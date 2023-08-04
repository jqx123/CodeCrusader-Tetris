#include "block.h"
#include "cubePoint.h"
#define DOWN 0
#define LEFT 1
#define RIGHT 2

// 画出block
void AbstractBlock::showblock()
{
    int i,j;
    CubePoint p;
    //int size = 16;//图片大小
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
        {
            if(bk[i][j] == 1)
            {
                p.setLocate(xbase+ (y + j) * cube_size,ybase+ (x + i) * cube_size);
                p.setColor(BLACK);
                p.printPoint();
            }
        }
}

// 画出block
void AbstractBlock::shownextblock()
{
    int i, j;
    CubePoint p;
    //int size = 16;//图片大小
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            if (bk[i][j] == 1)
            {
                p.setLocate(301 + (y + j) * cube_size, 290 + (x + i) * cube_size);
                p.setColor(BLACK);
                p.printPoint();
            }
            else {
                p.setLocate(301 + (y + j) * cube_size, 290 + (x + i) * cube_size);
                p.setColor(CLEAR);
                p.printPoint();
            }
        }
}

// 移动block
int AbstractBlock::move(int dir)
{
    switch (dir)
    {
    case DOWN:
        x++;
        break;
    case LEFT:
        y--;
        break;
    case RIGHT:
        y++;
        break;
    default:
        break;
    }
    return 0;
}

// 旋转block
void AbstractBlock::rotate()
{
    int i,j;
    int temp[4][4] = { 0 };
    
     for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            temp[j][2 - i] = bk[i][j];
        }
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            bk[i][j] = temp[i][j];
        }
}

// int main(){
//     BlockFactory *block = new BlockFactory("LongBlock");
//     block->shape();
//     int *num = (int*)block->getArray();
//     printf("%d",num[3]);
// }
