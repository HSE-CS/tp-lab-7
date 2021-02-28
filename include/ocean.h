// Copyright 2021 Stanislav Stoianov

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "common.h"
#include "Cell.h"
#include <list>

class Ocean {

private:
    Cell **cells;
    std::list<Object *> stuff;

public:
    Ocean();

    ~Ocean();

    void print() const;

    void addObjects(...);

    void run();
};

#endif  // INCLUDE_OCEAN_H_
