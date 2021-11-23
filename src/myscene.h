#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QMessageBox>
#include "myitem.h"

class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = nullptr);
    void setMap(int w,int h,int m){width=w;height=h;mine=m;}//设置地图大小和地雷数
    void initialize();//游戏初始化
    int getRestMines();//得到剩余的地雷数

signals:
    void victorySignal(int looktype);
    void gameOverSignal(int looktype);
    void reinitializeSignal(int looktype);
    void markChangedSignal();

public slots:
    void gameOver(int row,int col);//游戏结束
    void findBlocks(int row,int col);//递归寻找无雷区
    void doubleClick(int row,int col);//某处双击
    void checkGame();//检查游戏是否结束
    void markChange(){qDebug()<<"Scene Mark changed!";emit markChangedSignal();}//标记改变,改变剩余地雷数

private:
    static const int MAX_HEIGHT=24;
    static const int MAX_WIDTH=30;

    myItem *items[MAX_WIDTH][MAX_HEIGHT];

    int mine=10;//地雷数
    int height=9;//地图宽高
    int width=9;

};

#endif // MYSCENE_H
