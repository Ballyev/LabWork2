#ifndef DUNGEON_H
#define DUNGEON_H
#include <iostream>

class Dungeon
{
    public:
    int level;
   
    
    Dungeon(int level);
    
    void generateLevel();
    void spawnBoss() const;

    ~Dungeon() = default;

};

#endif