#ifndef MAGIC_H
#define MAGIC_H
#include <iostream>
#include "Skills.h"

class Magic : public Skills
{
    public:
    int manaCost;
    int areaOfEffect;

    Magic(std::string name, std::string description, int cooldown, bool isActive, int manaCost, int areaOfEffect);

    void aoeDamage();
    void debuff();

    ~Magic() = default;
};


#endif