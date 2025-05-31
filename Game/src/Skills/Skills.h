#ifndef SKILLS_H
#define SKILLS_H

#include <iostream>

#include <string>

class Skills {
    public:
    std::string name;
    std::string description;
    int cooldown;
    bool isActive;
    int currentCooldown;

    Skills(std::string name, std::string description, int cooldown, bool isActive, int currentCooldown = 0);


    void inspect() const;
    void updateCooldown();

    virtual ~Skills() = default;
};

#endif