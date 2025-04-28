#ifndef ARMOR_H
#define ARMOR_H
#include <iostream>
#include "Item.h"
#include <memory>
#include <vector>
#include "Weapon.h"

class Armor : public Item
{
public:
    int defence;
    int stability;

    Armor(std::string name, std::string description, bool isConsumable, int defence, int stability);

    void reinforce();
    void absorbDamage(int damage);

    ~Armor() = default;
};

#endif