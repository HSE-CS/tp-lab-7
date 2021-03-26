// Copyright Mushka Nikita 2021

#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "cell.h"
#include <list>
#include <vector>
#include "object.h"

class Ocean {
private:
    Cell **cells;
    std::vector<Object *> objects;
    unsigned int size;

public:


    explicit Ocean(unsigned int new_size);

    ~Ocean() = default;

    void print() const;

    void FillWithRandomObjects();

    unsigned int getSize() const;

    Object * getObject(Pair pair);

    Cell * getCell(Pair pair);

    void start();

    void addObject(Object *obj);

};

#endif