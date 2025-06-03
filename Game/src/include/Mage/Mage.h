#ifndef MAGE_H
#define MAGE_H
#include "../Hero/Hero.h"
#include <vector>
#include "../obj/Item.h"
#include "../obj/Potion.h"

class Magic;

class Mage : public Hero 
{
    public:
    int mana;
    int spellPower;

    std::vector<Item*> itemSector={};

    Mage(int level, int experience, int attack, int defence, std::string name, int health, int mana, int spellPower);

    void heal();
    void usePotion(Potion* potion, Enemy& target);

    ~Mage() = default;
};

#endif