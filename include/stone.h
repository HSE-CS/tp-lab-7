#ifndef TP_LAB_7_STONE_H
#define TP_LAB_7_STONE_H

#include "common.h"

class stone : public Object {
public:
    explicit stone(int x, int y, int type = STONE, int energy = -1, Cell *cell = nullptr);

    virtual void live();  // do nothing

    virtual Object* divide();  // do nothing

    virtual char getFiller();
};

#endif //TP_LAB_7_STONE_H
