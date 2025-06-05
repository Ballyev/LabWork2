#include <iostream>
#include "../include/Character/Character.h"
#include "../include/Enemy/Enemy.h"

Character::Character(std::string name, int health, int attack, int defence) : name(name), health(health), attack(attack), defence(defence) {}


void Character::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        health = 0;
        std::cout << name << " повержен!" << std::endl;
    } else {
        std::cout << name << " получает " << damage << " урона. Осталось HP: " << health << std::endl;
    }
}

void Character::defend(int currentDefendCooldown, int originalDefence) {
    if (currentDefendCooldown > 0) {
        currentDefendCooldown--;

        if (currentDefendCooldown == 0) {
            defence = originalDefence;
            std::cout << name << " выходит из защитной стойки.\n";
        }
    }
    if (currentDefendCooldown > 0) {
        std::cout << name << " ещё не готов использовать защитную стойку. "
                  << "Осталось ходов: " << currentDefendCooldown << "\n";
        return;
    }
    originalDefence = defence;
    defence += defence / 2;
    currentDefendCooldown = 2;

    std::cout << name << " принимает защитную стойку!\n"
              << "Защита увеличена с " << originalDefence
              << " до " << defence << ".\n";
}

void Character::attackTarget(Enemy& enemy) {
    int damage = attack;
    std::cout << name << " атакует " << enemy.name << " и наносит "
              << damage << " урона!\n";
    enemy.takeDamage(damage);

    if (enemy.health <= 0) {
        std::cout << name << " не может атаковать - враг уже повержен!\n";
    }
}

void Character::displayInfo() const {
    std::cout << "\n=== " << name << " ===\n"
              << "Здоровье: " << health << "\n"
              << "Атака: " << attack << "\n"
              << "Защита: " << defence << "\n";
}