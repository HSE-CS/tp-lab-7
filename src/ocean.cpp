// Copyright 2021 VladimirUspensky

#include <iostream>
#include <sstream>
#include <algorithm>
#include <random>
#include "../include/ocean.h"

Ocean::Ocean() {
    rand_r(reinterpret_cast<unsigned int *>(44));
    stuff = std::vector<Object*>{};
    cells = new Cell*[N];
    for (int i = 0; i < N; i++) {
        cells[i] = new Cell[M];
        for (int j = 0; j < M; j++) {
            cells[i][j].init(Pair{i, j}, this);
        }
    }
}

void Ocean::addObjects() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (rand_r(reinterpret_cast<unsigned int *>(44))
                % 100 <= ENTITY_CREATION) {
                int entType = static_cast<int>(rand() % (
                        STONE_CREATION + CORAL_CREATION +
                        PREDATOR_CREATION + PREY_CREATION));
                if (entType >=
                STONE_CREATION +
                CORAL_CREATION +
                PREY_CREATION) {
                    cells[i][j].obj = new Predator{&cells[i][j]};
                } else if (entType >=
                STONE_CREATION +
                CORAL_CREATION) {
                    cells[i][j].setObject(new Prey{&cells[i][j]});
                } else if (entType >= STONE_CREATION) {
                    cells[i][j].obj = new Coral{&cells[i][j]};
                } else {
                    cells[i][j].setObject(new Stone{&cells[i][j]});
                }
                if (cells[i][j].obj->getType() != ObjType::STONE) {
                    stuff.push_back(cells[i][j].obj);
                }
            }
        }
    }
}

void Ocean::show() const {
    std::stringbuf buffer;
    std::ostream stream(&buffer);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cells[i][j].obj) {
                if (cells[i][j].obj->getType() == ObjType::STONE) {
                    stream << STONE_N;
                } else if (cells[i][j].obj->getType() == ObjType::PREY) {
                    stream << PREY_N;
                } else if (cells[i][j].obj->getType() == ObjType::PREDATOR) {
                    stream << PREDATOR_N;
                } else if (cells[i][j].obj->getType() == ObjType::CORAL) {
                    stream << CORAL_N;
                }
            } else {
                stream << NOTHING_N;
            }
        }
        stream << "\n";
    }
    std::cout << buffer.str() << std::endl;
}

void Ocean::run() {
    for (int k = 0; k < 300; k++) {
        std::random_device rand_dev;
        std::mt19937 mt(rand_dev());
        std::shuffle(stuff.begin(), stuff.end(), mt);
        int removed = 0;
        int staff_len = stuff.size();
        for (int i = 0; i < staff_len; i++) {
            if (stuff[i - removed]->getRemainLive() <= 0) {
                int x = stuff[i - removed]->getCell()->crd.x_coord;
                int y = stuff[i - removed]->getCell()->crd.y_coord;
                if (cells[x][y].getObject() &&
                    cells[x][y].getObject()->getType() ==
                    stuff[i - removed]->getType()) {
                        this->cells[x][y].killMe();
                }
                delete stuff[i - removed];
                stuff.erase(stuff.begin() + i - removed);
                removed++;
            }
        }
        for (auto & i : stuff) {
            int x = i->getCell()->crd.x_coord;
            int y = i->getCell()->crd.y_coord;
            if (cells[x][y].getObject() &&
                cells[x][y].getObject()->
                getType() == i->getType())
                i->live();
        }
        std::cout << stuff.size() << std::endl;
        this->show();
        stuff.insert(stuff.begin(),
                     temp_stuff.begin(),
                     temp_stuff.end());
        temp_stuff.clear();
    }
}

Ocean::~Ocean() {
    for (Object *obj : stuff) {
        delete obj;
    }
    for (int i = 0; i < N; i++) {
        delete cells[i];
    }
}

Cell **Ocean::getCells() const {
    return cells;
}
