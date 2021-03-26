// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_
#include "../include/common.h"
#include "../include/object.h"

class Ocean;

class Cell {
  friend Ocean;

 private:
  Pair cord;
  Object *obj;
  Ocean *ocean;

 public:
  explicit Cell(Pair p = {0, 0}, Ocean *oc = nullptr) :
      cord(p),
      obj(nullptr),
      ocean(oc) {}
  bool checkPrey(Cell *cellToCheck) const;
  [[nodiscard]] Cell *huntStart() const;
  void killMe();
  void initial(Pair p, Ocean *oc);
  [[nodiscard]] Object *getObject() const;
  [[nodiscard]] Ocean *getOcean() const;
  void setObject(Object *object);
  Cell *findMove();

};

#endif  //  INCLUDE_CELL_H_
