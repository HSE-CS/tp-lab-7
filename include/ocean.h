// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "../include/common.h"
#include "../include/cell.h"

class Ocean {
 private:
    std::vector<std::vector<Cell*>> cells;
    std::list<Object*> stuff;
 public:
    Ocean(unsigned int x_len, unsigned int y_len);
    ~Ocean();
    void print();
    void addObject(Object * object);
    void addObjects(std::list<Object *> lst);
    void run();
    Cell *get(unsigned int x, unsigned int y);
    void setObjectOnCell(Object *object, Cell *cell);
    void setObjectOnCell(Object *object, int i, int j);
    unsigned int lenX();
    unsigned int lenY();
    Object *removeFromStuff(Object *obj);
    std::map<ObjectType, unsigned int> getObjectsCount();
};

#endif  // INCLUDE_OCEAN_H_
