// Copyright 2021 MalininDmitry
#include <random>
#include <vector>
#include <iostream>
#include "prey.h"
#include "cell.h"
#include "object.h"
#include "ocean.h"

Prey::~Prey() {
}

Prey::Prey(int live_count, int time_reproduction,
           Cell * cell, ObjType type) :
    Object(cell, type) {
    this->live_count = live_count;
    this->time_reproduction = time_reproduction;
    this->type = type;
}

void Prey::live() {
    int x = cell->getCrd().x;
    int y = cell->getCrd().y;
    if (live_count-- > 0) {
        curr_time++;
        go();
        if ((live_count > 0) &&
            (time_reproduction == curr_time) &&
            (!cell->getOcean()->getCells()[x][y].
             getObject())) {
            cell->getOcean()->getCells()[x][y].setObject(new Prey{live_count+curr_time,
                time_reproduction,
                &(cell->getOcean()->
                getCells()[x][y]),
                ObjType::PREY});
            cell->getOcean()->addObjects(cell->getOcean()->
                        getCells()[x][y].getObject());
        }
    } else {
        cell->getOcean()->deleteObjects(cell->
            getOcean()->getCells()[x][y].getObject());
        delete this;
        cell->getOcean()->getCells()[x][y].killMe();
    }
}

void Prey::go() {
    int x = cell->getCrd().x;
    int y = cell->getCrd().y;\
    
    std::vector<Pair> newWays;
    if ( ((x-1) >= 0) && ((y-1) >= 0) && (!cell->
        getOcean()->getCells()[x-1][y-1].
                                    getObject()) ) {
        newWays.push_back(Pair{(size_t) (x-1),
            (size_t) (y-1)});
    }  // x-1; y-1
    if ( ((y-1) >= 0) && (!cell->getOcean()->
                       getCells()[x][y-1].getObject()) ) {
        newWays.push_back(Pair{(size_t) (x),
            (size_t) (y-1)});
    }  // x y-1
    if ( ((x+1) < M) && ((y-1) >= 0) && (!cell->getOcean()->
        getCells()[x+1][y-1].getObject()) ) {
        newWays.push_back(Pair{(size_t) (x+1),
            (size_t) (y-1)});
    }  // x+1; y-1
    if ( ((x-1) >= 0) && (!cell->getOcean()->
                getCells()[x-1][y].getObject()) ) {
        newWays.push_back(Pair{(size_t) (x-1),
            (size_t) (y)});
    }  // x-1; y
    if ( ((x+1) < M) && (!cell->getOcean()->
                getCells()[x+1][y].getObject()) ) {
        newWays.push_back(Pair{(size_t) (x+1),
            (size_t) (y)});
    }  // x+1; y
    if ( ((x-1) >= 0) && ((y+1) < N) && (!cell->
                getOcean()->getCells()[x-1][y+1].
                        getObject()) ) {
        newWays.push_back(Pair{(size_t) (x-1),
            (size_t) (y+1)});
    }  // x-1; y+1
    if ( ((y+1) < N) && (!cell->getOcean()->
                getCells()[x][y+1].getObject()) ) {
        newWays.push_back(Pair{(size_t) (x),
            (size_t) (y+1)});
    }  // x; y+1
    if ( ((x+1) < M) && ((y+1) < N) && (!cell->
                    getOcean()->getCells()[x+1][y+1].
                        getObject()) ) {
        newWays.push_back(Pair{(size_t) (x+1),
            (size_t) (y+1)});
    }  // x+1; y+1
    if (!newWays.empty()) {
        int r = rand() % newWays.size();
        coord_t x_coor = newWays[r].x;
        coord_t y_coor = newWays[r].y;
        this->setCell(&(cell->getOcean()->
        getCells()[x_coor][y_coor]));

        cell->getOcean()->getCells()[x_coor][y_coor].
        setObject(this);
        cell->getOcean()->getCells()[x][y].killMe();
    }
}
