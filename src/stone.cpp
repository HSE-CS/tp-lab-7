// Copyright 2021 Ilya Urtyukov
#include "stone.h"

void STONE::live() {
    fastness -= std::rand() % 1;
    if (fastness == 0) {
        cell->setObject(nullptr);
    }
}

int STONE::getFastness() {
    return fastness;
}
