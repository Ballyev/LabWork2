#ifndef ROGUE_H
#define ROGUE_H
#include<memory>
#include<vector>
#include "../../../obj/Scroll.h"
#include "../../../obj/Item.h"


class Rogue : public Hero 
{
    public:
    int stealth;
    int criticalChance;


    Rogue(int level, int experience, int attack, int defence, std::string name, int health, int stealth, int criticalChance);

    std::vector<std::unique_ptr<Item>> itemSector={};
    unsigned int sneakAttack(unsigned int baseDamage);
    void useScroll(std::unique_ptr<Scroll>);
    
    ~Rogue() = default;


};


#endif