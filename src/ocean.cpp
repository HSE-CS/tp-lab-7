// Copyright 2021 Krayushkina
#include "../include/ocean.h"
#include "../include/stone.h"
#include "../include/object.h"
Ocean::Ocean() {
    cells = new Cell*[N];
    for (auto i = 0; i < N; i++) {
        cells[i] = new Cell[M];
        for (auto j = 0; j < M; j++)
            cells[i][j].init(Pair{ i, j }, this);
    }
}
void Ocean::AddStuff(Object *obj) {
    stuff.push_back(obj);
}

void Ocean::print() const {
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < M; j++) {
            std::cout << (cells[i][j].getObject() ?
                cells[i][j].getObject()->getSymbol() : '.');
        }
        std::cout << std::endl;
    }
}
void Ocean::addObjects(unsigned int n, ObjType type) {
    while (n > 0) {
        unsigned int x = rand_r() % M;
        unsigned int y = rand_r() % N;
        if (cells[y][x].getObject()) {
            continue;
        } else {
            Object * born = nullptr;
            switch (type) {
            case ObjType::STONE:
                born = new Stone(&cells[y][x]);
                break;
            case ObjType::PREY:
                born = new Prey(&cells[y][x]);
                break;
            case ObjType::PREDATOR:
                born = new Predator(&cells[y][x]);
                break;
            }

            cells[y][x].setObject(born);
            stuff.push_back(born);
            n--;
            }
    }
}
void Ocean::run() {
    while (1) {
        system("cls");
        clock_t now = clock();
        print();
        while {
        (clock() < now + CLOCKS_PER_SEC / 10);
        }
        std::list<Object*>::iterator i = stuff.begin();
        while (i != stuff.end()) {
            bool isActive = DeleteObj(*i);
            if (!isActive) {
                stuff.erase(i++);
            } else {
                (*i)->live();
                ++i;
                 }
        }
    }
}
bool Ocean::DeleteObj(Object *obj) {
    if (obj->getLive() == 0) {
        obj->getCell()->killMe();
        return false;
    }
    return true;
}

Cell * Ocean::Step(Pair crd) {
    random_device ran;
    int xt = crd.x + ran() % 3 - 1;
    int yt = crd.y + ran() % 3 - 1;
        if (xt < N && yt < M) {
            if (cells[xt][yt].getObject() == nullptr)
                return &cells[xt][yt];
        }
        return nullptr;
}

Cell * Ocean::Radar(Pair crd) {
    random_device ran;
    int i = 0;
    while (i != 8) {
        int xt = crd.x + ran() % 3 - 1;
        int yt = crd.y + ran() % 3 - 1;

        if (xt < N && yt < M) {
            if (cells[xt][yt].getObject()
                && cells[xt][yt].getObject()->getType() == ObjType::PREY)
                return  &cells[xt][yt];
        }
        i++;
    }
    return nullptr;
}

Ocean::~Ocean() {
    for (int i = 0; i < N; i++)
        delete[] cells[i];
    delete[] cells;
    for (auto i = stuff.begin(); i != stuff.end(); ++i)
        delete i;
}
