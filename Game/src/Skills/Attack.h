#ifndef ATTACK_H
#define ATTACK_H
#include <iostream>
#include "Skills.h"
#include "../Enemy.h"

class Attack : public Skills
{
    public:
    int damageMultiplier;
    int baseDamage;

    Attack(int damageMultiplier, std::string name, std::string description, int cooldown, bool isActive, int baseDamage, int currentCooldown = 0);

    void criticalHit(Enemy& target);
    void comboAttack(Enemy& target);
    ~Attack() = default;

};


#endif