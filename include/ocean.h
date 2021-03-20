//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include <list>
#include <vector>
#include <iostream>
#include "object.h"
#include "cell.h"
#include "predator.h"
#include "stone.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"  /* Red */
#define YELLOW  "\033[33m"  /* Yellow */
#define BLUE    "\033[34m"  /* Blue */
#define GREEN   "\033[32m"  /* Green */

class Ocean {
 public:
  Ocean();
  ~Ocean();
  void fullHouse(float preyPerc = 0.3,
                 float predatorPerc = 0.05,
                 float stonePerc = 0.1);
  Cell **getMatrix();
  void print() const;
  void addObjects(Object *newObj);
  void delObjects();
  void addDeleteCreatures(Object *obj);
  [[noreturn]] void run();

 private:
  Cell **cells;
  std::list<Object *> stuff;
  std::vector<Object *> toDeleteCreatures;
};

#endif  //  INCLUDE_OCEAN_H_
