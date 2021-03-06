#include"enemyMinion.h"
#include<QPixmap>
#include<QObject>
#include<QTimer>
#include<QGraphicsScene>
#include<QVector>
#include<QPointF>
#include<QPolygonF>
#include<QLineF>
#include "Game.h"
#include"Bullet.h"
#include"Minion.h"
extern Game * game;

enemyMinion::enemyMinion(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
   //define hp
    hp = 10;
   //define team
    team = 2;

   //draw pic
    setPixmap(QPixmap(":images/Minion.png"));

   //set  timer
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(200);

   //create a polygon

   QVector<QPointF> points;
   points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
         << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);
   //scale polygon
   int i,n;
   int scale = 60;
   for(i=0,n=points.size();i<n;i++){
       points[i]=points[i]*scale;
   }

   //create polygonitem
   attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);

   //match polygon and minion
   QPointF poly_center(1.5,1.5);
   poly_center = poly_center * scale;
   poly_center = mapToScene(poly_center);
   QPointF Minion_center(x()+28,y()+40);
   QLineF ln(poly_center,Minion_center);
   attack_area->setPos(x()+ln.dx(),y()+ln.dy());


   }



void enemyMinion::hpdecreace()
{
    hp--;
}



void enemyMinion::move(){

     setPos(x()-10,y());

     if (pos().x()< 0||pos().y()>800){
             scene()->removeItem(this);
             delete this;

         }

     //attacked

     if(this->collidesWithItem(bullet)){
         hpdecreace();
        }
     //dead
     if(hp == 0){
         scene()->removeItem(this);
         delete this;
     }
     }



