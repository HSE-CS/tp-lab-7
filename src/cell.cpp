//  Copyright 2021 Nikita Naumov

#include "cell.h"


Object * Cell::getObject() const {

}
void Cell::init(Pair p, Ocean *ocean) {
    this->coordinates = p;
    this->ocean = ocean;
}
void Cell::setObject(Object* objToSet) {
    this->object = objToSet;
}

void Cell::killMe() {
    this->object = nullptr;
}
bool Cell::isFree() {
    if (this->object) {
        return false;
    }
    return true;
}