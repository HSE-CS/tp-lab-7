// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "object.h"

class Prey : public Object {
 public:
    explicit Prey(Cell* _cell = nullptr,
                   NATURE _nature = NATURE::PREY,
                   unsigned int _age = 0);
    ~Prey() override;
    void live() override;
    void swim();
    void breed();
};

#endif  // INCLUDE_PREY_H_
