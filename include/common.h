#ifndef TP_LAB_7_COMMON_H
#define TP_LAB_7_COMMON_H

#include <iostream>
#include <vector>
#include <random>
#include <string>

#define stone_symbol '#'
#define void_symbol ' '
#define prey_symbol '*'
#define predator_symbol 'X'

static const int width = 50;
static const int height = 50;

static const int startPreyEnergy = 100;
static const int startPredatorEnergy = 100;

enum ObjType {
    STONE,
    // CORAL,
    PREY,
    PREDATOR,
};

enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT,
};

class Cell;

class Object {
protected:
    int energy;
    int type;
    Cell *cell;
    int x;
    int y;
public:
    explicit Object(int x, int y, int energy, int type, Cell *cell);

    virtual void live() = 0;

    virtual Object *divide() = 0;

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getEnergy() const;

    void setEnergy(int energy);

    int getType() const;

    void setType(int type);

    Cell *getCell() const;

    virtual char getFiller() = 0;

    void setCell(Cell *cell);
};

Object::Object(int x1, int y1, int energy1, int type1, Cell *cell1) {
    this->x = x1;
    this->y = y1;
    this->energy = energy1;
    this->type = type1;
    this->cell = cell1;
}

int Object::getX() const {
    return x;
}

void Object::setX(int x1) {
    Object::x = x1;
}

int Object::getY() const {
    return y;
}

void Object::setY(int y1) {
    Object::y = y1;
}

int Object::getEnergy() const {
    return energy;
}

void Object::setEnergy(int energy1) {
    Object::energy = energy1;
}

int Object::getType() const {
    return type;
}

void Object::setType(int type1) {
    Object::type = type1;
}

Cell *Object::getCell() const {
    return cell;
}

void Object::setCell(Cell *cell1) {
    Object::cell = cell1;
}

#endif //TP_LAB_7_COMMON_H
