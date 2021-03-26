// Copyright JMax 2021

#include <ctime>
#include <iostream>
#include "../include/Object.h"

Object::~Object() {
    this->cell = nullptr;
}

objectType Object::getType() const {
    return type;
}

void Object::changeCell(Cell *cell) {
    this->cell->clearMe();
    cell->setObject(this);
    this->cell = cell;
}

void Object::increaseAge() {
    age++;
}

char Object::getSymbol() {
    switch (type) {
        case PREY:
            return getSymbolByAging(PREY_LARGE_SYMBOL,
                                    PREY_SMALL_SYMBOL);
        case PREDATOR:
            return getSymbolByAging(PREDATOR_LARGE_SYMBOL,
                                    PREDATOR_SMALL_SYMBOL);
        case STONE:
            return getSymbolByAging(STONE_SMALL_SYMBOL,
                                    STONE_LARGE_SYMBOL);
        default:
            return NOTHING_SYMBOL;
    }
}

char Object::getSymbolByAging(char elder, char younger) const {
    if (age > DEATH_AGE / 2) {
        return elder;
    } else {
        return younger;
    }
}

bool Object::checkAge() const {
    return age < DEATH_AGE;
}

int Object::getRandom(int max) {
    unsigned int seed = time(nullptr);
    return rand_r(&seed) % max;
}

int Object::getSize() const {
    return size;
}

void Object::death() {
    if(isAlive()) {
        cell->killMe();
        cell = nullptr;
        alive = false;
    }
}

bool Object::isAlive() const {
    return alive;
}
