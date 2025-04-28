#include <iostream>
#include "Mage.h"
#include <algorithm>

Mage::Mage(int level, int experience, int attack, int defence, std::string name, int health, int mana, int spellPower)
    : Hero(level, experience, attack, defence, name, health), mana(mana), spellPower(spellPower) {}

void Mage::heal() {
    if (mana >= 1) { // maxHealth нужно определить
        health += 10;
        mana -= 1;
        std::cout << "Здоровье увеличилось: " << health << std::endl;
    } else {
        std::cout << "Недостаточно маны или здоровье уже полное!" << std::endl;
    }
}
void Mage::castSpell(const Magic& spell) {
    if (mana >= spell.manaCost) {
        mana -= spell.manaCost;
        health += spell.areaOfEffect * 2;
        std::cout << name << " кастует " << spell.name 
                  << "! Здоровье +" << spell.areaOfEffect * 2 << "\n";
    } 
    else {
        std::cout << "Недостаточно маны!\n";
    }
}
void Mage::usePotion(std::unique_ptr<Potion> potion) {
    if (!potion) {
        std::cout << "Ошибка: зелье не существует!" << std::endl;
        return;
    }
    health += potion->healingPower;  
if (health > 100) {  // Если здоровье больше 100, ограничиваем его
    health = 100;
}
}