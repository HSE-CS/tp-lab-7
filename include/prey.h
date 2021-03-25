#ifndef TP_LAB_7_PREY_H
#define TP_LAB_7_PREY_H

#include "common.h"

class prey : public Object {
public:
    prey(int x, int y, int energy = startPreyEnergy, int type = PREY, Cell *cell = nullptr);

    virtual void live();

    virtual Object *divide();

    virtual char getFiller();
};


#endif //TP_LAB_7_PREY_H
