#include <iostream>
#include "../../../include/Mage/Mage.h"
#include <algorithm>
#include "../../../include/Skills/Magic.h"

Mage::Mage(int level, int experience, int attack, int defence, std::string name, int health, int mana, int spellPower)
    : Hero(level, experience, attack, defence, name, health), mana(mana), spellPower(spellPower) {}

void Mage::heal()
{
    if (mana >= 1 && health < 100 ) {
    health += 10;
    mana -= 1;
    if (health > 100) {
    health = 100;
    }
    std::cout << "Здоровье увеличилось: " << health << std::endl;
    } else {
    std::cout << "Недостаточно маны или здоровье уже полное!" << std::endl;
    }
}

void Mage::usePotion(Potion* potion, Enemy& target) {
    if (!potion) {
        std::cout << "Ошибка: зелье не найдено!\n";
        return;
    }

    std::cout << name << " бросает зелье в " << target.name << "!\n";
    target.takeDamage(potion->attackPower);
    std::cout << "Нанесено урона: " << potion->attackPower << "\n";

    if (target.health <= 0) {
        std::cout << target.name << " повержен!\n";
    }
}