#include "../include/Enemy/Enemy.h"
#include <iostream>
#include "../include/Character/Character.h"

Enemy::Enemy(std::string name, int health, int attack, int defence, int attackPower) : Character(name, health, attack, defence), attackPower(attackPower) {}


void Enemy::attack_hero(Hero& target) {
    std::cout << name << " атакует " << target.name << "!" << std::endl;
    target.takeDamage(attack);
}

void Enemy::takeDamage(int damage) {
    health -= damage;
    std::cout << name << " получает " << damage << " урона. Осталось HP: " << health << std::endl;
    if(health <= 0) {
        health = 0;
        std::cout << name << " повержен!" << std::endl;
    }
}
bool Enemy::isAlive() const {
    return health > 0;
}
