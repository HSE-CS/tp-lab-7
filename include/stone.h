//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include "object.h"

class Stone : public Object {
 public:
  explicit Stone(ObjType type, Cell *cell) :
      Object(type, cell),
      ot(type) {}
  void live() override;

 private:
  ObjType ot;
};

#endif  //  INCLUDE_STONE_H_
