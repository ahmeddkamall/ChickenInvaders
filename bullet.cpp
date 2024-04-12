#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>

Bullet::Bullet():QObject(), QGraphicsPixmapItem() {

    // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    QPixmap pixmap(":/new/prefix1/laser.png");
    QPixmap Pixmap = pixmap.scaled(10, 50, Qt::KeepAspectRatio);
    setPixmap(Pixmap);
}
void Bullet:: move()
{
    setPos(x(), y()-10);
    if (pos().y() + pixmap().height() < 0) {
        scene() -> removeItem(this);
        delete this;
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            scene() -> removeItem(colliding_items[i]);
            scene() -> removeItem(this);
            Player::Score += 1;
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}
