#include "Room.h"
#include "../Enemy.h"
Room::Room() = default;

void Room::addEnemy(std::unique_ptr<Enemy> enemy) {
    if (enemy) {
        enemies.push_back(std::move(enemy));
        hasEnemy = true;
    }
}

void Room::clearRoom() {
    enemies.clear();
    hasEnemy = false;
}

bool Room::hasAliveEnemies() const {
    for (const auto& enemy : enemies) {
        if (enemy->isAlive()) return true;
    }
    return false;
}

void Room::printInfo() const {
    std::cout << "\n=== Комната ===\n";
    if (hasEnemy && !enemies.empty()) {
        std::cout << "Врагов: " << enemies.size() << "\n";
        for (const auto& enemy : enemies) {
            std::cout << "- " << enemy->name << " (HP: " << enemy->health << ")\n";
        }
    } else {
        std::cout << "Врагов: нет\n";
    }
}