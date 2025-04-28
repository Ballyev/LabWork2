#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include "Item.h"

class Weapon : public Item
{
    public:
    int damage;
    int durability;

    Weapon(std::string name, std::string description, bool isConsumable, int damage, int durabilty);

    void upgrade();
    void specialEffect();


    ~Weapon() = default;

};


#endif