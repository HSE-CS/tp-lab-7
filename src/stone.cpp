//  Copyright 2021 Nikita Naumov

#include "../include/stone.h"

void Stone::live() {
    if (lifespan == 0) {
        this->cell->killMe();
    }
}
void Stone::setType() {
    this->type = static_cast<ObjType>(1);  //  Stone is a stone
}

void Coral::live() {
    if (lifespan == 36) {
        int x = this->cell->getX(), y = this->cell->getY();
        if (true);
    } else {
        ++lifespan;
    }
}

void Coral::setType() {
    this->type = static_cast<ObjType>(2);
}