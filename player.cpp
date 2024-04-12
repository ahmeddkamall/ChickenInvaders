#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"

int Player::Score = 0;

Player::Player() : QGraphicsPixmapItem() {
    QPixmap pixmap(":/new/prefix1/plane.png");
    QPixmap Pixmap = pixmap.scaled(100, 500, Qt::KeepAspectRatio);
    setPixmap(Pixmap);
}


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0)
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800)
            setPos(x()+10,y());
    }



    else if(event->key()== Qt::Key_Space)
    {

        Bullet * bullet = new Bullet();
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);

    }
}

void Player::MakeEnemy() {
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}


