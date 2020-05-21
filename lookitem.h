#ifndef LOOKITEM_H
#define LOOKITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class lookItem : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
   lookItem();
   void setLook(int type=0);//type=0:happy,type=1:unhappy,type=2:victory

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
signals:
    void restart();

public slots:
};

#endif // LOOKITEM_H
