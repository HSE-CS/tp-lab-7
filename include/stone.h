//// Copyright 2021 Lukicheva Polina

#ifndef _STONE_H_
#define _STONE_H_

#include "object.h"

class Stone : public Object {
 private:
 public:
   explicit Stone();
   ~Stone();
   void live() override;
};
#endif
