// copyright 2021 Victor Shatilov

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/common.h"

class Ocean;

class Cell {
 private:
    int x, y;
    Object *object;
    Ocean *ocean;

 public:
    explicit Cell(int x, int y, Object *object1 = nullptr,
                  Ocean *ocean = nullptr);

    void kill();

    Cell *getUp();

    Cell *getRight();

    Cell *getDown();

    Cell *getLeft();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    Object *getObject() const;

    void setObject(Object *object);

    Ocean *getOcean() const;

    void setOcean(Ocean *ocean);
};

#endif  // INCLUDE_CELL_H_
