// Copyright JMax 2021

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/Common.h"
#include "../include/Object.h"

class Stone : public Object {
 private:
    int deathAge = DEATH_AGE * (getRandom(DEATH_AGE) + 1);
    bool checkAge();

 public:
    explicit Stone(Cell* cell) : Object(STONE, cell) {}
    void live() override;
};

#endif  // INCLUDE_STONE_H_
