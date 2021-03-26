// Copyright 2021 Galex

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include <iostream>
#include "../include/cell.h"
#include "../include/common.h"

class Cell;

enum class TYPE {
  STONE,
  PREY,
  PREDATOR
};

class Object {
  friend Cell;
 protected:
  Cell *cell;
  TYPE type_;
 public:
  Object(Cell * = nullptr);
  virtual ~Object();
  virtual void live();
  void setCell(Cell *);
  void setType(TYPE t);
  TYPE getType();
  virtual std::string getOutput() { return "\033[96;106mO\033[0m"; };
};
#endif  // INCLUDE_OBJECT_H_
