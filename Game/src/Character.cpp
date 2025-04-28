#include "Character.h"
#include <iostream>


Character::Character(int attack, int defence, std::string name, int health) : Entity (name, health) {}

void Character::defend()
{
    std::cout << "Вы встали в защитную стойку! Урон снижен" << std::endl;
    defence *= 2;
}

void Character::attackTarget()
{
    std::cout << "Атакуем противника! Нанося: " << attack << "урона" << std::endl; 
}