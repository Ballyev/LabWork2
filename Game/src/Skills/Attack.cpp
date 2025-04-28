#include "Attack.h"
#include <iostream>

Attack::Attack(int damageMultiplier, std::string name, std::string description, int cooldown, bool isActive) : Skills (name, description, cooldown, isActive) {}

void Attack::comboAttack() {
    if (isActive) {
        int comboDamage = damageMultiplier * 2; //удвоенный урон
        std::cout << "Combo attack! Damage: " << comboDamage << std::endl;
        cooldown += 1; // Увеличиваем кулдаун после комбо-атаки
    } else {
        std::cout << "Attack is not active!" << std::endl;
    }
}

void Attack::criticalHit() {
    if (isActive) {
        int criticalDamage = damageMultiplier * 3; // Например, утроенный урон
        std::cout << "Critical hit! Damage: " << criticalDamage << std::endl;
        cooldown += 2; // Увеличиваем кулдаун сильнее после критического удара
    } else {
        std::cout << "Attack is not active!" << std::endl;
    }
}