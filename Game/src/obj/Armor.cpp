#include "Armor.h"
#include <iostream>

Armor::Armor(const std::string &name, const std::string &description, const bool isConsumable, const int defence, const int stability)
    : Item(name, description, isConsumable), defence(defence), stability(stability) {}

void Armor::reinforce() {
    if(defence <= 40) {
        defence = stability * 2;
    }
    std::cout << name << " Устойчивость брони увеличена вдвое! " << stability << std::endl;
}

void Armor::absorbDamage(int damage) {
    if (damage <= 0) return;

    if (damage <= defence) {
        std::cout << name << ": Броня полностью поглотила урон (" << damage << ")!" << std::endl;
        stability -= 1;
    } else {
        int leftover = damage - defence;
        std::cout << name << ": Броня поглотила " << defence
          << " урона, но " << leftover << " прошел" << std::endl;
        stability -= 2;
    }
    if (stability <= 0) {
        stability = 0;
        std::cout << name << " разрушена!" << std::endl;
        defence = 0;
    }
}


