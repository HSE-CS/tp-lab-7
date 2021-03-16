//
// Created by freeb on 15.03.2021.
//

#ifndef TP_LAB_7_OCEAN_H
#define TP_LAB_7_OCEAN_H

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
    void  print() const;
    void addObjects(...);
    void  run();
};

#endif //TP_LAB_7_OCEAN_H
