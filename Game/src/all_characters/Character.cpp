#include <iostream>
#include "Character.h"

Character::Character(std::string name, int health, Attack attack, Defence defence) : name(name), health(health), attack(attack), defence(defence) {}


void Character::takeDamage(int damage) {
    health -= damage;
    std::cout << name << " получает " << damage << " урона. ";
    if (health <= 0) {
        health = 0;
        std::cout << name << " повержен!\n";
    } else {
        std::cout << "Осталось здоровья: " << health << "\n";
    }
}
void Character::defend() {

}
void Character::attackTarget(Enemy &) {

}




void Character::displayInfo() const {
    std::cout << "\n=== " << name << " ===\n"
              << "Здоровье: " << health << "\n"
              << "Атака: " << attack.name << " (урон: " << attack.damage << ")\n"
              << "Защита: " << defence.name << "\n\n";
}