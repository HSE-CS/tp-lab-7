// Copyright 2021 Schenikova

#include "../include/cell.h"

void Cell::init(Pair p, Ocean* oc) {
  this->coords = p;
  this->ocean = oc;
}

Object* Cell::getObject() const {
  return this->object;
}

void Cell::setObject(Object* ob) {
  // delete this->object;
  this->object = ob;
  if (ob) {
    ob->setCell(this);
    // std::vector<Object*> obj;
    // obj.push_back(ob);
  }
}

void Cell::killMe() {
  // this->ocean->addToList(this->object);
  delete this->object;
  this->object = nullptr;
  // std::cout << "death";
}

void Object::setCell(Cell* c) {
  this->cell = c;
}


