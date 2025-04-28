#include "Entity.h"
#include <iostream>

Entity::Entity(std::string name, int health) 
    : name(std::move(name)), health(health) {}

void Entity::setAttack(std::unique_ptr<Attack> attack) {
    currentAttack = std::move(attack);
    std::cout << "Установлена атака: " << currentAttack->name << "\n";
}

void Entity::setDefence(std::unique_ptr<Defence> defence) {
    currentDefence = std::move(defence);
    std::cout << "Установлена защита: " << currentDefence->name << "\n";
}

void Entity::performAttack() {
    if (currentAttack) {
        currentAttack->comboAttack();
    } else {
        std::cout << "Нет атаки!\n";
    }
}

void Entity::activateDefence() {
    if (currentDefence) {
        currentDefence->shieldBlock();
    } else {
        std::cout << "Нет защиты!\n";
    }
}

void Entity::takeDamage(int damage) {
    health -= damage;
    std::cout << name << " получил " << damage << " урона. Здоровье: " << health << "\n";
}

void Entity::displayInfo() const {
    std::cout << name << " (HP: " << health << ")\n";
    std::cout << "Атака: " << (currentAttack ? currentAttack->name : "Нет") << "\n";
    std::cout << "Защита: " << (currentDefence ? currentDefence->name : "Нет") << "\n";
}

