#ifndef POTION_H
#define POTION_H
#include <iostream>
#include "Item.h"

class Potion : public Item
{
    public:
    int healingPower;
    int duration;

    Potion(std::string name, std::string description, bool isConsumable, int healingPower, int duration);

    void restoreHealth();
    void boostStat();

    ~Potion() = default;
};



#endif