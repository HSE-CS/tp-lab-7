// Copyright 2021 by Sid

#ifndef Ocean_h
#define Ocean_h
#include <vector>
#include <list>
#include <iostream>
#include <unordered_set>
#include "Object.h"
#include "Coordinates.h"
#include "Settings.h"

class Cell;
class Object;

class Ocean {
    std::vector<std::vector<Cell*>> ocean;
    std::list<Object*> objects;
    bool isAnyLiving = false;
    int stoneCounter = 0;

    bool _coordCheck(Point coord);
public:

    Ocean(size_t h, size_t w);
    void run();
    void deleteObject(Object* obj);
    bool cellIsEmpty(Point coord);
    void printOcean();
    Cell* findEmptyCell(Point coord);
    Cell* findPrey(Point coord);
    Cell* getCell(Point coord);
    size_t getWidth() { return ocean[0].size(); }
    size_t getHeight() { return ocean.size(); }
    bool getState() { return isAnyLiving; }
    std::list<Object*>::iterator getOceanBegin() { return objects.begin(); }
    std::list<Object*>::iterator getOceanEnd() { return objects.end(); }
    void addObject(Object* obj) { objects.push_back(obj); }
    void addObjects(ObjectTypes type, size_t quant);
    void shuffle();
};


#endif /* Ocean_h */

