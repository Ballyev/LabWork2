#ifndef POTION_H
#define POTION_H
#include <iostream>
#include "Item.h"

class Potion : public Item
{
    public:
    int healingPower;
    int duration;
    int attackPower;

    Potion(std::string name, std::string description, bool isConsumable, int healingPower, int duration, int attackPower);

    void restoreHealth() const;
    void boostStat() const;

    ~Potion() = default;
};



#endif