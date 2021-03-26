// Copyright dmitrycvetkov 2021
#ifndef _STONE_H_
#define _STONE_H_

#include "object.h"

class Stone : public Object {
 public:
    explicit Stone(std::weak_ptr<Cell> cell);

    void live() override;
    ObjType type() const override;
};

#endif  // _STONE_H_
