#include "../include/Dungeon/Dungeon.h"
#include "../include/Enemy/Enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

Dungeon::Dungeon(int level)
    : difficultyLevel(std::max(1, level)),
      currentRoomIndex(0) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Dungeon::generate(int roomCount) {
    rooms.clear();
    rooms.reserve(static_cast<size_t>(roomCount));
    std::srand(static_cast<unsigned>(std::time(nullptr)));


    const std::vector<std::string> monsterNames = {
        "Гоблин", "Орк", "Скелет", "Тролль",
        "Паук", "Зомби", "Волк", "Демон"
    };

    for (int i = 0; i < roomCount; ++i) {
        Room room;


        if (std::rand() % 100 < 70) {
            int baseHealth = 20 + difficultyLevel * 10;
            int baseAttack = 5 + difficultyLevel * 3;


            std::string name = monsterNames[std::rand() % monsterNames.size()];


            int monsterType = std::rand() % 3;


            switch (monsterType) {
                case 0:
                    break;
                case 1:
                    baseHealth = static_cast<int>(baseHealth * 1.5f);
                    baseAttack = static_cast<int>(baseAttack * 0.8f);
                    name = "Бронированный " + name;
                    break;
                case 2:
                    baseHealth = static_cast<int>(baseHealth * 0.7f);
                    baseAttack = static_cast<int>(baseAttack * 1.4f);
                    name = "Яростный " + name;
                    break;
            }


            if (baseAttack > 15) {
                baseAttack = 15;
            }
            auto enemy = std::make_unique<Enemy>(
                name,
                baseHealth,
                baseAttack,
                0,
                baseAttack
            );

            room.addEnemy(std::move(enemy));
        }

        rooms.push_back(std::move(room));
    }
}
Room& Dungeon::getCurrentRoom() {
    return rooms[static_cast<size_t>(currentRoomIndex)];
}

bool Dungeon::moveToNextRoom() {
    if (static_cast<size_t>(currentRoomIndex + 1) < rooms.size()) {
        currentRoomIndex++;
        return true;
    }
    return false;
}

bool Dungeon::isComplete() const {
    return static_cast<size_t>(currentRoomIndex) >= rooms.size() - 1;
}

