#ifndef TP_LAB_7_OCEAN_H
#define TP_LAB_7_OCEAN_H

#include "common.h"

class Ocean {
private:
    std::vector<std::vector<Cell *>> water;
public:
    explicit Ocean();

    void renderOcean();

    void init(int stones, int preys, int predators);

    void run(int iterations = -1);

    bool isConditionOkay();

    Cell *getCell(int x, int y);
};


#endif //TP_LAB_7_OCEAN_H
