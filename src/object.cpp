// Copyright by Egor Bodrov 2021

#include "object.h"

Object::Object(Cell* cell) { this->cell = cell; }

Object::~Object() { this->cell = nullptr; }

void Object::setCell(Cell* cell) { this->cell = cell; }

Cell* Object::getCell() { return this->cell; }

void Object::setType(ObjectType type) { this->type = type; }

ObjectType Object::getType() { return this->type; }

char Object::getSymbol() {
    switch (this->getType()) {
    case ObjectType::STONE:
      return STONE_N;
    case ObjectType::PREY:
      return PREY_N;
    case ObjectType::PREDATOR:
      return PRED_N;
    }
}