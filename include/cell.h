// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include <list>
#include <utility>
#include "ocean.h"

class Ocean;
class Object;

class Cell {
 private:
    Ocean* ocean;
    Object* object;
    std::pair <unsigned int, unsigned int> coordinates;
    int temperature;
 public:
    explicit Cell(Ocean* _ocean = nullptr,
                std::pair<unsigned int, unsigned int> _coordinates = {0, 0},
                int _temperature = 0);
    ~Cell();
    void setObject(Object* _object);
    void setTemperature(int _temperature);
    Ocean* getOcean();
    Object* getObject();
    std::pair<unsigned int, unsigned int> getCoordinates();
    int getTemperature();
    std::list<std::pair<unsigned int, unsigned int>> getArea();
    void killObject();
};

#endif  // INCLUDE_CELL_H_
