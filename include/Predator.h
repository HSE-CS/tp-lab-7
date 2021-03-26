// Copyright JMax 2021

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/Prey.h"
#include "../include/Common.h"
#include "../include/Cell.h"

class Predator : public Prey {
 private:
    double satiety = size;
    void move() override;
    void eat(Cell* dest, bool hasFriends);
    static bool isPrey(Cell* cell) ;
    bool isHungry() const;
    bool isVeryHungry() const;
    static std::vector<Cell*> uniteVectors(std::vector<Cell*> vector1,
                                           std::vector<Cell*> vector2);
    void decreaseSatiety();
    void eat(Cell* cell);
    static Cell* minPredator(Cell* cell1, Cell* cell2);
    static Cell* maxPredator(Cell* cell1, Cell* cell2);
    static Cell* roulette(Cell* predator1, Cell* predator2);

 public:
    explicit Predator(Cell* cell, int minSize = 1) : Prey(cell) {
        type = PREDATOR;
        size = getRandom(MAX_PREDATOR_SIZE - 1) + minSize;
    }
    void live() override;
};

#endif  // INCLUDE_PREDATOR_H_
