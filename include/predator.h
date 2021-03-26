// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_
#include <string>
#include "prey.h"

class Predator : public Prey {
public:
    Predator();
    Predator(int health);
    void live();
    void move();
//    bool moveTo();
    void leaveOffspring(int x, int y);
    Pair eat();
    void die();
    char getSymbol();
protected:
    char symbol = 'S';
private:
    int health = 10;
    int maxHealth = 10;
    int satiety = 10;
    bool abilityToReproduce = false;
};

#endif  // INCLUDE_PREDATOR_H_
