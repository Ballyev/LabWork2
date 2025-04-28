#ifndef HERO_H
#define HERO_H
#include "../../Character.h"
#include "../../obj/Item.h"
#include "../../obj/Weapon.h"
#include <iostream>
#include <vector>
#include <memory>
class Hero : public Character 
{
    public:
    int level;
    int experience;

    Hero(int level, int experience, int attack, int defence, std::string name, int health);

    std::vector<std::unique_ptr<Item>> itemSector={};

    void levelUp();
    void useItem(std::unique_ptr<Weapon>);


    virtual ~Hero() = default;
};

#endif
