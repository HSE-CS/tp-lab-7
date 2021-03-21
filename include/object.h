#ifndef TP_LAB_7_OBJECT_H
#define TP_LAB_7_OBJECT_H

#include "common.h"

enum class ObjectType { STONE, CORAL, PREY, PREDATOR };

class Cell;

class Object {
protected:
    Cell *cell;
    unsigned int life_time;
public:
    static const unsigned int std_life_time = 0;
    explicit Object(Cell * cell= nullptr);
    virtual ~Object();
    virtual void live() = 0;
    void setCell(Cell *c);
    Cell *getCell();
    virtual char getCharacter() { return 'O'; }
};

#endif //TP_LAB_7_OBJECT_H
