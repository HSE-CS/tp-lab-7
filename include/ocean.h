// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include "common.h"
#include "cell.h"

class Ocean {
 private:
    Cell **cells;
    
 protected:
    std::list<Object*> stuff;

 public:
    Ocean();
    ~Ocean();
    void createOcean(int, int, int);
    void print() const;
    void addObjects(Object*);
    void run();
    void deleteObject(Object*);
    ObjType returnObjectAtSpecificPos(Pair);
    bool returnCellStatus(Pair);
    Cell* returnCell(Pair);
};

#endif  //  INCLUDE_OCEAN_H_
