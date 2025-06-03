#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

class Enemy;

class Character {
public:
    std::string name;
    int health;
    int attack;
    int defence;


    Character(std::string name, int health,int attack,int defence);

    virtual void takeDamage(int damage);
    void displayInfo() const;
    void attackTarget(Enemy& enemy);
    void defend(int currentDefendCooldown, int originalDefence);

    virtual ~Character() = default;
};
#endif
