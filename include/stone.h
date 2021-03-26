// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include "../include/object.h"

class Stone : public Object {
 private:
  ObjType ot;
 public:
  explicit Stone(ObjType type, Cell *cell) :
      Object(type, cell),
      ot(type) {}
  void live() override;
};

#endif  //  INCLUDE_STONE_H_
