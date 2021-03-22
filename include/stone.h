#ifndef TP_LAB_7_STONE_H
#define TP_LAB_7_STONE_H

#include "common.h"
#include "object.h"
#include "cell.h"

class Stone : public Object{
protected:
    ObjectType type = ObjectType::STONE;

public:
    static const unsigned int std_life_time = 1;
    Stone(Cell *c) : Object(c) {
        this->life_time = 1;
    };
    void live() override;
    char getCharacter() override { return '.'; }
};


#endif //TP_LAB_7_STONE_H
