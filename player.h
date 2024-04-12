#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <enemy.h>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);

    static int Score;


public slots:
    void MakeEnemy();


};

#endif
