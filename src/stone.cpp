// Copyright 2021 Nikolaev Ivan

#include <iostream>
#include "../include/ocean.h"
#include "../include/stone.h"

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
