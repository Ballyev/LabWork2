#include "../../include/Hero/Hero.h"
#include <iostream>

Hero::Hero(int level, int experience, int attack, int defence, std::string name, int health)
    : Character(name, health, attack, defence), level(level), experience(experience) {}
void Hero::levelUp() {
    std::cout << "Checking level up... ";
    int expNeeded = level * 50;

    if (experience >= expNeeded) {
        level += 1;
        experience = 0;
        attack += 3;
        defence += 2;
        std::cout << "Level up! New level: " << level
                  << ", attack: " << attack
                  << ", defence: " << defence
                  << ", remaining exp: " << experience << std::endl;
    } else {
        std::cout << "Not enough experience. Need " << (expNeeded - experience)
                  << " more exp for level " << (level + 1) << std::endl;
    }
}

void Hero::equipWeapon(Weapon *_weapon) {
    if (!Gun) {
        Gun = _weapon;
        attack += _weapon->damage;
    }else {
        attack -= Gun->damage;
        itemSector.push_back(std::make_unique<Item>(*Gun));
        Gun = _weapon;
        attack += Gun->damage;
    }
}
    void Hero::gainExperience(int amount) {
        experience += amount;
        std::cout << name << " получает " << amount << " опыта. Текущий опыт: " << experience << "\n";
    }

void Hero::endTurn() {
    for (auto& skill : skills) {
        skill->updateCooldown();
    }
}
