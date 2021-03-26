//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_NONE_H
#define INCLUDE_NONE_H

#include "Object.h"

class None : public Object {
 public:
    None(Cell* thisCell);
    void live() override;
    void setType() override;
};

#endif  //  INCLUDE_NONE_H