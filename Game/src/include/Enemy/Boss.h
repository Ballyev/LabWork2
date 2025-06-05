#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"
#include "../Hero/Hero.h"

class Boss : public Enemy 
{
    public:
    int phase;
    bool isEnraged;

    Boss(std::string name, int health,int attack,int defence, int attackPower, int phase, bool isEnraged);

    void ultimateAbility(Hero& target);


    ~Boss() = default;

};

#endif