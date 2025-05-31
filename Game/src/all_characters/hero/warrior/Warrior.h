#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>
#include "../Hero.h"
#include <memory>
#include <vector>
#include "../../../obj/Armor.h"
#include "../../../obj/Item.h"


class Warrior : public Hero 
{
    public:
    int rage;

    Warrior(std::string name, int level, int experience, int attack, int defence, int health, int rage);

     std::vector<std::unique_ptr<Item>> itemSector={};


    void rage();
    void powerStrike(unsigned int baseDamage);
    void equipArmor(std::unique_ptr<Armor>);

     ~Warrior() = default;
};

#endif