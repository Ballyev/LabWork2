#include <iostream>
#include <vector>
#include "src/all_characters/hero/Hero.h"
#include "src/all_characters/hero/warrior/Warrior.h"
#include "src/all_characters/hero/mage/Mage.h"
#include "src/all_characters/hero/rogue/Rogue.h"
#include "src/Enemy.h"
#include "src/dungeon/Room.h"
#include "src/Character.h"

// Простое меню
void showMenu() {
    std::cout << "\n=== МЕНЮ ===\n";
    std::cout << "1. Атаковать\n";
    std::cout << "2. Защищаться\n";
    std::cout << "3. Использовать способность\n";
    std::cout << "4. Перейти в следующую комнату\n";
    std::cout << "5. Выход\n";
    std::cout << "Выбор: ";
}

// Основная игра
void startGame() {
    // Создаем героя
    std::cout << "Выбери класс:\n1. Воин\n2. Маг\n3. Разбойник\n";
    int choice;
    std::cin >> choice;
    
    Hero* hero = nullptr;
    std::string name;
    std::cout << "Имя героя: ";
    std::cin >> name;
    
    if(choice == 1) {
        hero = new Warrior(name, 1, 0, 15, 10, 100, 0);
    } 
    else if(choice == 2) {
        hero = new Mage(1, 0, 10, 5, name, 80, 100, 20);
    }
    else {
        hero = new Rogue(1, 0, 12, 8, name, 90, 50, 15);
    }
    
    // Создаем подземелье
    std::vector<Room> rooms = {
        Room(true, false, 1),  // Комната с врагом
        Room(false, true, 2),   // Комната с сокровищем
        Room(true, true, 3)     // Комната с боссом
    };
    
    int currentRoom = 0;
    bool playing = true;
    
    while(playing && hero->health > 0) {
        std::cout << "\n=== Комната " << currentRoom+1 << " ===\n";
        rooms[currentRoom].spawnBoss();
        
        if(rooms[currentRoom].isEnemy) {
            Enemy enemy(50, 8, 4, "Гоблин", 30);
            std::cout << "Враг: " << enemy.name << " (HP: " << enemy.health << ")\n";
            
            bool fighting = true;
            while(fighting && enemy.health > 0 && hero->health > 0) {
                showMenu();
                std::cin >> choice;
                
                switch(choice) {
                    case 1:
                        hero->attackTarget();
                        enemy.takeDamage(hero->attack);
                        break;
                    case 2:
                        hero->defend();
                        break;
                    case 3:
    if (choice == 2) { // Если выбран маг
        Magic spell("Огненный шар", "Горит!", 2, true, 15, 3);
        spell.aoeDamage();
        enemy.takeDamage(20);
    }
    else {
        std::cout << "Этот класс не умеет кастовать заклинания!\n";
    }
    break;
                    case 4:
                        fighting = false;
                        break;
                    case 5:
                        playing = false;
                        fighting = false;
                        break;
                }
                
                if(enemy.health > 0 && fighting) {
                    hero->takeDamage(enemy.attack);
                }
            }
            
            if(enemy.health <= 0) {
                rooms[currentRoom].isEnemy = false;
                hero->levelUp();
            }
        }
        
        if(rooms[currentRoom].isTreasure) {
            std::cout << "Ты нашел сокровище!\n";
            hero->health += 20;
            rooms[currentRoom].isTreasure = false;
        }
        
        if(playing) {
            currentRoom++;
            if(currentRoom >= static_cast<int>(rooms.size())) {
                std::cout << "Ты прошел подземелье!\n";
                playing = false;
            }
        }
    }
    
    if(hero->health <= 0) {
        std::cout << "Ты погиб...\n";
    }
    
    delete hero;
}

int main() {
    startGame();
    return 0;
}