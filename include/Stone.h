//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "Object.h"
#include <iostream>
#include <string>

class Stone : public Object {
 protected:
  std::string s_name;

 public:
  ~Stone() override;
  explicit Stone(std::string name, Cell* cell);
  void live() override;
  std::string getName() override;
};
#endif  // INCLUDE_STONE_H_
