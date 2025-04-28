#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <iostream>


class Enemy : public Character {
    public:
    int reward;

    Enemy(int reward, int attack, int defence, std::string name, int health);

    void roar();
    void flee();
    
    ~Enemy() = default;
};

#endif 

