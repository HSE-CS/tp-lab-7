// Copyright dmitrycvetkov 2021
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"

class Stone : public Object {
 public:
    explicit Stone(std::weak_ptr<Cell> cell);

    void live() override;
    ObjType type() const override;
};

#endif  // INCLUDE_STONE_H_
