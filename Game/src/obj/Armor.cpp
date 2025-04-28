#include "Armor.h"
#include <iostream>

Armor::Armor(std::string name, std::string description, bool isConsumable, int defence, int stability) 
    : Item(name, description, isConsumable), defence(defence), stability(stability) {}

void Armor::reinforce() {
    if(defence <= 40) {
        defence = stability * 2;
    }
    std::cout << name << " Устойчивость брони увеличена вдвое! " << stability << std::endl;
}

void Armor::absorbDamage(int damage) {
    if(damage <= 5) {
        std::cout << name << " Нет урона!" << damage << std::endl;
    }
}


