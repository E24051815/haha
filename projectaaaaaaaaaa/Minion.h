#ifndef MINION_H
#define MINION_H

#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>

class Minion : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT


public:
    Minion(QGraphicsItem * parent=0);
    QGraphicsPolygonItem *attack_area;
    bool has;
    int team;
    void attack();
    QPointF target;


public slots:
    void move();




};

#endif // MINION_H
