#ifndef _INCLUDE_STONE_H_
#define _INCLUDE_STONE_H_

#include "Object.h"

class Cell;

class Stone : public Object {
 public:
  explicit Stone(Cell *cell_);
  void live() override;

};

#endif  // _INCLUDE_STONE_H_
