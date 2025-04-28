#include <iostream>
#include "Item.h"

Item::Item(std::string name, std::string description, bool isConsumable) : name(name), description(description), isConsumable(isConsumable) {}

void Item::use() {
    if (isConsumable) {
        std::cout << name << " was used!" << std::endl;
    } else {
        std::cout << name << " cannot be used directly." << std::endl;
    }
}
void Item::inspect()
{
    std::cout << "Name: " << name << "\n"
              << "Description: " << description << std::endl;

}
void Item::drop() {
    std::cout << name << " was dropped." << std::endl;
}
void Item::upgrade() {
    std::cout << name << " was upgraded!" << std::endl;
}