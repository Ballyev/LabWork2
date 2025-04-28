#include "Dungeon.h"
#include <iostream>

Dungeon::Dungeon(int level) : level(level) {}

void Dungeon::generateLevel() {
        level = rand() % 10 + 1;  // Генерируем уровень от 1 до 10
        std::cout << "Сгенерировано подземелье уровня: " << level << "!\n";
    }

    // Метод для спауна босса
    void Dungeon::spawnBoss() {
        if (level < 5) {
            std::cout << "Появился слабый босс!\n";
        } else if (level < 8) {
            std::cout << "Появился средний босс!\n";
        } else {
            std::cout << "Появился мощный босс!\n";
        }
    }