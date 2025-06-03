#include <iostream>
#include "../include/Skills/Skills.h"

Skills::Skills(std::string name, std::string description, int cooldown, bool isActive, int currentCooldown)
    : name(std::move(name)), description(std::move(description)), cooldown(cooldown), isActive(isActive), currentCooldown(currentCooldown) {}


    void Skills::inspect() const {
        std::cout << "Skill: " << name << "\n"
                  << "Description: " << description << "\n"
                  << "Cooldown: " << cooldown << " turns\n"
                  << "Status: " << (isActive ? "Active" : "Inactive") << "\n"
                  << "Current cooldown: " << currentCooldown << "\n";
    }


void Skills::updateCooldown() {
    if (currentCooldown > 0) {
        currentCooldown--;
        if (currentCooldown == 0) {
            isActive = true;
            std::cout << name << " готова к использованию!\n";
        }
    }
}