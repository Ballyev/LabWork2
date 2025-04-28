#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "all_characters/Entity.h"

class Character : public Entity
{
    public:
    int attack;
    int defence;

    
    Character(int attack, int defence, std::string name, int health);

    void attackTarget();
    void defend();

    ~Character() = default;
};


#endif