// Copyright 2021 Vlad
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include "Cell.h"
#include "Object.h"
class Prey : public Object {
private:
    int reproduction;
    int timeToReproduction;
    int death;
    int timeTodeath;
public:
    Prey(Cell* cell, int reproduction, int death) : Object(cell, ObjType::PREY) {
        this->reproduction = reproduction;
        timeToReproduction = reproduction;
        this->death = death - 1;
        timeTodeath = death - 1;
    }
    void live() override;
    ~Prey() {}
};
#endif  // INCLUDE_PREY_H_
