// Copyright DB 2021

#include "stone.h"

void Stone::setObjectType() { this->objType = 0; }

void Stone::setCell(Cell* c) { this->cell = c; }

void Stone::printObject() { std::cout << STONE_N; }

int Stone::getObjectINT() { return this->objType; }

void Stone::init(Cell* c) {
  this->setObjectType();
  this->setCell(c);
}

char Stone::getObjectChar() { return STONE_N; }

void Stone::live() { /*No live*/ }

void Coral::setObjectType() { this->objType = 1; }

void Coral::setCell(Cell* c) { this->cell = c; }

int Coral::getObjectINT() { return this->objType; }

void Coral::printObject() { std::cout << CORAL_N; }

char Coral::getObjectChar() { return CORAL_N; }

void Coral::init(Cell* c) {
  this->setObjectType();
  this->setCell(c);
}

void Coral::live() { /*No live*/ }