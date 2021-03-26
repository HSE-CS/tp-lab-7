//// Copyright 2021 Lukicheva Polina

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"
#include "ocean.h"
#include "object.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell {
  friend Ocean;
private:
  Pair crd;
  Object* obj;
  Ocean* ocean;
public:
  explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
    crd(p),
    obj(nullptr),
    ocean(oc) {}
  void init(Pair p, Ocean* oc);
  Object* getObject() const;
  Ocean* getOcean() const;
  void setObject(Object* obj);
  int getX() const;
  int getY() const;
  void killMe();
  bool isEmpty() const;
};
#endif