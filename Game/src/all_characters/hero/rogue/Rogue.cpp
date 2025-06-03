#include <iostream>
#include <memory>
#include "../../../include/Rogue/Rogue.h"

Rogue::Rogue(int level, int experience, int attack, int defence, std::string name, int health, int stealth, int criticalChance)
    : Hero(level, experience, attack, defence, name, health), stealth(stealth), criticalChance(criticalChance) {}

unsigned int Rogue::sneakAttack(unsigned int baseDamage) {

    if (stealth > 100) stealth = 100;
    if (stealth < 0) stealth = 0;

    std::cout << "Разбойник атакует... \n";
    if (stealth > 75) {
        std::cout << "Идеальный скрытный удар! \n";
        stealth -= 30;
        unsigned int damage = baseDamage * 3;
        std::cout << "Нанесено урона: " << damage << std::endl;
        return damage;
    }

    if (stealth > 40) {
        std::cout << "Скрытная атака. \n";
        stealth -= 20;

        if (rand() % 100 < criticalChance) {
            std::cout << "Критический удар!\n ";
            unsigned int damage = baseDamage * 2;
            std::cout << "Нанесено урона: " << damage << std::endl;
            return damage;
        } else {
            std::cout << "Обычный удар. \n";
            std::cout << "Нанесено урона: " << baseDamage << std::endl;
            return baseDamage;
        }
    }

    std::cout << "Враг заметил вас! \n";
    stealth = 0;
    unsigned int damage = baseDamage / 2;
    std::cout << "Нанесено урона: " << damage << " (атака ослаблена)\n";
    return damage;
}

void Rogue::useScroll(std::unique_ptr<Scroll> _scroll) {
    if (_scroll) {
        std::cout << "Using Scroll: " << _scroll->name << std::endl;
        stealth += _scroll->effect;
        if (stealth > 100) stealth = 100;
    }
}