//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_STONE_H
#define INCLUDE_STONE_H

#include "../include/Object.h"

class Stone : public Object {
 private:
    int lifespan = 0;

 public:
    Stone(Cell* thisCell) : Object(thisCell) {
        this->cell = thisCell;
        this->lifespan = std::rand()%1001;
    };
    void live() override;
    void setType() override;
};

class Coral : public Object {
 private:
    int lifespan = 0;

 public:
    Coral(Cell* thisCell) : Object(thisCell) {
        this->cell = thisCell;
        this->lifespan = 0;
    }
    void live() override;
    void setType() override;
};

#endif  //  INCLUDE_STONE_H