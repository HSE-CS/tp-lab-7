// copyright 2021 Victor Shatilov

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

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
    explicit Object(int x1, int y1, int energy1,
                    int type1, Cell *cell1) {
        this->x = x1;
        this->y = y1;
        this->energy = energy1;
        this->type = type1;
        this->cell = cell1;
    }

    virtual void live() = 0;

    virtual Object *divide() = 0;

    virtual char getFiller() = 0;

    int getX() const {
        return x;
    }

    void setX(int x1) {
        Object::x = x1;
    }

    int getY() const {
        return y;
    }

    void setY(int y1) {
        Object::y = y1;
    }

    int getEnergy() {
        return energy;
    }

    void setEnergy(int energy1) {
        Object::energy = energy1;
    }

    int getType() const {
        return type;
    }

    void setType(int type1) {
        Object::type = type1;
    }

    Cell *getCell() const {
        return cell;
    }

    void setCell(Cell *cell1) {
        Object::cell = cell1;
    }
};

#endif  // INCLUDE_COMMON_H_
