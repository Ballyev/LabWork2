#include <iostream>
#include "Scroll.h"

Scroll::Scroll(std::string name, std::string description, bool isConsumable, int uses,int effect) : Item(name, description, isConsumable) {}

    void Scroll::castEffect() {
        if (uses > 0) {
            std::cout << name << " активирован! Эффект: " << effect << std::endl;
            uses--; // Уменьшает количество использований

            if (isConsumable && uses == 0) {
                std::cout << name << " исчез после использования!" << std::endl;
            }
        } else {
            std::cout << name << " больше не имеет зарядов." << std::endl;
        }
    }

    
    void Scroll::revealSecrets() {
        std::cout << name << " раскрывает тайны..." << std::endl;
        if (uses > 0) {
            effect += 10;
            std::cout << "Эффект усилился: " << effect << std::endl;
        } else {
            std::cout << "Но свиток уже использован." << std::endl;
        }
    }
        
    
