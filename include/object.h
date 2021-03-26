// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include <map>
#include "common.h"

class Cell;

class Object {
 protected:
    Cell* cell;
    NATURE nature;
    unsigned int age;
    std::map<NATURE, unsigned int> longevity{{UNKNOWN, 0},
                                                {PREY, 20},
                                                {PREDATOR, 10},
                                                {STONE, 1000}};

    std::map<NATURE, unsigned int> breedingTime{{UNKNOWN, 0},
                                                  {PREY, 3},
                                                  {PREDATOR, 5},
                                                  {STONE, 0}};

    std::map<NATURE, unsigned int> eatTime{{UNKNOWN, 0},
                                                  {PREY, 0},
                                                  {PREDATOR, 2},
                                                  {STONE, 0}};

    std::map<NATURE, int> minTemperature{{UNKNOWN, 0},
                                                {PREY, -20},
                                                {PREDATOR, -25},
                                                {STONE, -100}};

    std::map<NATURE, int> maxTemperature{{UNKNOWN, 0},
                                                {PREY, 40},
                                                {PREDATOR, 35},
                                                {STONE, 250}};

 public:
    explicit Object(Cell* _cell = nullptr,
                    NATURE _nature = NATURE::UNKNOWN,
                    unsigned int _age = 0);
    ~Object();
    void setCell(Cell* _cell);
    void setNature(NATURE _nature);
    void setAge(unsigned int _age);
    Cell* getCell();
    NATURE getNature();
    unsigned int getAge();
    virtual void live();
};

#endif  // INCLUDE_OBJECT_H_
