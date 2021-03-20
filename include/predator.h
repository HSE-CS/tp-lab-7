// Copyright 2021 Stanislav Stoianov

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include <iostream>
#include "object.h"
#include "prey.h"
#include "ocean.h"
#include "predator.h"

class AbstractEntity;

class Predators : public AbstractEntity {
public:
    Predators(Ocean *aWorld, int x, int y) : AbstractEntity(aWorld, x, y) {
        death_tik = 0;
    }    // In the given world moves this organism.
    void move() override {
        breedTicks++;
        death_tik++;

        if (world->getAt(x, y + 1) != nullptr) {
            if (world->getAt(x, y + 1)->getType() == ANT) {
                death_tik = 0;
                delete world->getAt(x, y + 1);
                movesTo(x, y + 1);
                return;
            }
        }

        if (world->getAt(x, y - 1) != nullptr) {
            if (world->getAt(x, y - 1)->getType() == ANT) {
                death_tik = 0;
                delete world->getAt(x, y - 1);
                movesTo(x, y - 1);
                return;
            }
        }

        if (world->getAt(x - 1, y) != nullptr) {
            if (world->getAt(x - 1, y)->getType() == ANT) {
                death_tik = 0;
                delete world->getAt(x - 1, y);
                movesTo(x - 1, y);
                return;
            }
        }
        if (world->getAt(x + 1, y) != nullptr) {
            if (world->getAt(x + 1, y)->getType() == ANT) {
                death_tik = 0;
                delete world->getAt(x + 1, y);
                movesTo(x + 1, y);
                return;
            }
        }

        Move mover = world->randomMove();
        switch (mover) {
            case UP:
                if (world->getAt(x, y + 1) == nullptr && in_range(x, y + 1)) {
                    movesTo(x, y + 1);
                }
                break;
            case DOWN:
                if (world->getAt(x, y - 1) == nullptr && in_range(x, y - 1)) {
                    movesTo(x, y - 1);
                }
                break;
            case LEFT:
                if (world->getAt(x - 1, y) == nullptr && in_range(x - 1, y)) {
                    movesTo(x - 1, y);
                }
                break;
            case RIGHT:
                if (world->getAt(x + 1, y) == nullptr && in_range(x + 1, y)) {
                    movesTo(x + 1, y);
                }
                break;
            default:
                break;
        }
    }

    // Makes this organism breed.
    void breed() override {
        if (breedTicks >= BREED_BUGS) {
            breedAtAdjacentCell();
        }
    }

    // Returns the type of this organism.
    OrganismType getType() const override {
        return BUG;
    }

    // The character representation of this organism.
    char representation() const override {
        return 'S';
    }

    // The size of this organism.
    int size() const override {
        return 30;

    }

    // Returns true if organism is dead, false otherwise.
    bool isDead() const override {
        if (death_tik >= STARVE_BUGS) {
            return true;
        } else {
            return false;
        }
    }

    static bool in_range(int xx, int yy) {
        return (xx >= 0) && (xx < WORLDSIZE) && (yy >= 0) && (yy < WORLDSIZE);

    }

private:
    void generateOffspring(int whereX, int whereY) override {
        new Predators(this->world, whereX, whereY);
        breedTicks = 0;
    }

    int death_tik;
};

#endif  // INCLUDE_PREDATOR_H_
