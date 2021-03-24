#ifndef _STONE_H_
#define _STONE_H_

#include "object.h"

class Stone : public Object {
public:
    Stone(Cell* = nullptr);
    virtual void live();
};

#endif