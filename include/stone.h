// Copyright GN 2021
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/common.h"
#include "../include/Object.h"
#include "../include/cell.h"
#include "../include/ocean.h"

class Object;
class Stone : public Object {
 public:
  void setObjectType();
    void live();
    void printObject();
    void setCell(Cell* c);
    void init(Cell* c);
    int getObjectINT();
    char getObjectChar();
};


class Coral : public Object {
 private:
  size_t time_of_life = 1;

 public:
  void setObjectType();
  void live();
  void printObject();
  void setCell(Cell* c);
  void init(Cell* c);
  int getObjectINT();
  char getObjectChar();
};
#endif  // INCLUDE_STONE_H_
