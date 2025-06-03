#ifndef DEFENCE_H
#define DEFENCE_H
#include "Skills.h"
#include "../Enemy/Enemy.h"
#include "../BattleSystem/BattleSystem.h"

class Defence : public Skills 
{
    public:
    int defenceBoost;
    int duration;
    Defence(int defenceBoost, int duration, std::string name, std::string description, int cooldown, bool isActive, int currentCooldown = 0);


    void shieldBlock();
    void update();

    ~Defence() = default;
};


#endif