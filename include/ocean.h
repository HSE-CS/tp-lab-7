// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include <list>
#include <vector>
#include <iostream>
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/predator.h"
#include "../include/stone.h"

class Ocean {
 private:
  Cell **cells;
  std::list<Object *> stuff;
  std::vector<Object *> DeletedEntities;
 public:
  void fill(float percentPrey = 0.5,
            float percentPredator = 0.1,
            float percentStone = 0.1);
  void addObjects(Object *newObj);
  void deleteObj();
  void addDeletedEntities(Object *obj);
  [[noreturn]] void run();
  Cell **getMatrix();
  void print() const;
  Ocean();
  ~Ocean();
};

#endif  //  INCLUDE_OCEAN_H_
