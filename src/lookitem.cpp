#include "lookitem.h"

lookItem::lookItem()
{
    setLook();
}
void lookItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    setLook();
    emit restart();
}
void lookItem::setLook(int type){
    if(type==0)this->setPixmap(QPixmap(":/look/pic/happy.png"));
    else if(type==1)this->setPixmap(QPixmap(":/look/pic/unhappy.png"));
    else if(type==2)this->setPixmap(QPixmap(":/look/pic/victory.png"));
}
