//  Copyright © 2021 Ksuvot
#include "Cell.h"

void Cell::init(Pair pair, Ocean* p_ocean) {
  pair_ = pair;
  ocean_ = p_ocean;
}

Object* Cell::getObject() {
  return object_;
}

void Cell::setObject(Object* object) {
  object_ = object;
  if (object)
    is_empty = false;
  else
    is_empty = true;
}

bool Cell::is_Empty() {
  return is_empty;
}

void Cell::killMe() {
  is_empty = true;
  delete object_;
}
