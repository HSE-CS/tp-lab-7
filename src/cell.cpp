#include "../include/cell.h"
#include "../include/Ocean.h"

int Cell::getX() const {
    return x;
}

void Cell::setX(int x1) {
    Cell::x = x1;
}

int Cell::getY() const {
    return y;
}

void Cell::setY(int y1) {
    Cell::y = y1;
}

Object *Cell::getObject() const {
    return object;
}

void Cell::setObject(Object *object1) {
    Cell::object = object1;
}

Ocean *Cell::getOcean() const {
    return ocean;
}

void Cell::setOcean(Ocean *ocean1) {
    Cell::ocean = ocean1;
}

Cell *Cell::getUp() {
    return this->ocean->getCell(this->x, (this->y - 1 + height) % height);
}

Cell *Cell::getRight() {
    return this->ocean->getCell((this->x + 1) % width, this->y);
}

Cell *Cell::getDown() {
    return this->ocean->getCell(this->x, (this->y + 1 + height) % height);
}

Cell *Cell::getLeft() {
    return this->ocean->getCell((this->x - 1 + width) % width, this->y);
}

void Cell::kill() {
    this->object = nullptr;
}

Cell::Cell(int x1, int y1, Object *object1, Ocean *ocean1) {
    this->x = x1;
    this->y = y1;
    this->object = object1;
    this->ocean = ocean1;
}
