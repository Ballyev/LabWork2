#include <iostream>
#include "../include/obj/Weapon.h"

Weapon::Weapon(std::string name, std::string description, bool isConsumable, int damage, int durability) : Item(
    name, description, isConsumable), damage(damage), durability(durability) {
}

void Weapon::upgrade() {
    damage += 10;
    durability += 5;
    std::cout << name << " улучшен! Новый урон: " << damage << ", прочность: " << durability << std::endl;
}

void Weapon::specialEffect() {
    if (isConsumable) {
        std::cout << "'"<< name << "' было использовано и исчезло!" << std::endl;
        durability = 0;
    } else {
        std::cout << name << " испускает магическую волну, нанося дополнительный урон!" << std::endl;
        damage += 5;
    }
}

