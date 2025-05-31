#include "Attack.h"
#include <iostream>
#include "../all_characters/hero/Hero.h"

Attack::Attack(int damageMultiplier, std::string name, std::string description, int cooldown, bool isActive, int baseDamage) : Skills (name, description, cooldown, isActive) {}

void Attack::comboAttack() {
    if (isActive) {
        int comboDamage =  damageMultiplier * 2;
        std::cout << "Combo attack! Damage: " << comboDamage << std::endl;
        cooldown += 1;
    } else {
        std::cout << "Attack is not active!" << std::endl;
    }
}

void Attack::criticalHit(Enemy& target) {
    if (!isActive) {
        std::cout << "Способность не готова к использованию!\n";
        return;
    }
    if (currentCooldown > 0) {
        std::cout << "Перезарядка: " << currentCooldown << " ходов\n";
        return;
    }
    if (rand() % 100 < 30) {
        int criticalDamage = baseDamage * 2;
        target.takeDamage(criticalDamage);
        std::cout << "Критический удар! Нанесено " << criticalDamage << " урона\n";
    } else {
        target.takeDamage(baseDamage);
        std::cout << "Обычный удар. Нанесено " << baseDamage << " урона\n";
    }
    isActive = false;
    currentCooldown = 3;
}