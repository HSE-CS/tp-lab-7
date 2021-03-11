#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "cell.h"
#include "predator.h"
#include "prey.h"
#include "stone.h"
#include <vector>
#include <list>

class Ocean {
 private:
  Cell **cells;
  std::vector<Object *> stuff;

 public:
  Ocean();
  ~Ocean();
  void AddStuff(Object *obj);
  void addObjects(unsigned int n, ObjType type);
  bool DeleteObj(Object *obj);
  void run();
  void print() const;
  Cell *Step(Pair crd);
  Cell *Radar(Pair cord);
};
#endif
