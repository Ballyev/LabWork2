#ifndef HERO_H
#define HERO_H
#include "../Character.h"
#include "../../obj/Item.h"
#include "../../obj/Weapon.h"
#include <vector>
#include <memory>
#include "../../Skills/Skills.h"
class Hero : public Character{
    public:
    int level;
    int experience;
    Weapon *Gun;
    int currentDefendCooldown = 0;
    int originalDefence = 0;

    Hero(int level, int experience, int attack, int defence, std::string name, int health);
    std::vector<std::unique_ptr<Skills>> skills;
    std::vector<std::unique_ptr<Item>> itemSector={};

    void levelUp();
    void equipWeapon(Weapon *);
    bool isAlive() const { return health > 0; }
    void gainExperience(int amount);
    void endTurn();


    ~Hero() = default;
};

#endif
