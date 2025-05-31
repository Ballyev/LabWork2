#ifndef ENEMY_H
#define ENEMY_H
#include "all_characters/hero/Hero.h"
#include <iostream>
#include "all_characters/Character.h"
#include "BattleSystem/BattleSystem.h"


class Enemy : public Character {
    public:
    int attackPower;
    Enemy(std::string name, int health,int attack,int defence, int attackPower);

    void attack_hero(Hero& target);
    void takeDamage(int damage);
    bool isAlive() const;


    ~Enemy() = default;
};

#endif 

