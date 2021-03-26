// Copyright 2021 by Sid

#include <iostream>
#include <vector>
#include <random>
#include "Ocean.h"
#include "Factory.h"

class Factory;

Ocean::Ocean(size_t h, size_t w) {
    ocean.resize(h);
    for (coord_t i = 0; i < ocean.size(); i++) {
        ocean[i].resize(w);
        for (coord_t j = 0; j < ocean[i].size(); j++) {
            ocean[i][j] = new Cell(Point(j, i), this);
        }
    }
}

void Ocean::addObjects(ObjectTypes type, size_t quant) {
    isAnyLiving = true;
    size_t width = getWidth();
    size_t height = getHeight();
    for (int i = 0; i < quant; i++) {
        Point coord(rand() % width, rand() % height);
        int count = 0;
        while (!cellIsEmpty(coord) && count++ < width * height) {
            coord = *(new Point(rand() % width, rand() % height));
        }
        if (!cellIsEmpty(coord)) {
            std::cout << "Not enough space for type " << typeNames[type]
                      << "\nAt " << i << " step" << std::endl;
            return;
        }
        Cell* cell = getCell(coord);
        Object* obj = Factory::createObject(type, cell);
        obj->setCell(cell);
        if (obj->getSymbol() != STONE_CHAR) {
            objects.push_back(obj);
        } else {
            stoneCounter++;
        }
        cell->setObject(obj);



    }
}

bool Ocean::cellIsEmpty(Point coord) {
    if (coord.y >= ocean.size() || coord.x >= ocean[0].size()) {
        return false;
    }
    return ocean[coord.y][coord.x]->getObject() == nullptr;
}

void Ocean::printOcean() {
    for (auto line : this->ocean) {
        for (Cell* cell : line) {
            Object* obj = cell->getObject();
            if (obj == nullptr) {
                std::cout << "_";
            }
            else {
                std::cout << obj->getSymbol();
            }
        }
        std::cout << std::endl;
    }
    _sleep(100);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

Cell* Ocean::getCell(Point coord) {
    return ocean[coord.y][coord.x];
}

Cell* Ocean::findEmptyCell(Point coord) {
    for (int i = 0; i < NUMBER_OF_TRYS; i++) {
        coord_t x;
        coord_t y;
        int rand_choice = rand() % 4;
        switch (rand_choice) {
            case 0:
                x = coord.x;
                y = coord.y + 1;
                break;
            case 1:
                x = coord.x;
                y = coord.y - 1;
                break;
            case 2:
                x = coord.x + 1;
                y = coord.y;
                break;
            case 3:
                x = coord.x - 1;
                y = coord.y;
                break;
            default:
                exit(666);
                break;
        }
        Point coord(x, y);
        if (cellIsEmpty(coord) && abs(int(x)) != abs(int(y))) {
            return getCell(coord);
        }
    }
    return nullptr;
}

bool Ocean::_coordCheck(Point coord) {
    coord_t x = coord.x;
    coord_t y = coord.y;
    if (x < ocean[0].size() && y < ocean.size()) {
        return getCell(coord)->getObject() != nullptr && getCell(coord)->getObject()->getSymbol() != PREY_CHAR;
    }
    return false;
}

Cell* Ocean::findPrey(Point coord) {
    if (_coordCheck(Point(coord.x + 1, coord.y))) {
        return getCell(Point(coord.x + 1, coord.y));
    } else if (_coordCheck(Point(coord.x - 1, coord.y))) {
        return getCell(Point(coord.x - 1, coord.y));
    } else if (_coordCheck(Point(coord.x, coord.y + 1))) {
        return getCell(Point(coord.x, coord.y + 1));
    } else if (_coordCheck(Point(coord.x, coord.y - 1))) {
        return getCell(Point(coord.x, coord.y - 1));
    }
    return nullptr;
}

void Ocean::deleteObject(Object *obj) {
    obj->getCell()->killObject();
}

void Ocean::run() {

    for (int i = 0; i < objects.size(); i++) {
        auto iter = std::next(objects.begin(), i);
        if ((*iter)->live() == false) {
            deleteObject(*iter);
            objects.erase(iter);
            i--;
        }
    }

    if (objects.size() <= stoneCounter) {
        isAnyLiving = false;
    }
}

void Ocean::shuffle() {

    std::vector<std::reference_wrapper<Object*>> vec(objects.begin(), objects.end()) ;

    std::shuffle( vec.begin(), vec.end(), std::mt19937{ std::random_device{}() } ) ;

    std::list<Object*> shuffled_list {  vec.begin(), vec.end() } ;

    objects.swap(shuffled_list) ;
}