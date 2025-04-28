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
    int rage1;

    Warrior(std::string name, int level, int experience, int attack, int defence, int health, int rage1);

     std::vector<std::unique_ptr<Item>> itemSector={};


    void rage(unsigned int rage1);
    void powerStrike(unsigned int level);
    void equipArmor(std::unique_ptr<Armor>);

    ~Warrior() = default;
};

#endif