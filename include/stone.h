// Copyright 2020 Uskova
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "Object.h"

class Stone : public Object {
 //private:
   // ObjType type;
 public:
    explicit Stone(Cell*, ObjType);
    char getObjSym() override;
    void live() override;
    //ObjType getType();
};


#endif  // INCLUDE_STONE_H_
