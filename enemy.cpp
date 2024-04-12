#include "enemy.h"
#include "player.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>


Enemy::Enemy() : QGraphicsPixmapItem() {
    // *******  Setting the size of the enemy ********
    QPixmap pixmap(":/new/prefix1/chicken.png");
    QPixmap Pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio);
    setPixmap(Pixmap);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    int number = rand() % 700;
    setPos(number,0);
}

void Enemy::move() {
    setPos(x(), y() + 5);
    if (y() + pixmap().height() > 600) {
        scene()->removeItem(this);

        delete this;
    }
}
