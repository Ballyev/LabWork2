#ifndef ROGUE_H
#define ROGUE_H
#include "../Hero.h"
#include <iostream>
#include<memory>
#include<vector>
#include "../../../obj/Scroll.h"
#include "../../../obj/Item.h"
#include "../../../Skills/Stealth.h"
#include <memory>
#include <vector>

class Rogue : public Hero 
{
    public:
    int stealth;
    int criticalChance1;
    std::unique_ptr<Stealth> stealthAbility;
    

    Rogue(int level, int experience, int attack, int defence, std::string name, int health, int stealth, int criticalChance1);

    std::vector<std::unique_ptr<Item>> itemSector={};

    void sneakAttack(unsigned int stealth, unsigned int baseDamage);
    void dodge(unsigned int chance);
    void criticalChance();
    void useScroll(std::unique_ptr<Scroll>);
    void useStealth(std::unique_ptr<Stealth>);
    
    ~Rogue() = default;


};


#endif