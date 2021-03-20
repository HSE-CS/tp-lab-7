// Copyright 2021 Stanislav Stoianov

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "object.h"
#include "ocean.h"
#include "prey.h"
#include "predator.h"

enum OrganismType {
    ANT, BUG
};

// forward declaration
class Ocean;

class AbstractEntity {
public:
    // Create an organism at the given coordinates.
    AbstractEntity(Ocean *aWorld, int x, int y) {
        world = aWorld;
        this->x = x;
        this->y = y;
        breedTicks = 0;
        moved = false;
        world->setAt(x, y, this);
    }

    virtual ~AbstractEntity() {}

    // In the given world moves this organism.
    virtual void move() = 0;

    // Makes this organism breed.
    virtual void breed() = 0;

    // Returns the type of this organism.
    virtual OrganismType getType() const = 0;

    // Flags this organism as moved or not.
    void setMoved(bool hasMoved) {
        moved = hasMoved;
    }

    // The character representation of this organism.
    virtual char representation() const = 0;

    // The size of this organism.
    virtual int size() const = 0;

    // Has this organism moved in this time slot or not?
    bool hasMoved() const {
        return moved;
    }

    // Returns true if organism is dead, false otherwise.
    virtual bool isDead() const {
        return false;
    }

    static bool in_range(int xx, int yy) {
        return (xx >= 0) && (xx < WORLDSIZE) && (yy >= 0) && (yy < WORLDSIZE);
    }

protected:
    // Generates an offspring at the given position.
    virtual void generateOffspring(int whereX, int whereY) = 0;

    // Moves this organism from coordinates (x,y) to (xNew,yNew).
    void movesTo(int xNew, int yNew) {
        world->setAt(xNew, yNew, world->getAt(x, y));
        world->setAt(x, y, nullptr);
        x = xNew;
        y = yNew;
        world->getAt(x, y)->setMoved(true);
    }

    // Breeds a new organism at an adjacent cell. Tries to produce one new
    // organism in UP, DOWN, LEFT, or RIGHT cell (in that order).  Makes
    // sure not to breed off the grid.
    void breedAtAdjacentCell() {
        if ((world->getAt(x, y + 1) == nullptr) && in_range(x, y + 1)) {
            generateOffspring(x, y + 1);
        } else if ((world->getAt(x, y - 1) == nullptr) && in_range(x, y - 1)) {
            generateOffspring(x, y - 1);
        } else if ((world->getAt(x - 1, y) == nullptr) && in_range(x - 1, y)) {
            generateOffspring(x - 1, y);
        } else if ((world->getAt(x + 1, y) == nullptr) && in_range(x + 1, y)) {
            generateOffspring(x + 1, y);
        }
    }

    // This organism's x position in the world.
    int x;

    // This organism's y position in the world.
    int y;

    // Has moved this turn?
    bool moved;

    // Number of ticks since breeding.
    int breedTicks;

    // A pointer to the world in which this organism lives.
    Ocean *world;
private:
};

#endif  // INCLUDE_OBJECT_H_
