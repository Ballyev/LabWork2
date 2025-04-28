#include <iostream>
#include "Stealth.h"

Stealth::Stealth(std::string name, std::string description, int cooldown, bool isActive, int stealthLevel, int detectionRange) : Skills (name, description, cooldown, isActive) {}

    void Stealth::vanish() {
        if (!isActive) {
            activate();  // Активируем способность, если она не активна
            stealthLevel = 100;  // Максимальная скрытность при активации
            std::cout << name << " - You vanish into the shadows!\n";
        } else {
            std::cout << name << " - You're already hidden!\n";
        }
    }

    // Обнаружение ловушек в радиусе
    void Stealth::trapDetection() {
        if (isActive) {
            std::cout << name << " - Scanning area (" << detectionRange 
                      << "m radius) for traps...\n";
            // Логика обнаружения ловушек могла бы быть здесь
            std::cout << "Trap detection active using stealth level " 
                      << stealthLevel << "\n";
        } else {
            std::cout << name << " - Skill not active! Cannot detect traps.\n";
        }
    }