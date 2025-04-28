#ifndef BOSS_H
#define BOSS_H
#include <iostream>
#include "Enemy.h"
#include <vector>

class Boss : public Enemy 
{
    public:
    int phase;
    bool isEnraged;
    std::vector<std::string> minions;

    Boss(int reward, int attack, int defence, std::string name, int health, int phase, bool isEnraged);
    
    void summonMinions(int count);
    void ultimateAbility(bool isEnraged);
    
    ~Boss() = default;

};




#endif