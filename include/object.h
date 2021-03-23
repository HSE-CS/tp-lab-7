// Copyright by Egor Bodrov 2021

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

enum class ObjectType { STONE, PREY, PREDATOR };

class Cell;

class Object {
 protected:
  Cell* cell;
  ObjectType type{};

 public:
  explicit Object(Cell* cell = nullptr);

  ~Object();

  virtual void live() = 0;

  void setCell(Cell* cell);

  Cell* getCell();

  void setType(ObjectType type);

  ObjectType getType();

  char getSymbol();
};

#endif  // INCLUDE_OBJECT_H_