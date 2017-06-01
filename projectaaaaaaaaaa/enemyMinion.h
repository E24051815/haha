#ifndef ENEMYMINION_H
#define ENEMYMINION_H
#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
#include"Bullet.h"

class enemyMinion : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT


public:
    enemyMinion(QGraphicsItem * parent=0);
    QGraphicsPolygonItem *attack_area;
    int team;
    int hp;
    void hpdecreace();
public slots:
    void move();

};
#endif // ENEMYMINION_H
