#include "Warrior.h"
#include <iostream>

Warrior::Warrior(std::string name, int level, int experience, int attack, int defence, int health, int rage1)
    : Hero(level, experience, attack, defence, name, health), rage1(rage1) {}

void Warrior::rage(unsigned int rage1)
{
    if(health <= 50)
    {
    std::cout << "Воин пришел в ярость: Aaaa!" << rage1 << std::endl;
    }
    return;
}

void Warrior::powerStrike(unsigned int level)
{
    
    if(level >= 2)
    std::cout << "Мощный урон" << std::endl;

    return;
}
void Warrior::equipArmor(std::unique_ptr<Armor> _armor) {
    defence += _armor->defence;
    std::cout << "Броня надета! " << _armor->defence << std::endl;
    
    if (_armor->stability == 0) {  // Смотрим на стабильность брони
        std::cout << "Броня упала!" << std::endl;
    }
}