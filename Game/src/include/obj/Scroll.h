#ifndef SCROLL_H
#define SCROLL_H
#include "Item.h"
#include "../Hero/Hero.h"

class Scroll : public Item {
public:
    int effect;
    unsigned int uses;
    std::string description;


    Scroll(const std::string &name, std::string description, bool isConsumable,const unsigned int _uses, const int &effect);

    void castEffect();

    void revealSecrets();

    ~Scroll() = default;
};

#endif
