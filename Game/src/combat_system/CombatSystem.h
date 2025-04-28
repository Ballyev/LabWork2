#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H
#include <iostream>
#include <vector>

class CombatSystem
{
    public:
    bool isCombatActive;

    CombatSystem(bool isCombatActive);


    void startCombat(bool isCombatActive);
    void endCombat(bool isCombatActive);

    ~CombatSystem() = default;
};

#endif