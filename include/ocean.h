// Copyright [2020] <Olesya Nikolaeva>

#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "cell.h"
#include <list>

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
};

#endif  //  INCLUDE_OCEAN_H_
