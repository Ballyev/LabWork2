#include "Potion.h"
#include <iostream>

Potion::Potion(std::string name, std::string description, bool isConsumable,int healingPower, int durability) : Item(name, description, isConsumable) {}


void Potion::restoreHealth() 
{
    if (!isConsumable) {
        std::cout << "Error: " << name << " cannot be consumed!\n";
        return;
    }
    
    if (healingPower <= 0) {
        std::cout << "Warning: " << name << " has no healing effect!\n";
        return;
    }
    
    std::cout << name << " restores " << healingPower << " health points. ";
    std::cout << "(Duration: " << duration << " turns)\n";
    
}

void Potion::boostStat()
{
    if (duration <= 0) {
        std::cout << name << " has expired and has no effect!\n";
        return;
    }
    
    std::cout << name << " grants a temporary stat boost for " << duration << " turns.\n";
}