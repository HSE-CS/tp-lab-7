#ifndef TP_LAB_7_PREDATOR_H
#define TP_LAB_7_PREDATOR_H

#include "common.h"
#include "ocean.h"
#include "prey.h"
#include "object.h"
#include "cell.h"

class Predator : public Prey {
protected:
    ObjectType type = ObjectType::PREDATOR;

public:
    static const unsigned int std_life_time = 20;
    Predator(Cell *c, unsigned int lt) : Prey(c, lt) {};
    void live() override;

    Cell *getNextCell();
    void goToCell(Cell *c);

    char getCharacter() override { return 'S'; }
};


#endif //TP_LAB_7_PREDATOR_H
