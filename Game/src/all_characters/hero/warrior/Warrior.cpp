#include "../../../include/Warrior/Warrior.h"
#include <iostream>
#include "../../../include/Enemy/Enemy.h"

Warrior::Warrior(std::string name, int level, int experience, int attack, int defence, int health, int rage)
    : Hero(level, experience, attack, defence, name, health), rage(rage) {}

void Warrior::useRage() {
    if (health <= 50 && rage >= 20) {
        std::cout << "Воин пришел в ярость: 'Аaaa!' Урон усилен.\n";
        rage -= 20;
        attack += 10;
    } else {
        std::cout << "Воину не хватает ярости!\n";
    }
}

void Warrior::powerStrike(unsigned int baseDamage) {
    if (level >= 2 && rage >= 10) {
        std::cout << "Воин выполняет мощный удар! Нанесено урона: " << baseDamage * 2 << std::endl;
        rage -= 10;
    } else {
        std::cout << "Недостаточно ярости или уровня!\n";
    }
}

void Warrior::equipArmor(std::unique_ptr<Armor> _armor) {
    if (!_armor) return;


    defence += _armor->defence;
    std::cout << "Броня надета! +" << _armor->defence << " защиты.\n";

    if (_armor->stability == 0) {
        std::cout << "Броня упала!\n";
    }
}

void Warrior::useAttack(std::unique_ptr<Attack>& attackSkill, Enemy& target) {
    if (!attackSkill->isActive) {
        std::cout << "Атака \"" << attackSkill->name << "\" не активна!\n";
        return;
    }

    if (attackSkill->currentCooldown > 0) {
        std::cout << "Способность \"" << attackSkill->name << "\" на перезарядке: "
                  << attackSkill->currentCooldown << " ходов.\n";
        return;
    }

    std::cout << "Воин " << name << " использует атаку \"" << attackSkill->name << "\"!\n";
    attackSkill->comboAttack(target);
    attackSkill->isActive = false;
    attackSkill->currentCooldown = attackSkill->cooldown;
}

void Warrior::useDefence(std::unique_ptr<Defence>& defenceSkill, BattleSystem& battleSystem) {
    if (!defenceSkill->isActive) {
        std::cout << "Навык защиты на перезарядке.\n";
        return;
    }

    defenceSkill->shieldBlock();
}