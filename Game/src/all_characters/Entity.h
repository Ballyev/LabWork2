#ifndef ENTITY_H
#define ENTITY_H

#include "../Skills/Attack.h"
#include "../Skills/Defence.h"
#include <memory>

class Entity {
public:
    std::string name;
    int health;
    std::unique_ptr<Attack> currentAttack;  
    std::unique_ptr<Defence> currentDefence; 

    Entity(std::string name, int health);
    
    
    void setAttack(std::unique_ptr<Attack> attack);
    void setDefence(std::unique_ptr<Defence> defence);
    
    
    void performAttack();
    void activateDefence();
    
    void takeDamage(int damage);
    void displayInfo() const;
};
#endif
