#include "block.h"
#include "cubePoint.h"
#define DOWN 0
#define LEFT 1
#define RIGHT 2

// 画出block
void AbstractBlock::showblock(int color)
{
    int i,j;
    CubePoint p;
    for(i = x-1; i < x+3; i++)
        for(j = y-1; j < y+3; j++)
        {
            if(bk[i - x][j - y] == 1)
            {
                p.setLocate(i,j);
                p.setColor(color);
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
        y++;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    default:
        break;
    }
    return 0;
}

// 旋转block
int AbstractBlock::rotate()
{
    int i,j;
    int temp[4][4];
     for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
        {
            temp[2-j][i] = bk[i][j];
        }
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
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
