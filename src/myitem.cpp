#include "myitem.h"

myItem::myItem()
{
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setAcceptedMouseButtons(Qt::AllButtons);

    updateItem();
}

void myItem::simulateLeftClick(){
    if(!sweeped&&!mark){
        setSweeped(true);
        if(mine){
            stepMine=true;
            updateItem();
            emit stepOnMine(row,col);
        }
        else if(numOfMines==0)emit stepOnNone(row,col);
    }

}

void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<"Click detected at:"<<row<<","<<col;
//    qDebug()<<event->button();
//    qDebug()<<event->buttons();

    if(event->buttons()==(Qt::LeftButton|Qt::RightButton)){
        qDebug()<<"|-> Left and right click";
        if((sweeped&&numOfMines!=0)||(!sweeped&&mark)){//已被挖掘且有数字/未挖掘被标记
            emit doubleClickSignal(row,col);
        }

    }else if(event->button()==Qt::LeftButton){//左键点击
        qDebug()<<"|-> Left click";
        simulateLeftClick();
    }else if(event->button()==Qt::RightButton){
        qDebug()<<"|-> Right click";
        if(!sweeped){
            setMark(!mark);

            qDebug()<<"Mark changed!";
            emit markChangedSignal();

        }
    }
    emit checkSignal();
}

void myItem::updateItem(){
    if(stepMine)this->setPixmap(QPixmap(":/mine/pic/mine_step.png"));
    else if(!sweeped){
        if(!mark)this->setPixmap(QPixmap(":/mine/pic/notSweep.png"));
        else this->setPixmap(QPixmap(":/mine/pic/flag.png"));
    }
    else if(mine){
        this->setPixmap(QPixmap(":/mine/pic/mine.png"));
    }else{
         if(numOfMines==0)this->setPixmap(QPixmap(":/mine/pic/mine0.png"));
         else if(numOfMines==1)this->setPixmap(QPixmap(":/mine/pic/mine1.png"));
         else if(numOfMines==2)this->setPixmap(QPixmap(":/mine/pic/mine2.png"));
         else if(numOfMines==3)this->setPixmap(QPixmap(":/mine/pic/mine3.png"));
         else if(numOfMines==4)this->setPixmap(QPixmap(":/mine/pic/mine4.png"));
         else if(numOfMines==5)this->setPixmap(QPixmap(":/mine/pic/mine5.png"));
         else if(numOfMines==6)this->setPixmap(QPixmap(":/mine/pic/mine6.png"));
         else if(numOfMines==7)this->setPixmap(QPixmap(":/mine/pic/mine7.png"));
         else if(numOfMines==8)this->setPixmap(QPixmap(":/mine/pic/mine8.png"));
    }
}

void myItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QStyleOptionGraphicsItem op;
    op.initFrom(widget);
    op.state = QStyle::State_None;

    return QGraphicsPixmapItem::paint(painter, &op, widget);
}
