#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include "Game.h"
#include <QLine>
#include <QList>
#include "enemyMinion.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    // set graphics
    setPixmap(QPixmap(":images/bullet.png"));


    // connect a timer to move()
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);

}








void Bullet::move(){
    double slope = 10;
    double theta = rotation();
    double dy = slope * qSin(qDegreesToRadians(theta));
      double dx = slope * qCos(qDegreesToRadians(theta));
      this ->setPos(x()+dx,y()+dy);

      //delete after collide with enemy
      QList <QGraphicsItem*>coenemy = this -> collidingItems();
      int a = coenemy.size();
      for(int i = 0;i<a;i++){
          if(typeid(*(coenemy[i])) == typeid(enemyMinion)){
              scene() -> removeItem(this);
              delete this;

          }
      }

}
