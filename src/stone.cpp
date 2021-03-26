// Copyright 2021 Nikolaev Ivan

#include "ocean.h"
#include "stone.h"
#include <iostream>

Stone::Stone() {
}

Stone::~Stone() {
    this->cell = nullptr;
}
void Stone::live() {
    return;
}

char Stone::getSymbol() {
    return symbol;
}

void Stone::die() {
}
