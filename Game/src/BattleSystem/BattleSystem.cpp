#include "BattleSystem.h"
#include <iostream>
#include "../Skills/Attack.h"
#include "../Skills/Magic.h"
#include "../Skills/Defence.h"
#include "../obj/Potion.h"
#include "../obj/Scroll.h"
#include "../obj/Item.h"
#include <vector>

BattleSystem::BattleSystem(Hero& h, Enemy& e, Dungeon& d)
    : hero(h),
      enemy(e),
      activeDefenceBonus(0),
      defenceDurationLeft(0),
      dungeon(d) {}

bool BattleSystem::isHeroAlive() const {
    return hero.isAlive();
}

bool BattleSystem::isEnemyAlive() const {
    return enemy.isAlive();
}

void BattleSystem::startBattle() {
    std::cout << "Битва началась!\n";

    while (isHeroAlive() && isEnemyAlive()) {
        hero.displayInfo();
        enemy.displayInfo();

        heroTurn();
        if (!isEnemyAlive()) break;

        enemyTurn();
    }

    if (!isEnemyAlive()) {
        std::cout << "\nВы победили врага: " << enemy.name << "! Получено 50 опыта.\n";
        hero.gainExperience(50);
        hero.levelUp();
    }

    if (!isHeroAlive()) {
        std::cout << "Вы погибли...\n";
    }
}

void BattleSystem::useBasicAttack() {
    std::cout << hero.name << "Атаковать.\n";
    enemy.takeDamage(hero.attack);
}

void BattleSystem::useSkill() {
    std::cout << "Доступные навыки:\n";
    for (size_t i = 0; i < hero.skills.size(); ++i) {
        auto& skill = hero.skills[i];

        if (auto* attack = dynamic_cast<Attack*>(skill.get())) {
            std::cout << i + 1 << ". Атака: " << attack->name
                      << " [Cooldown: " << attack->currentCooldown << "]\n";
        } else if (auto* magic = dynamic_cast<Magic*>(skill.get())) {
            std::cout << i + 1 << ". Магия: " << magic->name
                      << " [Cooldown: " << magic->currentCooldown << "]\n";
        } else if (auto* defence = dynamic_cast<Defence*>(skill.get())) {
            std::cout << i + 1 << ". Защита: " << defence->name
                      << " [Cooldown: " << defence->currentCooldown << "]\n";
        }
    }
    size_t index;
    std::cout << "Ваш выбор: ";
    std::cin >> index;
    if (index == 0) {
        std::cout << "Возврат в меню.\n";
        return heroTurn();
    }

    if (index > 0 && index <= hero.skills.size()) {
        auto& skill = hero.skills[index - 1];


        if (auto* attackSkill = dynamic_cast<Attack*>(skill.get())) {
            if (!attackSkill->isActive) {
                std::cout << "Навык \"" << attackSkill->name << "\" на перезарядке.\n";
                return;
            }

            if (!dungeon.getCurrentRoom().hasAliveEnemies()) {
                std::cout << "Нет целей для атаки.\n";
                return;
            }

            Enemy* target = dungeon.getCurrentRoom().enemies[0].get();
            attackSkill->comboAttack(*target);
            attackSkill->currentCooldown = attackSkill->cooldown;
            attackSkill->isActive = false;
        }



        else if (auto* magicSkill = dynamic_cast<Magic*>(skill.get())) {
            if (!magicSkill->isActive) {
                std::cout << "Магия \"" << magicSkill->name << "\" на перезарядке.\n";
                return;
            }

            if (!dungeon.getCurrentRoom().hasAliveEnemies()) {
                std::cout << "Нет целей для магии.\n";
                return;
            }

            Enemy* target = dungeon.getCurrentRoom().enemies[0].get();
            magicSkill->singleTargetDamage(target);
            magicSkill->currentCooldown = magicSkill->cooldown;
            magicSkill->isActive = false;
        }

        else if (auto* defenceSkill = dynamic_cast<Defence*>(skill.get())) {
            if (!defenceSkill->isActive) {
                std::cout << "Защита \"" << defenceSkill->name << "\" на перезарядке.\n";
                return;
            }
            defenceSkill->shieldBlock();
        }
    } else {
        std::cout << "Неверный номер навыка.\n";
    }
}

void BattleSystem::useItem() {
    if (hero.itemSector.empty()) {
        std::cout << "Нет доступных предметов\n";
        return;
    }

    std::cout << "Доступные предметы:\n";
    for (size_t i = 0; i < hero.itemSector.size(); ++i) {
        std::cout << i + 1 << ". " << hero.itemSector[i]->name << "\n";
    }

    size_t index;
    std::cout << "Ваш выбор: ";
    std::cin >> index;
    if (index == 0) {
        std::cout << "Возврат в меню.\n";
        return heroTurn();
    }

    if (index > 0 && index <= hero.itemSector.size()) {
        auto& item = hero.itemSector[index - 1];

        if (auto* potion = dynamic_cast<Potion*>(item.get())) {
            potion->restoreHealth();
            enemy.takeDamage(potion->attackPower);
        } else if (auto* scroll = dynamic_cast<Scroll*>(item.get())) {
            scroll->castEffect();
        } else {
            std::cout << "Этот предмет нельзя использовать в бою\n";
        }
    } else {
        std::cout << "Неверный выбор предмета\n";
    }
}

void BattleSystem::useDefence() {
    for (auto& skill : hero.skills) {
        if (auto* defSkill = dynamic_cast<Defence*>(skill.get())) {
            if (defSkill->currentCooldown > 0) {
                std::cout << "Защита \"" << defSkill->name << "\" на перезарядке.\n";
                return;
            }


            activeDefenceBonus = defSkill->defenceBoost;
            defenceDurationLeft = defSkill->duration;

            std::cout << defSkill->name << " снижает урон на "
                      << defSkill->defenceBoost << " на "
                      << defSkill->duration << " ходов\n";


            defSkill->currentCooldown = defSkill->cooldown;
            skill->updateCooldown();

            return;
        }
    }
    std::cout << "Нет навыка защиты!\n";
}

void BattleSystem::updateDefence() {
    if (defenceDurationLeft > 0) {
        defenceDurationLeft--;
        if (defenceDurationLeft == 0) {
            activeDefenceBonus = 0;
        }
    }
}

void BattleSystem::heroTurn() {
    updateDefence();

    std::cout << "\n=== Ваш ход ===\n";

    std::cout << "Выберите действие:\n"
              << "1. Базовая атака\n"
              << "2. Использовать навык\n"
              << "3. Использовать предмет\n"
              << "4. Защититься\n"
              << "0. Отменить\n";

    int action;
    std::cin >> action;

    switch (action) {
        case 1:
            useBasicAttack();
            break;
        case 2:
            useSkill();
            break;
        case 3:
            useItem();
            break;
        case 4:
            useDefence();
            break;
        case 0:
            std::cout << "Действие отменено.\n";
            return;
        default:
            std::cout << "Неверный выбор.\n";
            return heroTurn();
    }


    for (auto& skill : hero.skills) {
        skill->updateCooldown();
    }
}

void BattleSystem::enemyTurn() {
    if (defenceDurationLeft > 0) {
        defenceDurationLeft--;
        if (defenceDurationLeft == 0) {
            activeDefenceBonus = 0;
        }
    }

    if (isEnemyAlive()) {
        int damage = enemy.attackPower - activeDefenceBonus;
        if (damage < 0) damage = 0;

        std::cout << enemy.name << " атакует " << hero.name << "!\n";
        hero.takeDamage(damage);
    }
}