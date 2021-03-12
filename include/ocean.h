//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef _OCEAN_H_
#define _OCEAN_H_

#include <list>
#include <vector>
#include <iostream>
#include <string>
//#include "common.h"
#include "cell.h"
#include "predator.h"
#include "stone.h"

class Ocean
{
 private:
  Pair size;
  Cell **cells;
  std::list<Object*> stuff;
  std::vector<Object*> deleteCandidatesList;
  Cell* find(Cell *centerCell, bool (*condition)(Cell*));
  static bool isPreyCell(Cell* checkCell);
  static bool isEmptyCell(Cell* checkCell);
  void deleteCandidates();

 public:
  Ocean(Pair newSize);
  ~Ocean();
  void print() const;
  void createInitial(float preyPercent,
                     float predatorPercent,
                     float stonePercent,
                     unsigned* seed);
  void run();
  void addObject(Object* newObject);
  void deleteObject(Object* oldObject);
  void addDeleteCandidate(Object* oldObject);
  Cell* findEmpty(Cell* centerCell);
  Cell* findPrey(Cell* centerCell);
  Cell* getCell(Pair crd);
};
#endif // _OCEAN_H_
