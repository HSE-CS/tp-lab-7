#ifndef TP_LAB_7_PREDATOR_H
#define TP_LAB_7_PREDATOR_H

#include "common.h"

class predator : public Object {
public:
    predator(int x, int y, int energy = startPredatorEnergy, int type = PREDATOR, Cell *cell = nullptr);

    virtual void live();

    virtual Object *divide();

    virtual char getFiller();
};


#endif //TP_LAB_7_PREDATOR_H
