#include <iostream>
#include "src/include/Hero/Hero.h"
#include "src/include/Warrior//Warrior.h"
#include "src/include/Rogue/Rogue.h"
#include "src/include/Mage/Mage.h"
#include "src/include/Dungeon/Dungeon.h"
#include "src/include/BattleSystem//BattleSystem.h"
#include "src/include/Skills/Attack.h"
#include "src/include/Skills/Magic.h"
#include "src/include/Skills/Defence.h"
#include "src/include/obj//Potion.h"
#include "src/include/obj/Scroll.h"
#include "src/include/Enemy/Boss.h"


void clearScreen() {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

void displayHeroInfo(const Hero& hero) {
    std::cout << "\n=== " << hero.name << " ===\n";
    std::cout << "Уровень: " << hero.level << "\n";
    std::cout << "Здоровье: " << hero.health << "\n";
    std::cout << "Атака: " << hero.attack << "\n";
    std::cout << "Защита: " << hero.defence << "\n";
    std::cout << "Опыт: " << hero.experience << "\n";
}


void createHero(Hero*& hero) {
    std::cout << "Выберите Героя:\n";
    std::cout << "1. Воин\n2. Разбойник\n3. Маг\nВаш выбор: ";
    int choice;
    std::cin >> choice;

    std::string name;
    std::cout << "Введите имя героя: ";
    std::cin >> name;

    switch (choice) {
        case 1:
            hero = new Warrior(name, 1, 0, 15, 10, 100, 50);
            hero->skills.push_back(std::make_unique<Attack>(2, "Удар клинком", "Базовая комбо-атака", 3, true, 10));
            hero->skills.push_back(std::make_unique<Defence>(10, 2, "Щит", "Повышает защиту на 5 на 2 хода", 4, true));
            break;

        case 2:
            hero = new Rogue(1, 0, 15, 10, name, 100, 30, 20);
            hero->skills.push_back(std::make_unique<Attack>(3, "Скрытная атака", "Критическая атака", 2, true, 12));
            hero->skills.push_back(std::make_unique<Defence>(10, 2, "Исчезновение", "На время скрывает вас от врагов", 5, true));
            hero->itemSector.push_back(std::make_unique<Scroll>("Свиток скрытности", "Скрывает вас", true, 2, 15));
            break;

        case 3:
            hero = new Mage(1, 0, 15, 10, name, 100, 50, 10);
            hero->skills.push_back(std::make_unique<Magic>("Огненный шар", "AoE урон", 5, true, 10, 15));
            hero->skills.push_back(std::make_unique<Defence>(10, 2, "Магический щит", "Защита +3 на 3 хода", 3, true));
            hero->itemSector.push_back(std::make_unique<Potion>("Яд", "Уменьшает здоровье", true, 0, 0, 20));
            break;

        default:
            hero = new Warrior(name, 1, 0, 10, 5, 100, 50);
    }
}


int main() {
    clearScreen();
    Hero* hero = nullptr;
    createHero(hero);

    Dungeon dungeon(1);
    dungeon.generate(5);

    while (true) {
        Room& currentRoom = dungeon.getCurrentRoom();
        currentRoom.printInfo();

        if (currentRoom.hasAliveEnemies()) {
            BattleSystem battle(*hero, *currentRoom.enemies[0], dungeon);
            battle.startBattle();

            if (!hero->isAlive()) {
                std::cout << "Вы погибли...\n";
                delete hero;
                return 0;
            }

            currentRoom.clearRoom();


            if (dungeon.isComplete()) {
                std::cout << "\n⚠️ Вы дошли до конца подземелья!\n";
                std::cout << "🔥 Из тени выходит: Кровавое Чудовище\n";

                Boss boss("Кровавое Чудовище", 70, 15, 5, 15, 1, false);
                BattleSystem bossBattle(*hero, boss, dungeon);
                bossBattle.startBattle();

                if (!hero->isAlive()) {
                    std::cout << "Вы были повержены боссом...\n";
                    delete hero;
                    return 0;
                }

                std::cout << "Вы победили финального босса! Подземелье пройдено.\n";
                break;
            }
        } else {
            std::cout << "В этой комнате нет врагов.\n";

            if (!dungeon.moveToNextRoom()) {
                std::cout << "Подземелье окончено.\n";
                break;
            }
        }

        char moveChoice;
        std::cout << "Продолжить? (y/n): ";
        std::cin >> moveChoice;

        if (moveChoice != 'y' && moveChoice != 'Y') {
            std::cout << "Вы покидаете подземелье. До новых встреч!\n";
            break;
        }
    }
    delete hero;
    return 0;
}