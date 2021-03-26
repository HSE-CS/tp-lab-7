// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include "common.h"
#include "cell.h"

class Ocean {
 private:
    Cell **cells;
    std::list<Object*> stuff;

 public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObjects(Object*);
    void run();
    bool returnCellStatus(Pair);
    Cell* returnCell(Pair);
};

#endif  //  INCLUDE_OCEAN_H_
