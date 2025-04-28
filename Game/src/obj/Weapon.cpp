#include <iostream>
#include "Weapon.h"

Weapon::Weapon(std::string name, std::string description, bool isConsumable, int damage, int durability) : Item (name, description, isConsumable) {}


void Weapon::upgrade() 
{
    damage += 10;  
    durability += 5;  
    std::cout << name << " улучшен! Новый урон: " << damage << ", прочность: " << durability << std::endl;
}

    
void Weapon::specialEffect() 
{
    if (isConsumable) {
    std::cout << name << " был использован и исчез!" << std::endl;
    durability = 0;  // Одноразовое оружие ломается после использования
    } else {
    std::cout << name << " испускает магическую волну, нанося дополнительный урон!" << std::endl;
    damage += 5;  
    }
}