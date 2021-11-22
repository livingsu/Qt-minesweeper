//显示单个数字
#ifndef NUMITEM_H
#define NUMITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class numItem : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    numItem();
    void setNum(int a);

signals:

public slots:
};

#endif // NUMITEM_H
