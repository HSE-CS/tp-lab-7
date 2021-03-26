// Copyright 2020 PollyllyZh
#include <random>
#include "../include/ocean.h"
#include "../include/stone.h"
#include "../include/object.h"
#include "../include/common.h"
Ocean::Ocean() {
    cells = new Cell * [N];

    for (uint i = 0; i < N; i++) {
        cells[i] = new Cell[M];
    }
    for (uint i = 0; i < N; i++)
        for (uint j = 0; j < M; j++) {
            cells[i][j].init({ i, j }, this);
        }
    }
Ocean::~Ocean() {
    for (uint i = 0; i < N; i++) {
        delete[] cells[i];
    }
    delete[] cells;

    std::list<Object*>().swap(stuff);
}
void Ocean::print() const {
    uint num_prey = 0,
        num_predator = 0,
        num_stone = 0;

    for (uint i = 0; i < N; i++) {
        for (uint j = 0; j < M; j++) {
            if (!cells[i][j].get_object()) {
                std::cout << ". ";
            }
            else {
                if (cells[i][j].get_object()->get_type() == ObjType::PREY) {
                    num_prey++;
                }
                if (cells[i][j].get_object()->get_type() == ObjType::PREDATOR) {
                    num_predator++;
                }
                if (cells[i][j].get_object()->get_type() == ObjType::STONE) {
                    num_stone++;
                }
                std::cout << cells[i][j].get_object()->get_symbol() << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "prey: " << num_prey << std::endl;
    std::cout << "predator: " << num_predator << std::endl;
    std::cout << "stone: " << num_stone << std::endl;
}
void Ocean::add_objects(ObjType obj_type, uint num) {
    for (uint i = 0; i < num; ) {
        auto n = rand() % N;
        auto m = rand() % M;

        if (cells[n][m].get_object())
            continue;

        Object* tmp = nullptr;

        switch (obj_type) {
        case ObjType::PREY:
            tmp = new Prey(&cells[n][m]);
            break;

        case ObjType::PREDATOR:
            tmp = new Predator(&cells[n][m]);
            break;

        case ObjType::STONE:
            tmp = new Stone(&cells[n][m]);
            break;

        default:
            break;

        }
        cells[n][m].set_object(tmp);
        stuff.push_back(tmp);
        i++;
    }
}
void Ocean::add_stuff(Object* object) {
    stuff.push_back(object);
}
void Ocean::del_obj(Object* object) {
    object->get_cell()->killMe();
}
Cell* Ocean::find_empty(Pair crd)
{
    std::srand(unsigned(std::time(0)));
    for (uint i = 0; i < attempts; i++) {
        uint x1 = crd.x + rand() % 3 - 1;
        uint y1 = crd.y + rand() % 3 - 1;
        if (x1 < N && y1 < M)
            if (cells[x1][y1].get_object() == nullptr)
                return &cells[x1][y1];
    }

    return nullptr;
}
Cell* Ocean::find_prey(Pair crd) {
    std::srand(unsigned(std::time(0)));

    for (uint i = 0; i < attempts; i++) {
        uint x1 = crd.x + rand() % 3 - 1;
        uint y1 = crd.y + rand() % 3 - 1;

        if (x1 < N && y1 < M)
            if (cells[x1][y1].get_object() && cells[x1][y1].get_object()->get_type() == ObjType::PREY)
                return &cells[x1][y1];
    }
    return nullptr;
}
void Ocean::run() {
    for (auto i = stuff.begin(); i != stuff.end(); i++) {
        if (!(*i)->live()) {
            del_obj(*i);
            stuff.erase(i++);
        }
    }
}
