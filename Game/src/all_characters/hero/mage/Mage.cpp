#include <iostream>
#include "Mage.h"
#include <algorithm>

Mage::Mage(int level, int experience, int attack, int defence, std::string name, int health, int mana, int spellPower)
    : Hero(level, experience, attack, defence, name, health), mana(mana), spellPower(spellPower) {}

void Mage::heal() {
    if (mana >= 1 && health <= 90 ) {
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
void Mage::usePotion(const Potion* potion) {
    if (!potion) {
        std::cout << "Ошибка: зелье не существует!" << std::endl;
        return;
    }
    health += potion->healingPower;
    if (health > 100) {
    health = 100;
}
}
