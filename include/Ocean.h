// Copyright JMax 2021

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "../include/Common.h"
#include "../include/Cell.h"
#include "../include/Object.h"

#include <vector>
#include <string>
#include <map>
#include <list>

class Cell;
class Object;

class Ocean {
 private:
    int step = 0;
    Cell **cells;
    std::list<Object*> stuff;
    void makeOcean();
    void createSpecies();
    static int getRandom(int max);
    std::vector<Cell*> getEmptyCells() const;
    static Object* getObject(objectType type, Cell* cell);
    void clearStuff();
    std::map<std::string, int> calcStuff() const;
    static void printStats(std::map<std::string, int> stats) ;
    static void setCursor(short x, short y);

 public:
    Ocean();
    ~Ocean();
    void printOcean() const;
    void run();
    Cell* getCell(Pair crd);
    void addToStuff(Object* object);
};

#endif  // INCLUDE_OCEAN_H_
