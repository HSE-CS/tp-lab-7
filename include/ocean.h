// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include <vector>
#include "include/common.h"
#include "include/Cell.h"

class Ocean {
 private:
  Cell** cells;
  int width;
  int height;
  std::list<Object*> biosphere;

 public:
  explicit Ocean(int width = M, int height = N);
  ~Ocean() = default;
  void print() const;
  void addToBiosphere(Object* existingObject);
  int movement(coords prev, coords newCds, Object* existingObject);
  int getWidth();
  int getHeight();
  void run();
  void addObjects(int quantity, int type,
   std::vector < std::vector <coords> > availableCoords);
};

#endif  // INCLUDE_OCEAN_H_
