//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "Cell.h"
#include <iostream>
#include <string>

class Cell;

class Object {
 protected:
  Cell* obj_cell;  //Связь объекта с клеткой

 public:
  virtual ~Object();
  explicit Object(Cell* cell);
  virtual void live() = 0;  // Виртуальный метод для перемещения по океану
  void SetCell(Cell* cell);
  virtual std::string getName();
};

#endif 
