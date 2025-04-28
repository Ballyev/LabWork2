#include "Hero.h"
#include <iostream>


Hero::Hero(int level, int experience, int attack, int defence, std::string name, int health) : Character(attack, defence, name, health) {}

void Hero::levelUp()
{
    std::cout << "Checking level up... ";
        int expNeeded = level * 50;  
        
        if (experience >= expNeeded) 
        {
            level += 1;              
            experience -= expNeeded; 
            attack += 3;
            defence += 2;           
            
            
            std::cout << "Level up! New level: " << level 
                      << ", attack: " << attack 
                      << ", defence: " << defence 
                      << ", remaining exp: " << experience << std::endl;
        } else {
            std::cout << "Not enough experience. Need " << (expNeeded - experience) 
                      << " more exp for level " << (level + 1) << std::endl;
        }
}

void Hero::useItem(std::unique_ptr<Weapon> _weapon)
{
    std::cout << "Using Weapon: " << _weapon->name << std::endl;
    Hero::attack += _weapon->damage;
}