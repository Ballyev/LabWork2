#ifndef MAGIC_H
#define MAGIC_H
#include <iostream>
#include "Skills.h"
#include "../Enemy.h"
#include <vector>
#include "../all_characters/hero/mage/Mage.h"

class Magic : public Skills
{
    public:
    int manaCost;
    int damage;

    Magic(std::string name, std::string description, int cooldown, bool isActive, int manaCost);

    void aoeDamage(std::vector<Enemy>& enemies);
    void debuff(Enemy& target_enemy);
    void update();

    ~Magic() = default;
};


#endif