#include "Magic.h"
#include <iostream>

Magic::Magic(std::string name, std::string description, int cooldown, bool isActive, int manaCost) : Skills (name, description, cooldown, isActive) {}

void Magic::aoeDamage(std::vector<Enemy>& enemies) {
    if (currentCooldown > 0) {
        std::cout << name << " на перезарядке! Осталось " << currentCooldown << " ходов\n";
        return;
    }
    if (!isActive) {
        std::cout << name << " недоступно для использования!\n";
        return;
    }
    std::cout << name << " наносит AoE урон!\n";
    for (Enemy& enemy : enemies) {
        enemy.health -= damage;
        std::cout << "  " << enemy.name << " получает " << damage << " урона. ";
        if (enemy.health <= 0) {
            std::cout << enemy.name << " повержен!" << std::endl;
        }
    }
    currentCooldown = cooldown;
    std::cout << name << " перезаряжается (" << cooldown << " ходов)\n";
}

void Magic::update() {
    if (currentCooldown > 0) {
        currentCooldown--;
        if (currentCooldown == 0) {
            isActive = true;
            std::cout << name << " готово к использованию!\n";
        }
    }
}
void Magic::debuff(Enemy& target_enemy) {
    if (isActive == true) {
        target_enemy.attackPower /= 2;
        std::cout << name << " снижает силу атаки " << target_enemy.name << "!\n";
        isActive = false;
    }else{
        std::cout << "Способность уже использована\n";
    }
}