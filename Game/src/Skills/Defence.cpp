#include  <iostream>
#include "../include/Skills/Defence.h"

Defence::Defence(int defenceBoost, int duration, std::string name, std::string description, int cooldown, bool isActive, int currentCooldown)
    : Skills(name, description, cooldown, isActive, currentCooldown), defenceBoost(defenceBoost), duration(duration) {}

void Defence::shieldBlock() {
    if (!isActive) {
        std::cout << name << " на перезарядке.\n";
        return;
    }
    if (duration > 0) {
        duration--;
        std::cout << name << " снижает урон на " << defenceBoost << " на "
                  << duration << " ходов\n";
    } else {
        std::cout << name << " больше не действует.\n";
        isActive = false;
        currentCooldown = cooldown;
    }
}

void Defence::update() {
    if (isActive) {
        duration--;
        if (duration <= 0) {
            isActive = false;
            std::cout << name << " завершила действие.\n";
        }
    }
    if (currentCooldown > 0) {
        currentCooldown--;
    }
}
