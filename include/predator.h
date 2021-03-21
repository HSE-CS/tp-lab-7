#ifndef TP_LAB_7_PREDATOR_H
#define TP_LAB_7_PREDATOR_H

#include "common.h"
#include "prey.h"
#include "cell.h"
#include "object.h"

class Predator : public Prey {
public:
    static const unsigned int std_life_time = 20;
    Predator(Cell *c, unsigned int lt) : Prey(c, lt) {};
    void live() override;

    Cell *getNextCell();
    void goToCell(Cell *c);

    char getCharacter() { return 'S'; }
};


#endif //TP_LAB_7_PREDATOR_H
