#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "Dungeon.h"

class Room : public Dungeon
{
    public:
    bool isEnemy;
    bool isTreasure;

    Room(bool isEnemy, bool isTreasure, int level);

    void addEnemy();
    void addTreasure();

    ~Room() = default;
};



#endif