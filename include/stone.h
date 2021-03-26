//// Copyright 2021 Lukicheva Polina

#ifndef _STONE_H_
#define _STONE_H_

#include "../include/object.h"

class Stone : public Object {
 private:
 public:
   explicit Stone(Cell* c) : Object(ObjType::STONE, c) { cell = c; }
   ~Stone();
   void live() override;
   void setCell(Cell*);
};
#endif
