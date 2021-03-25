// Copyright 2021 MalininDmitry
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "ocean.h"
#include "cell.h"
#include "prey.h"
#include "stone.h"
#include "predator.h"

Cell **Ocean::getCells() {
    return cells;
}

struct srt {
    int x;
    int y;
};

std::vector<srt> getShuffle(int numStones, int numPreys, int numPredators) {
    std::vector<srt> v;
    srt s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            s.x = i;
            s.y = j;
            v.push_back(s);
        }
    }

    srand(unsigned(time(0)));
    shuffle(v.begin(), v.end(), std::default_random_engine(0));
    return v;
}

Ocean::Ocean(int numStones, int numPreys,
             int numPredators, int live_count,
             int time_reproduction, int satiety,
             int deathByStarvation) {
    this->numStones = numStones;
    this->numPreys = numPreys;
    this->numPredators = numPredators;
    cells = new Cell*[N];
    for (int i = 0; i < N; i++) {
        cells[i] = new Cell[M];
        for (int j = 0; j < M; j++) {
            Pair c = {(size_t)i, (size_t)j};
            cells[i][j].init(c, this);
        }
    }
    std::vector<srt> v = getShuffle(numStones, numPreys,
                                    numPredators);

    for (int i = 0; i < numStones; i++) {
        cells[v[i].x][v[i].y].setObject(new
                Stone{&cells[v[i].x][v[i].y]});
        stuff.push_back(cells[v[i].x][v[i].y].getObject());

    }
    for (int i = numStones; i < numStones + numPreys; i++) {
        cells[v[i].x][v[i].y].setObject(new
            Prey{live_count, time_reproduction,
                &cells[v[i].x][v[i].y], ObjType::PREY});
        stuff.push_back(cells[v[i].x][v[i].y].getObject());
    }

    for (int i = numPreys; i < numPreys + numPredators; i++) {
        cells[v[i].x][v[i].y].setObject(new Predator{live_count, time_reproduction, &cells[v[i].x][v[i].y], satiety, deathByStarvation, ObjType::PREDATOR});
        stuff.push_back(cells[v[i].x][v[i].y].getObject());
    }
    std::cout << stuff.size() << std::endl;
}

void Ocean::run() {
    std::cout << stuff.size() << std::endl;
    for (int i = 0; i < stuff.size(); i++) {
        stuff[i]->live();
    }
    
}

void Ocean::addObjects(Object* obj) {
    stuff.push_back(obj);
}

void Ocean::print() const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cells[i][j].getObject() &&
    cells[i][j].getObject()->getType() == ObjType::STONE) {
                std::cout << STONE_N;
            } else if (cells[i][j].getObject()
    && cells[i][j].getObject()->getType() == ObjType::PREY) {
                std::cout << PREY_N;
            } else if (cells[i][j].getObject()
    && cells[i][j].getObject()->getType() == ObjType::PREDATOR) {
                std::cout << PREDATOR_N;
            } else {
                std::cout << NOTHING_N;
            }
        }
        std::cout << std::endl;
    }
}

Ocean::~Ocean() {
    for (Object *o : stuff) {
        delete o;
    }
    for (int i = 0; i < N; i++){
        delete cells[i];
    }
    delete cells;
}

void Ocean::deleteObjects(Object* obj) {
    for (int i = 0; i < stuff.size(); i++) {
        if ( stuff[i] == obj ) {
            stuff.erase(stuff.begin() + i);
        }
    }
}


