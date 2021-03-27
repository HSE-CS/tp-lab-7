// Copyright [2020] <Olesya Nikolaeva>

#include <stdlib.h>
#include <time.h>
#include "cell.h"
#include "ocean.h"

void Cell::init(Pair p, Ocean* oc) {
    crd = p;
    obj = nullptr;
    ocean = oc;
}

void Cell::changeStatus(bool arg) {
    isfree = arg;
    if (arg == true) {
        setObject(nullptr);
    }
}

void Cell::die() {
    ocean->deleteObject(obj);
    delete obj;
    obj->setObjType(ObjType::EMPTY);
}

//0 - движется вверх, 1 - вправо, 2 - вниз, 3 - влево
bool Cell::movingtoNeighborhood() {
    unsigned int seed = time(NULL);
    int index = rand_r(&seed) % 4;
    int n = 0;
    while (n < 4) {
        n++;
        index = (index + 1) % 4;
        Pair initial;
        switch (index) {
            case 0:
                initial = { crd.x - 1, crd.y };
                if ((initial.x > 0) && (returnCellfromOcean(initial) == true)) {
                    returnCellPointer(initial)->setObject(obj);
                    changeStatus(true);
                    return true;
                }
                break;
            case 1:
                initial = { crd.x, crd.y + 1 };
                if ((initial.y < M) && (returnCellfromOcean(initial) == true)) {
                    returnCellPointer(initial)->setObject(obj);
                    changeStatus(true);
                    return true;
                }
                break;
            case 2:
                initial = { crd.x + 1, crd.y };
                if ((initial.x < N) && (returnCellfromOcean(initial) == true)) {
                    returnCellPointer(initial)->setObject(obj);
                    changeStatus(true);
                    return true;
                }
                break;
            case 3:
                initial = { crd.x, crd.y - 1 };
                if ((initial.y > 0) && (returnCellfromOcean(initial) == true)) {
                    returnCellPointer(initial)->setObject(obj);
                    changeStatus(true);
                    return true;
                }
                break;
        }
    }
    return false;
}

bool Cell::findingPreys() {
    unsigned int seed = time(NULL);
    int index = rand_r(&seed) % 4;
    int n = 0;
    while (n < 4) {
        n++;
        index = (index + 1) % 4;
        Pair initial;
        switch (index) {
            case 0:
                initial = { crd.x - 1, crd.y };
                if ((initial.x > 0) && (atSpecificPosition(initial) == ObjType::PREY)) {
                    returnCellPointer(initial)->setObject(obj);
                    changeStatus(true);
                    return true;
                }
                break;
            case 1:
                initial = { crd.x, crd.y + 1 };
                if ((initial.y < M) && (atSpecificPosition(initial) == ObjType::PREY)) {
                    returnCellPointer(initial)->setObject(obj);
                    changeStatus(true);
                    return true;
                }
                break;
            case 2:
                initial = { crd.x + 1, crd.y };
                if ((initial.x < N) && (atSpecificPosition(initial) == ObjType::PREY)) {
                    returnCellPointer(initial)->setObject(obj);
                    changeStatus(true);
                    return true;
                }
                break;
            case 3:
                initial = { crd.x, crd.y - 1 };
                if ((initial.y > 0) && (atSpecificPosition(initial) == ObjType::PREY)) {
                    returnCellPointer(initial)->setObject(obj);
                    changeStatus(true);
                    return true;
                }
                break;
        }
    }
    return false;
}

Object* Cell::getObject() const {
    return obj;
}

void Cell::setObject(Object* new_obj) {
    obj = new_obj;
}

Pair Cell::returnLocation() {
    return crd;
}

bool Cell::returnCellfromOcean(Pair arg) {
    return ocean->returnCellStatus(arg);
}

Cell* Cell::returnCellPointer(Pair arg) {
    return ocean->returnCell(arg);
}

ObjType Cell::atSpecificPosition(Pair arg) {
    return ocean->returnObjectAtSpecificPos(arg);
}

Ocean* Cell::returnOcean() {
    return ocean;
}
