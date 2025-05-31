#include "Warrior.h"
#include <iostream>

Warrior::Warrior(std::string name, int level, int experience, int attack, int defence, int health, int rage)
    : Hero(level, experience, attack, defence, name, health), rage(rage) {}

void Warrior::rage() {
    if (health <= 50 && rage >= 20) {
        std::cout << "Воин пришел в ярость: Aaaa! Урон усилен.\n";
        rage -= 20;
        attack += 10;
    } else {
        std::cout << "Воину не хватает ярости!\n";
    }
}

    void Warrior::powerStrike(unsigned int baseDamage) {
    if (level >= 2 && rage >= 10) {
        std::cout << "Воин выполняет мощный удар!" << baseDamage * 2 << std::endl;
        rage -= 10;
    }
    std::cout << "Недостаточно ярости или уровня!" << baseDamage << std::endl;
}

void Warrior::equipArmor(std::unique_ptr<Armor> _armor) {
    if (!_armor) return;

    defence += _armor->defence;
    std::cout << "Броня надета! +" << _armor->defence << " защиты.\n";

    if (_armor->stability == 0) {
        std::cout << "Броня упала!\n";
    }
}
