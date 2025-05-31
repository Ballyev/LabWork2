#ifndef WARRIOR_H
#define WARRIOR_H
#include "../Hero.h"
#include <memory>
#include <vector>
#include "../../../obj/Armor.h"
#include "../../../obj/Item.h"
#include "../../../Skills/Attack.h"
#include "../../../Skills/Defence.h"
#include "../../../Skills/Skills.h"


class Warrior : public Hero 
{
    public:
    int rage;
    std::vector<std::unique_ptr<Skills>> skills;

    Warrior(std::string name, int level, int experience, int attack, int defence, int health, int rage);

     std::vector<std::unique_ptr<Item>> itemSector={};


    void useRage();
    void powerStrike(unsigned int baseDamage);
    void equipArmor(std::unique_ptr<Armor>);
    void useAttack(std::unique_ptr<Attack>& attackSkill, Enemy& target);
    void useDefence(std::unique_ptr<Defence>& defenceSkill, BattleSystem& battleSystem);

     ~Warrior() = default;
};

#endif