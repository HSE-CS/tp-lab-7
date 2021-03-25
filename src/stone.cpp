// Copyright GN 2021
#include "../include/stone.h"

void Stone::setObjectType() { this->objType = 0; }
void Stone::setCell(Cell* c) { this->cell = c; }
void Stone::init(Cell* c) {
  this->setObjectType();
  this->setCell(c);
}
void Stone::printObject() { std::cout << STONE_N; }
int Stone::getObjectINT() { return this->objType; }
char Stone::getObjectChar() { return STONE_N; }
void Stone::live(){}
void Coral::setObjectType() { this->objType = 1; }
void Coral::setCell(Cell* c) { this->cell = c; }
void Coral::init(Cell* c) {
  this->setObjectType();
  this->setCell(c);
}
void Coral::live() {}
int Coral::getObjectINT() { return this->objType; }
void Coral::printObject() { std::cout << CORAL_N; }
char Coral::getObjectChar() { return CORAL_N; }
