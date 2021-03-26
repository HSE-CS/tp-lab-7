// Copyright 2021 Galex

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/object.h"

class Stone : public Object{
 public:
  explicit Stone(Cell* c = nullptr):Object(c){
    this->type_ = TYPE::STONE;
    this->cell = c;
  }
  std::string getOutput() override;
};
#endif  // INCLUDE_STONE_H_
