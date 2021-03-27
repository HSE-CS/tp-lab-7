//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_NONE_H_
#define INCLUDE_NONE_H_

#include "Object.h"

class None : public Object {
 public:
    explicit None(Cell* thisCell);
    void live() override;
    void setType() override;
};

#endif  //  INCLUDE_NONE_H_
