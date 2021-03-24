//// Copyright 2021 Lukicheva Polina

#ifndef _PREY_H_
#define _PREY_H_

#include "stone.h"
#include "object.h"

class Prey : Stone {
private:
  ObjType objT;
  
public:
  explicit Prey();
  ~Prey();
  void live() override;
  
};
#endif
