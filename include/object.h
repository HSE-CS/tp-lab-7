#ifndef TP_LAB_7_OBJECT_H
#define TP_LAB_7_OBJECT_H

#include "common.h"

class Cell;

class Object {
protected:
    ObjectType type = ObjectType::OBJECT;
public:
    Cell *cell;
    unsigned int life_time;
    static const unsigned int std_life_time = 0;
    explicit Object(Cell * cell= nullptr);
    virtual ~Object();
    virtual void live() = 0;
    void setCell(Cell *c);
    Cell *getCell();
    virtual char getCharacter() { return 'O'; }
    ObjectType getType() {return type; }
};

#endif //TP_LAB_7_OBJECT_H
