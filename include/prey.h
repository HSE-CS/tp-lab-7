// Copyright 2021 Stanislav Stoianov

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include <iostream>
#include "object.h"
#include "ocean.h"
#include "prey.h"
#include "predator.h"

class Prey : public AbstractEntity {
public:
    Prey(Ocean *aWorld, int x, int y);

    // In the given world moves this organism.
    void move() override;

    // Makes this organism breed.
    void breed() override;

    // Returns the type of this organism.
    OrganismType getType() const override;

    // The character representation of this organism.
    char representation() const override;

    // The size of this organism.
    int size() const override;

    bool in_range(int xx, int yy);

private:
    void generateOffspring(int whereX, int whereY) override;
};

#endif  // INCLUDE_PREY_H_
