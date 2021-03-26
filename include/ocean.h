#ifndef _OCEAN_H_
#define _OCEAN_H_

#include <list>
#include "../include/common.h"
#include "../include/cell.h"

class Ocean
{
 private:
    Cell **cells;
    std::list<Object*> stuff;

 public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObjects(...);
    void run();
};
#endif