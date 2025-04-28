#include <iostream>
#include "Skills.h"

Skills::Skills(std::string name, std::string description, int cooldown, bool isActive) : name(name), description(description), cooldown(cooldown), isActive(isActive) {}

    void Skills::activate() {
        if (currentCooldown == 0 && !isActive) {
            isActive = true;
            std::cout << name << " has been activated!\n";
        } else if (isActive) {
            std::cout << name << " is already active!\n";
        } else {
            std::cout << name << " is on cooldown! (" << currentCooldown << " turns remaining)\n";
        }
    }

    // Показывает информацию о способности
    void Skills::inspect() {
        std::cout << "Skill: " << name << "\n"
                  << "Description: " << description << "\n"
                  << "Cooldown: " << cooldown << " turns\n"
                  << "Status: " << (isActive ? "Active" : "Inactive") << "\n"
                  << "Current cooldown: " << currentCooldown << "\n";
    }

    // Деактивирует способность
    void Skills::deactivate() {
        if (isActive) {
            isActive = false;
            currentCooldown = cooldown;  // Устанавливаем кулдаун при деактивации
            std::cout << name << " has been deactivated. Cooldown started.\n";
        } else {
            std::cout << name << " is not active!\n";
        }
    }

    // Обновляет кулдаун (должен вызываться каждый ход/тик)
    void Skills::updateCooldown() {
        if (currentCooldown > 0) {
            currentCooldown--;
            if (currentCooldown == 0 && !isActive) {
                std::cout << name << " is ready to use again!\n";
            }
        }
    }