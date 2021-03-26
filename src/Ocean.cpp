// Copyright 2021 Vlad
#include <ctime>
#include <iostream>
#include "Ocean.h"
#include "Object.h"
#include "Prey.h"
#include "Cell.h"
#include "Predactor.h"
#include "Stone.h"


void Ocean::setObject(Object* obj) {
    int x = std::rand() % N;
    int y = std::rand() % M;
    for (int i = 0; i < 100; i++) {
        if (ocean[x][y].getObject() == nullptr) {
            obj->setCell(&(ocean[x][y]));
            ocean[x][y].setObject(obj);
            return;
        }
        x = std::rand() % N;
        y = std::rand() % M;
    }
}

Ocean::Ocean(int stone, int prey, int predactor, int reproduction, int death) {
    ocean = new Cell *[N];
    for (int i = 0; i < N; i++) {
        ocean[i] = new Cell[M];
        for (int j = 0; j < M; j++) {
            ocean[i][j].init(Pair{ i, j }, this);
        }
    }
    for (int i = 0; i < stone; i++) {
        setObject(new Stone());
    }
    for (int i = 0; i < prey; i++) {
        setObject(new Prey(nullptr, reproduction, death));
    }
    for (int i = 0; i < predactor; i++) {
        setObject(new Predactor(nullptr, reproduction, death));
    }
}

void Ocean::print() const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ocean[i][j].getObject() == nullptr) {
                std::cout << '.';
                continue;
            }
            switch (ocean[i][j].getObject()->getType()) {
            case ObjType::PREY:
                std::cout << 'f';
                break;
            case ObjType::PREDATOR:
                std::cout << 'S';
                break;
            case ObjType::STONE:
                std::cout << '*';
                break;
            default:
                break;
            }
        }
        std::cout << '\n';
    }
}

void Ocean::AddObject(Object* object) {
    objects.push_back(object);
}

void Ocean::run() {
    for (;;) {
        print();
        // Sleep(20000)
        for (int i = 0; i < objects.size(); i++) {
            objects[i]->live();
        }
       // system("cls");
    }
}

Cell* Ocean::getCell(Pair pair) {
    if (pair.x >= 0 && pair.x < N && pair.y >= 0 && pair.y < M) {
        return &(ocean[pair.x][pair.y]);
    }
    return nullptr;
}


void Ocean::removeObject(Object* object) {
    for (int i = 0; i < objects.size(); i++)  {
        Cell* newCell = objects[i]->getCell();
        if (object && object->getCell()->getX() == newCell->getX() &&
            object->getCell()->getY() == newCell->getY()) {
            auto iter = objects.cbegin();
            objects.erase(iter + i);
        }
    }

}

Ocean::~Ocean()
{
    for (int i = 0; i < N; i++) {
        delete[] ocean[i];
    }
    delete ocean;
    for (int i = 0; i < objects.size(); i++) {
        delete objects[i];
    }
}
