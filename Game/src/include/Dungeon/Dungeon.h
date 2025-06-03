#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>
#include "Room.h"

class Dungeon {
    int difficultyLevel;
    int currentRoomIndex;

public:
    explicit Dungeon(int level = 1);
    std::vector<Room> rooms;
    void generate(int roomCount);
    Room& getCurrentRoom();
    bool moveToNextRoom();
    bool isComplete() const;
    int getDifficulty() const { return difficultyLevel; }
};

#endif