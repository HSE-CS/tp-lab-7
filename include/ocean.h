// Copyright 2021 Stanislav Stoianov

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "object.h"
#include "ocean.h"
#include "prey.h"
#include "predator.h"

// The possible moves
enum Move {
    UP = 0, DOWN, LEFT, RIGHT
};

// The size of this world
const int WORLDSIZE = 20;

// Number of initial ants
const int INITIAL_ANTS = 20;

// Number of initial bugs
const int INITIAL_BUGS = 5;

// Time steps between breeding of ants
const int BREED_ANTS = 3;

// Time steps between breeding of bugs
const int BREED_BUGS = 8;

// Time steps until bugs die if they have not eaten
const int STARVE_BUGS = 3;

struct Position {
    int x;
    int y;
};

class Ocean {
public:
    // Constructor: creates and initializes this world. the seed is used for
    // seeding the random behaviour.
    Ocean(unsigned int seed) {
        // seed the random generator
        srand(seed);
        // Create an empty world
        for (int i = 0; i < WORLDSIZE; i++) {
            for (int j = 0; j < WORLDSIZE; j++) {
                grid[i][j] = nullptr;
            }
        }
        // creates the ants = 3
        createOrganisms(ANT, INITIAL_ANTS);
        // creates the bugs = 8
        createOrganisms(BUG, INITIAL_BUGS);
    }

    // Destructor.
    ~Ocean() {
        for (int i = 0; i < WORLDSIZE; i++) {
            for (int j = 0; j < WORLDSIZE; j++) {
                if (grid[i][j] != nullptr) {
                    delete grid[i][j];
                }
            }
        }
    }

    // Returns the organism at the given coordinates.
    AbstractEntity *getAt(int x, int y) const {
        if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE)) {
            return grid[x][y];
        } else {
            return nullptr;
        }
    }

    // Sets the organism org at position (x,y).
    void setAt(int x, int y, AbstractEntity *org) {
        if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE)) {
            grid[x][y] = org;
        }
    }

    // Displays this world.
    void display() const {
        int numAnts = 0;
        int numBugs = 0;
        std::cout << std::endl << std::endl;
        for (int j = 0; j < WORLDSIZE; j++) {
            for (int i = 0; i < WORLDSIZE; i++) {
                if (grid[i][j] == nullptr) {
                    std::cout << ' ';
                } else {
                    if (grid[i][j]->getType() == ANT) {
                        numAnts++;
                    } else if (grid[i][j]->getType() == BUG) {
                        numBugs++;
                    }
                    std::cout << grid[i][j]->representation();
                }
            }
            std::cout << std::endl;
        }
        std::cout << "Ants: " << numAnts << " Bugs: " << numBugs << std::endl;
    }

    // Simulates one time step in this world.
    void simulateOneStep() {
        // The main routine that simulates one turn in the world:
        // 1. move bugs
        // 2. move ants
        // 3. make bugs starve (which happens under a certain condition)
        // 4. make the organisms breed (again which happens under a certain
        // condition).

        // Reset all organisms to not moved
        resetOrganisms();

        // Move the bugs
        moveOrganism(BUG);

        // Move the ants
        moveOrganism(ANT);

        // Make the bugs starve
        cleanup();

        //Make them breed
        breedOrganisms();
    }

    // Returns a random position in the grid.
    Position randomPosition() const {
        Position p;
        p.x = rand() % WORLDSIZE;
        p.y = rand() % WORLDSIZE;
        return p;
    }

    // Returns a random move (UP, DOWN, LEFT or RIGHT).
    Move randomMove() const {
        return static_cast<Move>(rand() % 4);
    }

private:
    // The grid in which the organisms live. According the to image below,
    // the correct iteration order through grid starts at the top left
    // corner (i.e. grid[0][0]), loops through one column at a time and ends
    // at the bottom right corner (i.e. grid[WORLDSIZE-1][WORLDSIZE-1]).
    //
    // grid[0, 0]          , grid[1, 0],      ...,      grid[WORLDSIZE-1, 0]
    // grid[0, 1]          , grid[1, 1],      ...,      grid[WORLDSIZE-1, 1]
    //    .                                                     .
    //    .                                                     .
    //    .                                                     .
    // grid[0, WORLDSIZE-2], grid[1, WORLDSIZE-2], ..., grid[WORLDSIZE-1, WORLDSIZE-2]
    // grid[0, WORLDSIZE-1], grid[1, WORLDSIZE-1], ..., grid[WORLDSIZE-1, WORLDSIZE-1]
    //
    // (See e.g. the destructor for correct iteration through the grid)
    AbstractEntity *grid[WORLDSIZE][WORLDSIZE]{};

    // Randomly create `count` many organisms of type `orgType`.  This
    // method uses the parameterized constructor in Prey and Predators.
    void createOrganisms(OrganismType orgType, int count) {
        int orgCount = 0;
        while (orgCount < count) {
            Position p = randomPosition();
            // Only put ant in empty spot
            if (grid[p.x][p.y] == nullptr) {
                orgCount++;
                if (orgType == ANT) {
                    new Prey(this, p.x, p.y);   // Create an Prey and put it into the world
                } else if (orgType == BUG) {
                    new Predators(this, p.x, p.y);   // Create a Predators and put it into the world
                }
            }
        }
    }

    // Reset all organisms to not moved. This is necessary because later we
    // iterate through the grid starting from the top left moving to the
    // bottom right looking for an organism to move. Say if an organism
    // moves down, we don't want to move the organism again when we reach
    // it.
    void resetOrganisms() {
        for (int i = 0; i < WORLDSIZE; i++) {
            for (int j = 0; j < WORLDSIZE; j++) {
                if (grid[i][j] != nullptr) {
                    grid[i][j]->setMoved(false);
                }
            }
        }
    }

    // Make every organisms in this world of type aType move. Make sure to
    // to iterate through grid in order as specified above and only move an
    // organism if it hasn't moved already.
    void moveOrganism(OrganismType aType) {
        for (int i = 0; i < WORLDSIZE; i++) {
            for (int j = 0; j < WORLDSIZE; j++) {
                if (grid[i][j] != nullptr) {
                    if (grid[i][j]->getType() == aType && !(grid[i][j]->hasMoved())) {
                        grid[i][j]->move();
                    }
                }
            }
        }
    }

    // Remove all dead organism from this world. Iterates through the grid
    // and uses the method AbstractEntity::isDead() to test if an organism is
    // dead. For this assignment in this method, only starved bugs will be
    // removed.
    void cleanup() {
        for (int i = 0; i < WORLDSIZE; i++) {
            for (int j = 0; j < WORLDSIZE; j++) {
                // Kill off any organisms that haven't eaten recently
                if ((grid[i][j] != nullptr) && grid[i][j]->isDead()) {
                    delete grid[i][j];
                    grid[i][j] = nullptr;
                }
            }
        }
    }

    // Make every organism in this world breed. Make sure to iterate
    // through grid in order as specified above and to only breed organisms
    // that have moved, since breeding places new organisms on the map we
    // don't want to try and breed those.
    void breedOrganisms() {
        for (int i = 0; i < WORLDSIZE; i++) {
            for (int j = 0; j < WORLDSIZE; j++) {
                if (grid[i][j] != nullptr) {
                    grid[i][j]->breed();
                }
            }
        }
    }
};

#endif  // INCLUDE_OCEAN_H_
