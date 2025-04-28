#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
    public:

    Item(std::string name, std::string description, bool isConsumable);


    std::string name;
    std::string description;
    bool isConsumable;

    
    void use();
    void inspect();
    void drop();
    void upgrade();

    ~Item() = default;
};



#endif