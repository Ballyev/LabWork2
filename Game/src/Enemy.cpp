#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int reward, int attack, int defence, std::string name, int health, int attackPower) : Character(attack, defence, name, health) {}

void Enemy::roar() const {
    std::cout << "RAWWWR! Attack power: " << attack << std::endl;
}

