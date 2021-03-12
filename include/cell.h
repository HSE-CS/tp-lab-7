//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef _CELL_H_
#define _CELL_H_

//#include "common.h"
#include "object.h"

class Ocean;

class Cell {
 private:
  Pair crd;
  Object *obj;
  Ocean *ocean;

 public:
  explicit Cell(Pair p = {0, 0}, Ocean* oc = nullptr):
  crd(p), obj(nullptr), ocean(oc) {}
  void init(Pair p, Ocean* oc);
  Pair getCrd();
  Object* getObject();
  Ocean* getOcean();
  void setObject(Object* newObj);
  bool isEmpty() const;

  friend Ocean;
};

#endif // _CELL_H_
