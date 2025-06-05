#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>
#include <memory>

class Enemy;

class Room {
public:
    bool hasEnemy;
    std::vector<std::unique_ptr<Enemy>> enemies;

    Room();

    void addEnemy(std::unique_ptr<Enemy> enemy);
    void clearRoom();
    void printInfo() const;
    bool hasAliveEnemies() const;
};

#endif