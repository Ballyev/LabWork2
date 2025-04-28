#ifndef MAGE_H
#define MAGE_H
#include "../Hero.h"
#include <iostream>
#include <memory>
#include <vector>
#include "../../../obj/Item.h"
#include "../../../obj/Potion.h"
#include "../../../Skills/Magic.h"

class Mage : public Hero 
{
    public:
    int mana;
    int spellPower;

    std::vector<std::unique_ptr<Item>> itemSector={};

    void castSpell(const Magic& spell);
    void heal();
    void usePotion(std::unique_ptr<Potion>);
    
    
    Mage(int level, int experience, int attack, int defence, std::string name, int health, int mana, int spellPower);
    ~Mage() = default;
};

#endif