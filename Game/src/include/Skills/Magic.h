#ifndef MAGIC_H
#define MAGIC_H
#include <iostream>
#include "Skills.h"
#include "../Enemy/Enemy.h"
#include <vector>
#include "../Mage/Mage.h"


class Magic : public Skills
{
    public:
    int manaCost;
    int damage;

    Magic(std::string name, std::string description, int cooldown, bool isActive, int manaCost, int damage, int currentCooldown = 0);

    void singleTargetDamage(Enemy* target);
    void debuff(Enemy& target_enemy);
    void update();

    ~Magic() = default;
};


#endif