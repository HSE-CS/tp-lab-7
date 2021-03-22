
#ifndef TP_LAB_7_PREY_H
#define TP_LAB_7_PREY_H

#include "common.h"
#include "object.h"
#include "cell.h"

class Prey : public Object {
protected:
    ObjectType type = ObjectType::PREY;

public:
    static const unsigned int std_life_time = 10;
    Prey(Cell *c, unsigned int lt) : Object(c) {
        this->life_time = lt;
    };
    void live() override;

    virtual Cell *getNextCell();
    virtual void goToCell(Cell *c);

    char getCharacter() override { return 'f'; }
};


#endif //TP_LAB_7_PREY_H
