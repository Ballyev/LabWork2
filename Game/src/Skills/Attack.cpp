#include "Attack.h"
#include <iostream>
#include "../all_characters/hero/Hero.h"

Attack::Attack(int damageMultiplier, std::string name, std::string description, int cooldown, bool isActive, int baseDamage, int currentCooldown)
    : Skills(name, description, cooldown, isActive, currentCooldown), damageMultiplier(damageMultiplier), baseDamage(baseDamage) {}


void Attack::comboAttack(Enemy& target) {
    if (isActive && currentCooldown == 0) {
        int comboDamage = baseDamage * damageMultiplier;
        target.takeDamage(comboDamage);
        std::cout << "Комбо-атака! Урон: " << comboDamage << "\n";
        currentCooldown = cooldown;
        isActive = false;
    } else {
        std::cout << "Атака не активна или в откате!\n";
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
