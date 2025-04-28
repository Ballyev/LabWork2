#ifndef SCROLL_H
#define SCROLL_H
#include <iostream>
#include "Item.h"

class Scroll : public Item
{
    public:
    int effect;
    int uses;
    

    Scroll(std::string name, std::string description, bool isConsumable, int uses, int effect);
    
    void castEffect();
    void revealSecrets();

    ~Scroll() = default;
};

#endif