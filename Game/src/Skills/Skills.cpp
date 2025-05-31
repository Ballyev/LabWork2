#include <iostream>
#include "Skills.h"

Skills::Skills(std::string name, std::string description, int cooldown, bool isActive) : name(name), description(description), cooldown(cooldown), isActive(isActive) {}

    // Показывает информацию о способности
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

        if (currentCooldown == 0) {  // Без лишних условий!
            isActive = true;  // Способность снова доступна
            std::cout << name << " готова к использованию!\n";
        }
    }
}