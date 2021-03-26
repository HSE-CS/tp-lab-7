// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_
#include "../include/object.h"
class Cell;

class Predator : public Object {
    friend Cell;
private:
    bool isHungry;
public:
    explicit Predator(Cell* c);
    ~Predator() {}
    void live();
    void move();
    void eat();
    void makeChild();
    char getSymbol();
};

#endif  // INCLUDE_PREDATOR_H_
