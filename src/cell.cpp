// Copyright 2021 Kuznetsov Mikhail

#include "cell.h"



Cell::Cell(Ocean* _ocean,
          std::pair<unsigned int, unsigned int> _coordinates,
          int _temperature) :
    ocean(_ocean),
    coordinates(_coordinates),
    temperature(_temperature) {
    object = nullptr;
}

Cell::~Cell() {
  killObject();
}

void Cell::setObject(Object *_object) {
  object = _object;
}

void Cell::setTemperature(int _temperature) {
  temperature = _temperature;
}

Ocean* Cell::getOcean() {
  return ocean;
}

Object* Cell::getObject() {
  return object;
}

std::pair<unsigned int, unsigned int> Cell::getCoordinates() {
  return coordinates;
}

int Cell::getTemperature() {
  return temperature;
}

std::list<std::pair<unsigned int, unsigned int>> Cell::getArea() {
  std::list<std::pair<unsigned int, unsigned int>> area;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i || j) {
        unsigned int x = (coordinates.first +
                          ocean->getHeight() + i) % ocean->getHeight();
        unsigned int y = (coordinates.second +
                          ocean->getWidth() + j) % ocean->getWidth();
        area.push_back({x, y});
      }
    }
  }
  return area;
}

void Cell::killObject() {
  if (object) {
    delete object;
    object = nullptr;
  }
}

