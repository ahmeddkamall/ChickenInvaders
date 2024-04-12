#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include "enemy.h"
#include <enemy.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView *view =new QGraphicsView();
    view->setFixedSize(800, 600);
    QGraphicsScene *Scene = new QGraphicsScene();
    Scene->setSceneRect(0, 0, 800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QGraphicsTextItem * score = new QGraphicsTextItem;
    score-> setFont(QFont("times", 16));
    score-> setDefaultTextColor(Qt::white);
    score->setPlainText("Score: " + QString::number(Player::Score));
    score -> setPos(700, 10);
    Scene->addItem(score);
    Player * player = new Player;
    player -> setPos(view -> width()/2, view -> height() - player -> pixmap().height());
    Scene->addItem(player);
    player -> setFlag(QGraphicsItem::ItemIsFocusable);
    player -> setFocus();
    view->setScene(Scene);
    view->show();
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(MakeEnemy()));
    time->start(2000);


    return a.exec();
}
