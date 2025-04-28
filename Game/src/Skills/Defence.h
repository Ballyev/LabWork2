#ifndef DEFENCE_H
#define DEFENCE_H
#include <iostream>
#include "Skills.h"

class Defence : public Skills 
{
    public:
    int defenceBoost;
    int duration;


    Defence(int defenceBoost, int duration, std::string name, std::string description, int cooldown, bool isActive);

    void taunt();
    void shieldBlock();
    void update();

    ~Defence() = default;
};


#endif