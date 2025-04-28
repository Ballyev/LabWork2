#include "CombatSystem.h"
#include <iostream>

CombatSystem::CombatSystem(bool isCombatActive) : isCombatActive(isCombatActive) {}

void CombatSystem::startCombat(bool isCombatActive)
{
    if(isCombatActive == true)
    std::cout << "Let's go\n";
}

void CombatSystem::endCombat(bool isCombatActive)
{
    if(isCombatActive == false)
    std::cout << "    :(      " << std::endl;
}