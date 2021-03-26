// Copyright 2021 Vlad
#ifndef INCLUDE_PREDACTOR_H_
#define INCLUDE_PREDACTOR_H_
#include "Cell.h"
#include "Object.h"
class Predactor : public Object {
private:
    bool isHungry = true;
    int death;
    int reproduction;
    int timeTodeath;
    int timeToReproduction;
public:
    Predactor(Cell* cell, int reproduction, int death) : Object(cell, ObjType::PREDATOR) {
        this->death = death;
        this->reproduction = reproduction;
        timeToReproduction = reproduction;
        timeTodeath = death;
    }
    void live() override;
    virtual Cell* FindPrey();
    ~Predactor() {}

};
#endif  // INCLUDE_PREDACTOR_H_
