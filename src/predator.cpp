// Copyright 2021 MalininDmitry
#include <random>
#include <iostream>
#include <vector>
#include "prey.h"
#include "predator.h"
#include "cell.h"
#include "object.h"
#include "ocean.h"

Predator::Predator(int live_count, int time_reproduction, Cell * cell, int satiety, int deathByStarvation, ObjType type) :
    Prey(live_count, time_reproduction, cell, type) {
    this->satiety = satiety;
    this->deathByStarvation = deathByStarvation;
}


void Predator::go() {
    int x = cell->getCrd().x;
    int y = cell->getCrd().y;
    std::vector<Pair> preyPlaces;
    if( ((x-1)>=0) && ((y-1)>=0) && ((cell->getOcean()->getCells())[x-1][y-1].getObject()) && (cell->getOcean()->getCells()[x-1][y-1].getObject()->getType() == ObjType::PREY) ) {
        preyPlaces.push_back(Pair{(size_t) (x-1),
            (size_t) (y-1)});
    } // x-1; y-1
    if( ((y-1)>=0) && (cell->getOcean()->getCells()[x][y-1].getObject()) && (cell->getOcean()->getCells()[x][y-1].getObject()->getType() == ObjType::PREY) ) {
        preyPlaces.push_back(Pair{(size_t) (x),
            (size_t) (y-1)});
    } // x y-1
    if( ((x+1)<M) && ((y-1)>=0)&& (cell->getOcean()->getCells()[x+1][y-1].getObject()) && (cell->getOcean()->getCells()[x+1][y-1].getObject()->getType() == ObjType::PREY) ) {
        preyPlaces.push_back(Pair{(size_t) (x+1),
            (size_t) (y-1)});
    } // x+1; y-1
    if( ((x-1)>=0)&& (cell->getOcean()->getCells()[x-1][y].getObject()) && (cell->getOcean()->getCells()[x-1][y].getObject()->getType() == ObjType::PREY) ) {
        preyPlaces.push_back(Pair{(size_t) (x-1),
            (size_t) (y)});
    } // x-1; y
    if( ((x+1)<M)&& (cell->getOcean()->getCells()[x+1][y].getObject()) && (cell->getOcean()->getCells()[x+1][y].getObject()->getType() == ObjType::PREY) ) {
        preyPlaces.push_back(Pair{(size_t) (x+1),
            (size_t) (y)});
    } // x+1; y
    if( ((x-1)>=0) && ((y+1)<N)&& (cell->getOcean()->getCells()[x-1][y+1].getObject()) && (cell->getOcean()->getCells()[x-1][y+1].getObject()->getType() == ObjType::PREY) ) {
        preyPlaces.push_back(Pair{(size_t) (x-1),
            (size_t) (y+1)});
    } // x-1; y+1
    if( ((y+1)<N)&& (cell->getOcean()->getCells()[x][y+1].getObject()) && (cell->getOcean()->getCells()[x][y+1].getObject()->getType() == ObjType::PREY) ) {
        preyPlaces.push_back(Pair{(size_t) (x),
            (size_t) (y+1)});
    } // x; y+1
    if( ((x+1)<M) && ((y+1)<N)&& (cell->getOcean()->getCells()[x+1][y+1].getObject()) && (cell->getOcean()->getCells()[x+1][y+1].getObject()->getType() == ObjType::PREY) ) {
        preyPlaces.push_back(Pair{(size_t) (x+1),
            (size_t) (y+1)});
    } // x+1; y+1
    if (preyPlaces.size() != 0) {
        int r = rand() % preyPlaces.size();
        coord_t x_coor = preyPlaces[r].x;
        coord_t y_coor = preyPlaces[r].y;
        this->satiety += preyFatContent;
        cell->getOcean()->deleteObjects(cell->getOcean()->getCells()[x_coor][y_coor].getObject());
        cell->getOcean()->getCells()[x_coor][y_coor].killMe();
        
        this->setCell(&(cell->getOcean()->getCells()[x_coor][y_coor]));
        
        cell->getOcean()->getCells()[x_coor][y_coor].setObject(this);

        cell->getOcean()->getCells()[x][y].killMe();
        
        
    } else {
        std::vector<Pair> newWays;
        if( ((x-1)>=0) && ((y-1)>=0) && (!cell->getOcean()->getCells()[x-1][y-1].getObject()) ) {
            newWays.push_back(Pair{(size_t) (x-1),
                (size_t) (y-1)});
        } // x-1; y-1
        if( ((y-1)>=0) && (!cell->getOcean()->getCells()[x][y-1].getObject()) ) {
            newWays.push_back(Pair{(size_t) (x),
                (size_t) (y-1)});
        } // x y-1
        if( ((x+1)<M) && ((y-1)>=0) && (!cell->getOcean()->getCells()[x+1][y-1].getObject()) ) {
            newWays.push_back(Pair{(size_t) (x+1),
                (size_t) (y-1)});
        } // x+1; y-1
        if( ((x-1)>=0) && (!cell->getOcean()->getCells()[x-1][y].getObject()) ) {
            newWays.push_back(Pair{(size_t) (x-1),
                (size_t) (y)});
        } // x-1; y
        if( ((x+1)<M) && (!cell->getOcean()->getCells()[x+1][y].getObject()) ) {
            newWays.push_back(Pair{(size_t) (x+1),
                (size_t) (y)});
        } // x+1; y
        if( ((x-1)>=0) && ((y+1)<N) && (!cell->getOcean()->getCells()[x-1][y+1].getObject()) ) {
            newWays.push_back(Pair{(size_t) (x-1),
                (size_t) (y+1)});
        } // x-1; y+1
        if( ((y+1)<N) && (!cell->getOcean()->getCells()[x][y+1].getObject()) ) {
            newWays.push_back(Pair{(size_t) (x),
                (size_t) (y+1)});
        } // x; y+1
        if( ((x+1)<M) && ((y+1)<N) && (!cell->getOcean()->getCells()[x+1][y+1].getObject()) ) {
            newWays.push_back(Pair{(size_t) (x+1),
                (size_t) (y+1)});
        } // x+1; y+1
        if (newWays.size() != 0) {
            int r = rand() % newWays.size();
            coord_t x_coor = newWays[r].x;
            coord_t y_coor = newWays[r].y;
            this->setCell(&(cell->getOcean()->getCells()[x_coor][y_coor]));
            cell->getOcean()->getCells()[x_coor][y_coor].setObject(this);
            cell->getOcean()->getCells()[x][y].killMe();
        }
        
    }
}

Predator::~Predator() {
}

void Predator::live() {
    int x = cell->getCrd().x;
    int y = cell->getCrd().y;
    if ((live_count-- > 0) && (satiety-- > deathByStarvation)) {
        curr_time++;
        go();
        if (((live_count > 0) && (satiety > 0) && (time_reproduction == curr_time) && (!cell->getOcean()->getCells()[x][y].getObject()))) {
            std::cout << "fdsfd" << std::endl;
            cell->getOcean()->getCells()[x][y].setObject(new Predator{live_count+curr_time, time_reproduction, &(cell->getOcean()->getCells()[x][y]), satiety+1, deathByStarvation, ObjType::PREDATOR});
            cell->getOcean()->addObjects(cell->getOcean()->getCells()[x][y].getObject());
        }
    } else {
        cell->getOcean()->deleteObjects(cell->getOcean()->getCells()[x][y].getObject());
        delete this;
        cell->getOcean()->getCells()[x][y].killMe();
    }
}


