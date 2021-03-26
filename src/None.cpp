//  Copyright 2021 Nikita Naumov

#include "../include/None.h"
#include "../include/ocean.h"

void None::setType() {
    this->type = ObjType::NONE;
}
None::None(Cell *thisCell) : Object(thisCell) {
    this->cell = thisCell;
    this->setType();
}
void None::live() {
    return;
}
