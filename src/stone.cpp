#include "stone.h"

void Stone::set_time() {
    this->time = 1;
}

void Stone::set_objType() {
    this->objType = 0;
}

int Stone::get_objType() {
    return this->objType;
}


// жизнь объекта
void Stone::live() {
    time++;
    if (time == 100000) {
        int res = rand() % 2;
        if (res)
            time = 1;
        else {
            this->die();
        }
    }
}

void Stone::print_object() {
    std::cout << STONE_N;
}

void Stone::setCell(Cell* c) {
    this->cell = c;
}

void Stone::init(Cell* c) {
    this->set_time();
    this->set_objType();
    this->setCell(c);
}

void Stone::die() {
    this->cell->killMe(this);
    this->objType = -1;
}