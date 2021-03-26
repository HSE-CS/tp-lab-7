#ifndef _INCLUDE_CELL_H_
#define _INCLUDE_CELL_H_

#include "common.h"
#include "Object.h"
#include "ocean.h"

class Ocean;
class Object;

class Cell {
  friend Ocean;

 private:
  Pair crd;
  Object* obj;
  Ocean* ocean;

 public:
  explicit Cell(Pair p = {0, 0}, Ocean* oc = nullptr)
      : crd(p), obj(nullptr), ocean(oc){};
  void init(Pair p, Ocean* oc);
  Object* getObject() const;
  Ocean* getOcean();
  void setObject(Object*);
  void print();
  void killMe();
  Pair getCoord();
};

#endif  // _INCLUDE_CELL_H_