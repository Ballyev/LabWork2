#include <iostream>
#include <memory>
#include "Rogue.h"

Rogue::Rogue(int level, int experience, int attack, int defence, std::string name, int health, int stealth, int criticalChance)
    : Hero(level, experience, attack, defence, name, health), stealth(stealth), criticalChance(criticalChance) {}

unsigned int Rogue::sneakAttack(unsigned int baseDamage) {
    if (stealth > 100) stealth = 100;

    if (stealth > 75) {
        std::cout << "Идеальный скрытный удар! ";
        stealth -= 30;
        return baseDamage * 3;
    }

    if (stealth > 40) {
        std::cout << "Скрытная атака! ";
        stealth -= 20;
        if (rand() % 100 < criticalChance) {
            std::cout << "Критический удар!\n";
            return baseDamage * 2;
        } else {
            std::cout << "Нанесено урона: " << baseDamage << std::endl;

            return baseDamage;
        }
    }
    std::cout << "Враг вас заметил! ";
    stealth = 0;
    return baseDamage / 2;
}

void Rogue::useScroll(std::unique_ptr<Scroll> _scroll) {
    if (_scroll) {
        std::cout << "Using Scroll: " << _scroll->name << std::endl;
        stealth += _scroll->effect;
        if (stealth > 100) stealth = 100;
    }
}