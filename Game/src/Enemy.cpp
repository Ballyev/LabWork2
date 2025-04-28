#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int reward, int attack, int defence, std::string name, int health) : Character(attack, defence, name, health) {}

void Enemy::roar()
{
    std::cout << "RAWWWR! Attack power: " << attack << std::endl;
}

void Enemy::flee()
{
    std::cout << "Running away! Defence: " << defence 
              << ", Reward left: " << reward << std::endl;
}