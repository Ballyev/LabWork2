#include "Magic.h"
#include <iostream>

Magic::Magic(std::string name, std::string description, int cooldown, bool isActive, int manaCost, int areaOfEffect) : Skills (name, description, cooldown, isActive) {}

void Magic::aoeDamage() {
    if (isActive) {
        std::cout << name << " casts an AoE damage spell! Affects " << areaOfEffect << " units." << std::endl; // почему то areOfEffect
        cooldown += 2; // Увеличиваем кулдаун после массовой атаки
        manaCost += 10; // Расход маны
    } else {
        std::cout << "Magic is not active!" << std::endl;
    }
}

void Magic::debuff() {
    if (isActive) {
        std::cout << name << " casts a debuff spell! Reducing enemy effectiveness." << std::endl;
        cooldown += 1; // Увеличиваем кулдаун
        manaCost += 5; // Расход маны
    } else {
        std::cout << "Magic is not active!" << std::endl;
    }
}