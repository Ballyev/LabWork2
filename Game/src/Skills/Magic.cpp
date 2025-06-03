#include "../include/Skills/Magic.h"
#include <iostream>

Magic::Magic(std::string name, std::string description, int cooldown, bool isActive, int manaCost, int damage, int currentCooldown) : Skills (name, description, cooldown, isActive, currentCooldown), manaCost(manaCost), damage(damage) {}

void Magic::singleTargetDamage(Enemy* target) {
    if (!target || !target->isAlive()) {
        std::cout << "Цель недоступна для заклинания.\n";
        return;
    }

    target->takeDamage(damage);
    std::cout << name << " наносит урон " << damage << " по " << target->name << ".\n";

    currentCooldown = cooldown;
    isActive = false;
}

void Magic::update() {
    if (currentCooldown > 0) {
        currentCooldown--;
        if (currentCooldown == 0) {
            isActive = true;
            std::cout << name << " готово к использованию!\n";
        }
    }
}

void Magic::debuff(Enemy& target_enemy) {
    if (isActive == true) {
        target_enemy.attackPower /= 2;
        std::cout << name << " снижает силу атаки " << target_enemy.name << "!\n";
        isActive = false;
    }else{
        std::cout << "Способность уже использована\n";
    }
}