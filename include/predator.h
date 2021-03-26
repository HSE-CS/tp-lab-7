// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_
#include <string>
#include "../include/prey.h"

class Predator : public Prey {
 public:
    Predator();
    explicit Predator(int health);
    void live();
    void move();
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
