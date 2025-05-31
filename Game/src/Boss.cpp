#include <iostream>
#include "Boss.h"
#include <vector>

Boss::Boss(int reward, int attack, int defence, std::string name, int health, int phase, bool isEnraged) : Enemy (reward, attack, defence, name, health) {}

void Boss::summonMinions(int count) 
{
    std::cout << name << " призывает " << count << " миньонов!\n";
    for (int i = 1; i <= count; ++i) 
    {
        minions.push_back("Миньон #" + std::to_string(i));
    }
}

void Boss::ultimateAbility(bool isEnraged) {
    if (isEnraged || health < 50) {  
        attack *= 2; 
        std::cout << "Ярость! Увеличена атака!!! Теперь атака: " << attack << std::endl;
    } else {
        std::cout << "Условия для ярости не выполнены" << std::endl;
    }
}