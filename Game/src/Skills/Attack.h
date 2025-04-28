#ifndef ATTACK_H
#define ATTACK_H
#include <iostream>
#include "Skills.h"

class Attack : public Skills
{
    public:
    int damageMultiplier;

    Attack(int damageMultiplier, std::string name, std::string description, int cooldown, bool isActive);

    void criticalHit();
    void comboAttack();
    ~Attack() = default;

};


#endif