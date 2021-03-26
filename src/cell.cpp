// Copyright 2020 Uskova

#include "cell.h"

void Cell::init(Pair p, Ocean* oc) {
    this->ocean = oc;
    this->crd = p;
    this->obj = nullptr;
}

Object* Cell::getObject() {
  if (obj) {
      return this->obj;
  } else {
     return nullptr;
  }
}

Pair Cell::getCrd() {
    return this->crd;
}

void Cell::setObject(Object* ob) {
    this->obj = ob;
}


Cell* Cell::freePlace() {
  srand(time(0));
  Cell** oc = this->ocean->getOcean();
  Cell* north = &oc[this->crd.x - 1][this->crd.y];
  std::vector<Cell*> variants;
  if (this->crd.x != 0) {
    if (north->obj == nullptr) {
      variants.push_back(north);
    }
  }
  Cell* south = &oc[this->crd.x + 1][this->crd.y];
  if (this->crd.x != N - 1) {
    if (south->obj == nullptr) {
      variants.push_back(south);
    }
  }
  Cell* east = &oc[this->crd.x][this->crd.y + 1];
  if (this->crd.y != M - 1) {
    if (east->obj == nullptr) {
      variants.push_back(east);
    }
  }
  Cell* west = &oc[this->crd.x][this->crd.y - 1];
  if (this->crd.y != 0) {
    if (west->obj == nullptr) {
      variants.push_back(west);
    }
  }
  Cell* res = nullptr;
  if (variants.size() != 0) {
    res = variants[rand() % variants.size()];
  }
  return res;
}

Ocean* Cell::getOcean() {
    return this->ocean;
}

//void Cell::killMe() {
//    this->ocean->deleteObj(this->obj);
 //   this->obj = nullptr;
//}

Cell* Cell::forHunting() {
  srand(time(0));
  Cell** oc = this->ocean->getOcean();
  std::vector<Cell*> variants;
  if (this->crd.x != 0) {
    Cell* north = &(oc[this->crd.x - 1][this->crd.y]);
    if (north->obj != nullptr) {
        if (north->obj->getType() == ObjType::PREY) {
          variants.push_back(north);
        }
    }    
  }
  if (this->crd.x != (N - 1)) {
    Cell* south = &(oc[this->crd.x + 1][this->crd.y]);
    if (south->obj != nullptr) {
      if (south->obj->getType() == ObjType::PREY) {
        variants.push_back(south);
      }
    }
  }
  if (this->crd.y != (M - 1)) {
    Cell* east = &(oc[this->crd.x][this->crd.y + 1]);
    if (east->obj != nullptr) {
      if (east->obj->getType() == ObjType::PREY) {
        variants.push_back(east);
      }
    }
  }
  if (this->crd.y != 0) {
    Cell* west = &(oc[this->crd.x][this->crd.y - 1]);
    if (west->obj != nullptr) {
      if (west->obj->getType() == ObjType::PREY) {
        variants.push_back(west);
      }
    }
  }
  Cell* res = nullptr;
  if (variants.size() != 0) {
    if (variants.size() != 1) {
      res = variants[rand() % (variants.size() - 1)];
    } else {
      res = variants[0];
    }
  }
  return res;
}
