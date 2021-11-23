#ifndef NUMSCENE_H
#define NUMSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "numitem.h"

class numScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit numScene(QObject *parent = nullptr);
    void setNumer(int num);//设置显示数字

signals:

public slots:

};

#endif // NUMSCENE_H
