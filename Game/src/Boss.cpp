#include <iostream>
#include "Boss.h"
#include <vector>

Boss::Boss(std::string name, int health,int attack,int defence,int attackPower, int phase, bool isEnraged) : Enemy (name, health, attack, defence, attackPower) {}

void Boss::ultimateAbility(Hero& target) {
    if (!isAlive()) {
        std::cout << name << " не может использовать способность - он повержен!\n";
        return;
    }
    if (!target.isAlive()) {
        std::cout << "Нельзя атаковать мертвую цель!\n";
        return;
    }

    if (isEnraged || health < 50) {
        int originalAttack = attack;
        attack *= 2;
        target.takeDamage(attack);
        std::cout << "Ярость! Атака увеличена с " << originalAttack
                  << " до " << attack << " и нанесен урон!\n";
    } else {
        std::cout << "Условия для ярости не выполнены\n";
    }
}