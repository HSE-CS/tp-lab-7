// Copyright 2021 Dev-will-work
#include "stone.h"
#include "cell.h"

Stone::Stone() {
  this->type = ObjType::STONE;
  this->lifetime = STONE_LIFE;
}

Stone::~Stone() {}

void Stone::live() {
  if (!this->cell) return;
  if (this->lifetime > 0) {
    this->lifetime--;
  } else {
    this->cell->killMe();
  }
}
// object logic

void Stone::print() {
  std::cout << STONE_N;
}
