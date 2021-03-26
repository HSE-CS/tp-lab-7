// Copyright DB 2021
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <string>
#include <iostream>

typedef size_t coord_t;

struct Pair {
  coord_t x_cord;
  coord_t y_cord;
};

const size_t N = 40;
const size_t M = 100;

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell;

class Object {
 protected:
  Cell* cell;
  int objType;

 public:
  Object() {
    cell = nullptr;
    objType = -1;
  }
  virtual ~Object() {
    cell = nullptr;
    objType = -1;
  }
  virtual void setCell(Cell* cl) = 0;
  virtual void live() = 0;
  virtual void printObject() = 0;
  virtual char getObjectChar() = 0;
  virtual int getObjectINT() = 0;
};
#endif  // INCLUDE_COMMON_H_