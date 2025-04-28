#include <iostream>
#include "Room.h"

Room::Room(bool isEnemy, bool isTreasure, int level) : Dungeon(level) {}


void Room::addEnemy() {
        if (!isEnemy) {
            isEnemy = true;
            std::cout << "В комнате появился враг!\n";
        } else {
            std::cout << "В комнате никого нет.\n";
        }
    }

    void Room::addTreasure() {
        if (!isTreasure) {
            isTreasure = true;
            std::cout << "В комнате есть сокровище!\n";
        } else {
            std::cout << "В комнате нет сокровищь.\n";
        }
    }