#include <iostream>
#include "../include/obj/Scroll.h"

Scroll::Scroll(const std::string &name, std::string description, bool isConsumable,const unsigned int _uses, const int &effect)
    : Item(name, description, isConsumable),
      effect(effect), uses(_uses), description(std::move(description)) {
}

void Scroll::castEffect() {
    if (uses > 0) {
        std::cout << name << " активирован! Эффект: " << effect << std::endl;
        uses--;

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