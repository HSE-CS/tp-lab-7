// Copyright 2021 Nikolaev Ivan

#include <stdio.h>
#include <iostream>
#include "../include/ocean.h"

Ocean::Ocean() {
    Ocean(40, 80, 500, 500, 20);
}

Cell** Ocean::getCells() {
    return cells;
}

void Ocean::setCell(int x, int y, Object* obj) {
    cells[x][y].setObject(obj);
}

void Ocean::deleteObj(Object* objectForDelete) {
    std::list<Object*> newStuff;
    for (auto obj : stuff) {
        if (obj != objectForDelete) {
            newStuff.push_back(obj);
        }
    }
    stuff = newStuff;
    Pair crd = objectForDelete->getCell()->getCrd();
    objectForDelete->getCell()->getOcean()->setCell(crd.x, crd.y, nullptr);
    objectForDelete->getCell()->setObject(nullptr);
}

Ocean::Ocean(int height, int width, int preys, int predators, int stones) {
    this->height = height;
    this->width = width;
    this->preys = preys;
    this->predators = predators;
    this->stones = stones;
    cells = new Cell * [height];
    for (int i = 0; i < height; i++) {
        cells[i] = new Cell[width];
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cells[i][j].init({ i, j }, this);
        }
    }
}

Ocean::~Ocean() {
    for (unsigned i = 0; i < height; i++)
        delete[] cells[i];
    delete[] cells;
}

void Ocean::addPreys() {
    for (int i = 0; i < preys; i++) {
        Prey* prey = new Prey(10);
        stuff.push_back(prey);
        bool isAdded = false;
        while (!isAdded) {
            int h = static_cast<int>(gen() % height);
            int w = static_cast<int>(gen() % width);
            if (cells[h][w].getObject() == nullptr) {
                cells[h][w].setObject(prey);
                prey->setCell(&cells[h][w]);
                isAdded = true;
            }
        }
    }
}

void Ocean::addPredators() {
    for (int i = 0; i < predators; i++) {
        Predator* predator = new Predator(12);
        stuff.push_back(predator);
        bool isAdded = false;
        while (!isAdded) {
            int h = static_cast<int>(gen() % height);
            int w = static_cast<int>(gen() % width);
            if (cells[h][w].getObject() == nullptr) {
                cells[h][w].setObject(predator);
                predator->setCell(&cells[h][w]);
                isAdded = true;
            }
        }
    }
}

void Ocean::addObjects() {
    if (preys + predators + stones > height * width) {
        throw "There is not enough space!";
    }
    addPredators();
    addPreys();
    for (int i = 0; i < stones; i++) {
        Stone* stone = new Stone();
        //    stuff.push_back(stone);
        bool isAdded = false;
        while (!isAdded) {
            int h = static_cast<int>(gen() % height);
            int w = static_cast<int>(gen() % width);
            if (cells[h][w].getObject() == nullptr) {
                cells[h][w].setObject(stone);
                stone->setCell(&cells[h][w]);
                isAdded = true;
            }
        }
    }
}

void Ocean::print() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Object* object = cells[i][j].getObject();
            if (object == nullptr) {
                std::cout << "\x1B[34m~\033[0m";
            } else {
                char symbol = object->getSymbol();
                if (symbol == 'S') {
                    std::cout << "\x1B[31mS\033[0m";
                } else if (symbol == 'f') {
                    std::cout << "\x1B[92mf\033[0m";
                } else if (symbol == '*') {
                    std::cout << "\x1B[32m*\033[0m";
                }
            }
        }
        std::cout << std::endl;
    }
}

void Ocean::addObject(int x, int y, Object* obj) {
    cells[x][y].setObject(obj);
    obj->setCell(&cells[x][y]);
    stuff.push_back(obj);
}

void Ocean::run() {
    std::cout << std::endl;
    for (int i = 0; i < 100; i++) {
        if (predators == 0 || preys == 0) {
            break;
        }
        /*
        for (auto obj : stuff) {
            std::cout << obj->getCell()->getCrd().x << " " << obj->getCell()->getCrd().y << std::endl;
        }
        */
        int sizeOfStuff = stuff.size();
        for (int j = 0; j < sizeOfStuff; j++) {
            Object* front = stuff.front();
            Object* currentObject = stuff.front();
            if (i == 19) {
                int a = 5;
            }
            currentObject->live();
            if (stuff.front() == front) {
                stuff.pop_front();
            }
            if (currentObject->getCell()->getObject() != nullptr) {
                stuff.push_back(currentObject);
            } else {
                sizeOfStuff--;
            }
        }
        system("CLS");
        print();
    }
}

int Ocean::getPreys() {
    return preys;
}

int Ocean::getPredators() {
    return predators;
}

void Ocean::setPreys(int preys) {
    this->preys = preys;
}

void Ocean::setPredators(int predators) {
    this->predators = predators;
}

int Ocean::getHeight() {
    return height;
}

int Ocean::getWidth() {
    return width;
}
