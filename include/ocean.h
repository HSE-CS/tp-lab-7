#ifndef _OCEAN_H_
#define _OCEAN_H_

#include <list>
#include <vector>

#include "cell.h"
#include "common.h"
#include "predator.h"
#include "prey.h"
#include "stone.h"

class Ocean {
 private:
  Cell **cells;
  std::list<Object *> stuff;

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
