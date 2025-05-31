#ifndef CHARACTER_H
#define CHARACTER_H
#include "../Skills/Attack.h"
#include "../Skills/Defence.h"
#include "../Enemy.h"

class Character {
public:
    std::string name;
    int health;
    Attack attack;
    Defence defence;

    Character(std::string name, int health, Attack attack,Defence defence);

    void takeDamage(int damage);
    void displayInfo() const;
    void attackTarget(Enemy& );
    void defend();

    ~Character() = default;
};
#endif
