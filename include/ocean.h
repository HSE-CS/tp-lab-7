//Copyright GN 2021

#ifndef _OCEAN_H_
#define _OCEAN_H_


#include "common.h"
#include "cell.h"
#include "object.h"
#include "stone.h"
#include "prey.h"
#include "predator.h"

#include <list>

class Ocean {
 private:
  Cell** cells;
  std::list<Object*> objects;

 public:
  Ocean();
  ~Ocean() {
    for (int i = 0; i < N; i++) {
      delete[] cells[i];
    }
    delete[] cells;
  }
  void generateWorld(int number_of_preys, int number_of_predators,
                     int number_of_stones, int number_of_corals);
  void print() const;
  void addObject(Object*);
  void run();
  Cell* getCell(Pair);
};

#endif
