#include <iostream>
#include "Rogue.h"

Rogue::Rogue(int level, int experience, int attack, int defence, std::string name, int health, int stealth, int criticalChance1)
    : Hero(level, experience, attack, defence, name, health), stealth(stealth), criticalChance1(criticalChance1) {}

void Rogue::dodge(unsigned int chance)
{
    if(chance > 50)
    std::cout << "Разбойник увернулся от атаки" <<  std::endl;  
}

void Rogue::criticalChance() {
    std::cout << "КРИТИЧЕСКИЙ УДАР! Урон увеличен вдвое!\n";
}

#include "Rogue.h"

void Rogue::useStealth(std::unique_ptr<Stealth> ability) {
    if (!ability) {
        std::cout << "Неверная способность скрытности!" << std::endl;
        return;
    }

    // Передаем владение
    stealthAbility = std::move(ability); 

    // Используем методы через ->
    stealthAbility->vanish(); 
    stealthAbility->trapDetection();
    
    stealth += stealthAbility->getstealthLevel();
    std::cout << "Скрытность увеличена до: " << stealth << std::endl;
}

void Rogue::sneakAttack(unsigned int stealth, unsigned int baseDamage) {
    if (stealth > 75) {
        criticalChance();
        std::cout << "Скрытный удар в уязвимое место!\n";
        std::cout << "Вы нанесли " << baseDamage * 2 << " урона.\n";
    } else if (stealth > 40) {
        std::cout << "Вы нанесли скрытый удар!\n";
        std::cout << "Вы нанесли " << baseDamage << " урона.\n";
    } else {
        std::cout << "Враг вас заметил! Урон снижен.\n";
        std::cout << "Вы нанесли " << baseDamage / 2 << " урона.\n";
    }
    
}
    void Rogue::useScroll(std::unique_ptr<Scroll> _scroll) 
    {
        std::cout << "Using Scroll: " << _scroll->name << std::endl;
        stealth += _scroll->effect; 
    }