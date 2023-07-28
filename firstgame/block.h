#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
using namespace std;
// 这个block类用工厂模式
class AbstractBlock
{
protected:
    int x;
    int y;
    int bk[4][4];
//这里储存了方块状态
public:
    AbstractBlock()
    {
        int i, j;
        x = 0;
        y = 0;
        for (j = 0; j < 3; j++)
            for (i = 0; i < 3; i++)
                bk[i][j] = 0;
    }
    int move(int dir);
    virtual int rotate();
    virtual void shape() {}
    void setLocate(int a, int b)
    {
        x = a;
        y = b;
    }
    void getLocate(int *a, int *b)
    {
        *a = x;
        *b = y;
    }
    void showblock(int color);
    // 获取数组首地址
    void *getArray() { return (void *)bk; }
};

class LongBlock : public AbstractBlock
{
public:
    virtual void shape()
    {
    }
};
class SquareBlock : public AbstractBlock
{
public:
    virtual void shape()
    {
    }
};
class ZBlock : public AbstractBlock
{
public:
    virtual void shape()
    {
    }
};
class SBlock : public AbstractBlock
{
public:
    virtual void shape()
    {
    }
};
class LBlock : public AbstractBlock
{
public:
    virtual void shape()
    {
    }
};
class JBlock : public AbstractBlock
{
public:
    virtual void shape()
    {
    }
};
class TBlock : public AbstractBlock
{
public:
    virtual void shape()
    {
    }
};

// 方块工厂
class BlockFactory
{
protected:
    AbstractBlock *block;

public:
    BlockFactory(string blocks)
    {
        if ("LongBlock" == blocks)
        {
            block = new LongBlock;
        }
        else if ("SquareBlock" == blocks)
        {
            block = new SquareBlock;
        }
        else if ("ZBlock" == blocks)
        {
            block = new ZBlock;
        }
        else if ("SBlock" == blocks)
        {
            block = new SBlock;
        }
        else if ("LBlock" == blocks)
        {
            block = new LBlock;
        }
        else if ("JBlock " == blocks)
        {
            block = new JBlock;
        }
        else if ("TBlock" == blocks)
        {
            block = new TBlock;
        }
        else
        {
            block = NULL;
        }
    }
    ~BlockFactory()
    {
        delete block;
    }
    int move(int dir) { return block->move(dir); }
    int roll() { return block->rotate(); }
    void draw() { block->shape(); }
    void setLocate(int a, int b) { block->setLocate(a, b); }
    void getLocate(int *a, int *b) { block->getLocate(a, b); }
    void *getArray() { block->getArray(); }
    void showblock(int color) { block->showblock(color); }
};

#endif

// void test01()
// {
//     BlockFactory *factory = new BlockFactory;
//     AbstractBlock *block = factory->CreateBlock("TBlock");
//     block->shape();
//     delete block;
//     bloc;
//     block = factory->CreateBlock("TBlock");
//     block->shape();
//     delete block;
//     bloc;
//     delete factory;
//     factory = NULL;
// }

// int main()
// {
//     test01();
//     block= 0;
// }这是测试代码
