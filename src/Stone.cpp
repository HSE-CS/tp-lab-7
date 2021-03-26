//  Copyright 2021 GHA created by Klykov Anton

#include "Stone.h"

Stone::Stone(std::string name, Cell* cell)
            : Object(cell) {
  s_name = name;
}
std::string Stone::getName() {
  return s_name;
}
void Stone::live() {
  return;
}
Stone::~Stone() {
  s_name = "";
}
