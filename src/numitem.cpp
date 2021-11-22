#include "numitem.h"

numItem::numItem(){
    this->setPixmap(QPixmap(":/num/pic/num0.png"));
}

void numItem::setNum(int a){
    if(a==0)this->setPixmap(QPixmap(":/num/pic/num0.png"));
    else if(a==1)this->setPixmap(QPixmap(":/num/pic/num1.png"));
    else if(a==2)this->setPixmap(QPixmap(":/num/pic/num2.png"));
    else if(a==3)this->setPixmap(QPixmap(":/num/pic/num3.png"));
    else if(a==4)this->setPixmap(QPixmap(":/num/pic/num4.png"));
    else if(a==5)this->setPixmap(QPixmap(":/num/pic/num5.png"));
    else if(a==6)this->setPixmap(QPixmap(":/num/pic/num6.png"));
    else if(a==7)this->setPixmap(QPixmap(":/num/pic/num7.png"));
    else if(a==8)this->setPixmap(QPixmap(":/num/pic/num8.png"));
    else if(a==9)this->setPixmap(QPixmap(":/num/pic/num9.png"));
}
