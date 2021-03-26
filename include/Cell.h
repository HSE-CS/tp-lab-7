//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "parametr.h"
class Object;
class Ocean;

class Cell {
 private:
  Object* c_object;  // Связь клетки с объектом - Агрегация
  Ocean* c_ocean;  // Связь клетки с океаном - Композиция
  Pair c_pair;  // Координаты клетки

 public:
  explicit Cell(Pair pair = {0, 0},
                Ocean* ocean = nullptr);
  Object* getObject();
  void SetObject(Object* object);
  Ocean* getOcean();
  Pair* getPair();
  void delObject();
};

#endif

