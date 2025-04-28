#include  <iostream>
#include "Defence.h"

Defence::Defence(int duration, int defenceBoost, std::string name, std::string description, int cooldown, bool isActive) : Skills (name, description, cooldown, isActive) {}

void Defence::taunt() {
        if (isActive) {
            std::cout << name << " is already active! Cannot taunt now.\n";
            return;
        }

        if (cooldown > 0) {
            std::cout << name << " is on cooldown for " << cooldown << " turns. Cannot taunt now.\n";
            return;
        }

        isActive = true;
        std::cout << "You use " << name << "!\n";
        std::cout << description << "\n";
        std::cout << "Increases your defence by " << defenceBoost << " for " << duration << " turns.\n";
        std::cout << "Enemies are forced to attack you!\n";

        
        cooldown = duration + 3; 
    }

    void Defence::shieldBlock() {
        if (isActive) {
            std::cout << name << " is already active! Cannot block now.\n";
            return;
        }

        if (cooldown > 0) {
            std::cout << name << " is on cooldown for " << cooldown << " turns. Cannot block now.\n";
            return;
        }

        isActive = true;
        std::cout << "You raise your shield with " << name << "!\n";
        std::cout << description << "\n";
        std::cout << "Increases your defence by " << defenceBoost << " for " << duration << " turns.\n";
        std::cout << "You take reduced damage from frontal attacks!\n";

        
        cooldown = duration + 2; 
    }

    
    void Defence::update() {
        if (isActive) {
            duration--;
            if (duration <= 0) {
                isActive = false;
                std::cout << name << " has worn off.\n";
            }
        }

        if (cooldown > 0) {
            cooldown--;
        }
    };