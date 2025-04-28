#ifndef STEALTH_H
#define STEALTH_H
#include <iostream>
#include "Skills.h"

class Stealth : public Skills
{
    public:
    int stealthLevel;
    int detectionRange;
    int getstealthLevel() { return stealthLevel; }

    Stealth(std::string name, std::string description, int cooldown, bool isActive, int stealthLevel, int detectionRange);

    void vanish();
    void trapDetection();

    ~Stealth()  = default;
};

#endif
