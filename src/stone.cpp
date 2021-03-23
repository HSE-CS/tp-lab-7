// Copyright 2021 Dmitry Vargin
#include "../include/stone.h"

void Stone::live() {
    if (this->life_time < 1) {
        this->cell->setObject(nullptr);
        delete this;
    }
}
