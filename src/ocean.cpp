// Copyright 2021 valvarl

#include <iostream>
#include <sstream>
#include <algorithm>
#include "ocean.h"

Ocean::Ocean() {
    simple_rand.seed(
            std::chrono::system_clock::now().time_since_epoch().count());
    //simple_rand.seed(44);
    stuff = std::vector<Object*>{};
    cells = new Cell*[N];
    for (int i = 0; i < N; i++) {
        cells[i] = new Cell[M];
        for (int j = 0; j < M; j++) {
            cells[i][j].init(Pair{(size_t) i, (size_t) j}, this);
        }
    }
}

void Ocean::addObjects() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (simple_rand() % 100 <= ENTITY_SPAWN_PROBABILITY) {
                int entity_type = static_cast<int>(simple_rand() % (
                        STONE_SPAWN_PROBABILITY + CORAL_SPAWN_PROBABILITY +
                        PREDATOR_SPAWN_PROBABILITY + PREY_SPAWN_PROBABILITY
                        ));
                if (entity_type >= STONE_SPAWN_PROBABILITY +
                CORAL_SPAWN_PROBABILITY + PREY_SPAWN_PROBABILITY) {
                    cells[i][j].obj = new Predator{&cells[i][j]};
                } else if (entity_type >= STONE_SPAWN_PROBABILITY +
                CORAL_SPAWN_PROBABILITY) {
                    cells[i][j].setObject(new Prey{&cells[i][j]});
                } else if (entity_type >= STONE_SPAWN_PROBABILITY) {
                    cells[i][j].obj = new Coral{&cells[i][j]};
                } else {
                    cells[i][j].setObject(new Stone{&cells[i][j]});
                }
                if (cells[i][j].obj->getType() != ObjType::STONE){
                    stuff.push_back(cells[i][j].obj);
                }
            }
        }
    }
}

void Ocean::print() const {
    std::stringbuf str;
    std::ostream stream(&str);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cells[i][j].obj) {
                switch (cells[i][j].obj->getType()) {
                    case ObjType::STONE:
                        stream << STONE_N;
                        break;
                    case ObjType::CORAL:
                        stream << CORAL_N;
                        break;
                    case ObjType::PREY:
                        stream << PREY_N;
                        break;
                    case ObjType::PREDATOR:
                        stream << PREDATOR_N;
                        break;
                }
            } else {
                stream << NOTHING_N;
            }
        }
        stream << "\n";
    }
    std::cout << str.str() << std::endl;
}

void Ocean::run() {
    for (int k = 0; k < 300; k++) {
        std::random_device rd;
        std::mt19937  g(rd());
        std::shuffle(stuff.begin(), stuff.end(), g);

        int deleted = 0;
        int size_staff = stuff.size();
        for (int i = 0; i < size_staff; i++) {
            if (stuff[i - deleted]->getRemainLive() <= 0) {
                int x = stuff[i - deleted]->getCell()->crd.x;
                int y = stuff[i - deleted]->getCell()->crd.y;
                if (cells[x][y].getObject() && cells[x][y].getObject()->getType() == stuff[i-deleted]->getType()) {
                    this->cells[x][y].killMe();
                }
                delete stuff[i - deleted];
                stuff.erase(stuff.begin() + i - deleted);
                deleted++;
            }
        }

        for (int i = 0; i < stuff.size(); i++) {
            int x = stuff[i]->getCell()->crd.x;
            int y = stuff[i]->getCell()->crd.y;
            if (cells[x][y].getObject() && cells[x][y].getObject()->getType() == stuff[i]->getType()) stuff[i]->live();
        }

        std::cout << stuff.size() << std::endl;

        this->print();

        stuff.insert(stuff.begin(),
                     temporary_stuff.begin(), temporary_stuff.end());
        temporary_stuff.clear();
    }
}

Ocean::~Ocean() {
    for (Object *o : stuff) {
        delete o;
    }
    for (int i = 0; i < N; i++) {
        delete cells[i];
    }
}

Cell **Ocean::getCells() const {
    return cells;
}
