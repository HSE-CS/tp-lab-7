// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include <string>
#include "../include/object.h"

class Prey : public Object {
    friend Object;
 public:
    Prey();
    explicit Prey(int health);
    void live() override;
    void move();
    bool moveTo(int x, int y);
    bool searchSexualPartner();
    void leaveOffspring(int x, int y);
    char getSymbol();
    void changeCell(int x, int y);
    bool checkPosition(int x, int y);
    bool checkCellForReproduce(int x, int y);
    void die();
 protected:
    char symbol = 'f';
 private:
    int health = 10;
    int maxHealth = 10;
    bool abilityToReproduce = false;
};

#endif  // INCLUDE_PREY_H_
