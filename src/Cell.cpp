//  Copyright 2021 GHA created by Klykov Anton

#include "Cell.h"

Cell::Cell(Pair pair, Ocean* ocean) {
  c_pair = pair;
  c_ocean = ocean;
  c_object = nullptr;
}
Object* Cell::getObject() {
  return c_object;
}
void Cell::SetObject(Object* object) {
  c_object = object;
}
Ocean* Cell::getOcean() {
  return c_ocean;
}
Pair* Cell::getPair() {
  return &c_pair;
}
void Cell::delObject() {
  c_object = nullptr;
}
