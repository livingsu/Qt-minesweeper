#ifndef MYITEM_H
#define MYITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QStyleOptionGraphicsItem>

class myItem : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    myItem();
    void setRowAndCol(int x,int y){row=x;col=y;}
    void setSweeped(bool s){sweeped=s;updateItem();}//模拟点击
    void setMine(bool m){mine=m;}
    void setNumOfMines(int n){numOfMines=n;}
    void setMark(bool m){mark=m;updateItem();}
    void setStepMine(bool s){stepMine=s;}
    bool isSweeped(){return sweeped;}
    bool isMine(){return mine;}
    bool isMarked(){return mark;}
    int getNumOfMines(){return numOfMines;}
    void simulateLeftClick();//模拟左键点击
    void updateItem();//更新显示

protected:
     void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

signals:
     void stepOnMine(int r,int c);//挖到了雷
     void stepOnNone(int r,int c);//挖到没有雷的地方
     void doubleClickSignal(int r,int c);//左右键双击有效
     void checkSignal();//每次点击后，发送信号给myscene检查游戏是否结束
     void markChangedSignal();//标记改变信号,用来numScene改变剩余地雷数

private:
     int row;
     int col;
     bool sweeped=false;//是否已经挖掘
     bool mine=false;//有无地雷
     bool mark=false;//有无旗子标记
     bool stepMine=false;//是否踩雷
     int numOfMines=0;//周围地雷个数
};

#endif // MYITEM_H
