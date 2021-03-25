// Copyright 2021 Dumarevskaya
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <random>
#include "Cell.h"
#include "Ocean.h"

void Cell::init(Pair p, Ocean* oc) {
  crd = p;
  obj = nullptr;
  ocean = oc;
}

Object* Cell::getObject() const {
  return obj;
}

void Cell::setObject(Object* new_obj) {
  obj = new_obj;
}

Cell* Cell::findEmptyAround() {
  std::vector <Cell*> emptyCells;
  if (crd.x != 0 && crd.x != M - 1) {
    if (crd.y != 0 && crd.y != N - 1) {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (i != 0 && j != 0) {
            if (ocean->getCell(crd.x - i, crd.y - j)->obj == nullptr)
              emptyCells.push_back(ocean->getCell(crd.x - i, crd.y - j));
            if (ocean->getCell(crd.x + i, crd.y + j)->obj == nullptr)
              emptyCells.push_back(ocean->getCell(crd.x + i, crd.y + j));
            if (ocean->getCell(crd.x - i, crd.y + j)->obj == nullptr)
              emptyCells.push_back(ocean->getCell(crd.x - i, crd.y + j));
            if (ocean->getCell(crd.x + i, crd.y - j)->obj == nullptr)
              emptyCells.push_back(ocean->getCell(crd.x + i, crd.y - j));
          }
        }
      }
    } else {
      if (crd.y != 0) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x - i, crd.y - j)->obj == nullptr)
                emptyCells.push_back(ocean->getCell(crd.x - i, crd.y - j));
              if (ocean->getCell(crd.x + i, crd.y - j)->obj == nullptr)
                emptyCells.push_back(ocean->getCell(crd.x + i, crd.y - j));
            }
          }
        }
      } else if (crd.y != N - 1) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x + i, crd.y + j)->obj == nullptr)
                emptyCells.push_back(ocean->getCell(crd.x + i, crd.y + j));
              if (ocean->getCell(crd.x - i, crd.y + j)->obj == nullptr)
                emptyCells.push_back(ocean->getCell(crd.x - i, crd.y + j));
            }
          }
        }
      }
    }
  } else if (crd.x != 0) {
    if (crd.y != 0 && crd.y != N - 1) {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (i != 0 && j != 0) {
            if (ocean->getCell(crd.x - i, crd.y - j)->obj == nullptr)
              emptyCells.push_back(ocean->getCell(crd.x - i, crd.y - j));
            if (ocean->getCell(crd.x, crd.y + j)->obj == nullptr)
              emptyCells.push_back(ocean->getCell(crd.x, crd.y + j));
          }
        }
      }
    } else {
      if (crd.y != 0) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x - i, crd.y - j)->obj == nullptr)
                emptyCells.push_back(ocean->getCell(crd.x - i, crd.y - j));
            }
          }
        }
      } else if (crd.y != N - 1) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x - i, crd.y + j)->obj == nullptr)
                emptyCells.push_back(ocean->getCell(crd.x - i, crd.y + j));
            }
          }
        }
      }
    }
  } else if (crd.x != M - 1) {
    if (crd.y != 0 && crd.y != N - 1) {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (i != 0 && j != 0) {
            if (ocean->getCell(crd.x + i, crd.y + j)->obj == nullptr)
              emptyCells.push_back(ocean->getCell(crd.x + i, crd.y + j));
            if (ocean->getCell(crd.x + i, crd.y - j)->obj == nullptr)
              emptyCells.push_back(ocean->getCell(crd.x + i, crd.y - j));
          }
        }
      }
    } else {
      if (crd.y != 0) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x + i, crd.y - j)->obj == nullptr)
                emptyCells.push_back(ocean->getCell(crd.x + i, crd.y - j));
            }
          }
        }
      } else if (crd.y != N - 1) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x + i, crd.y + j)->obj == nullptr)
                emptyCells.push_back(ocean->getCell(crd.x + i, crd.y + j));
            }
          }
        }
      }
    }
  }
  if (emptyCells.empty())
    return nullptr;
  int random_choice = static_cast<int>(gen() % emptyCells.size());
  return emptyCells[random_choice];
}

Cell* Cell::findPreyAround() {
  std::vector <Cell*> victims;
  if (crd.x != 0 && crd.x != M - 1) {
    if (crd.y != 0 && crd.y != N - 1) {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (i != 0 && j != 0) {
            if (ocean->getCell(crd.x - i, crd.y - j)->obj != nullptr ||
              ocean->getCell(crd.x - i, crd.y - j)->obj->getObjType()
              == ObjType::PREY)
              victims.push_back(ocean->getCell(crd.x - i, crd.y - j));
            if (ocean->getCell(crd.x + i, crd.y + j)->obj != nullptr ||
              ocean->getCell(crd.x + i, crd.y + j)->obj->getObjType()
              == ObjType::PREY)
              victims.push_back(ocean->getCell(crd.x + i, crd.y + j));
            if (ocean->getCell(crd.x - i, crd.y + j)->obj != nullptr ||
              ocean->getCell(crd.x - i, crd.y + j)->obj->getObjType()
              == ObjType::PREY)
              victims.push_back(ocean->getCell(crd.x - i, crd.y + j));
            if (ocean->getCell(crd.x + i, crd.y - j)->obj != nullptr ||
              ocean->getCell(crd.x + i, crd.y - j)->obj->getObjType()
              == ObjType::PREY)
              victims.push_back(ocean->getCell(crd.x + i, crd.y - j));
          }
        }
      }
    } else {
      if (crd.y != 0) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x - i, crd.y - j)->obj != nullptr ||
                ocean->getCell(crd.x - i, crd.y - j)->obj->getObjType()
                == ObjType::PREY)
                victims.push_back(ocean->getCell(crd.x - i, crd.y - j));
              if (ocean->getCell(crd.x + i, crd.y - j)->obj != nullptr ||
                ocean->getCell(crd.x + i, crd.y - j)->obj->getObjType()
                == ObjType::PREY)
                victims.push_back(ocean->getCell(crd.x + i, crd.y - j));
            }
          }
        }
      } else if (crd.y != N - 1) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x + i, crd.y + j)->obj != nullptr ||
                ocean->getCell(crd.x + i, crd.y + j)->obj->getObjType()
                == ObjType::PREY)
                victims.push_back(ocean->getCell(crd.x + i, crd.y + j));
              if (ocean->getCell(crd.x - i, crd.y + j)->obj != nullptr ||
                ocean->getCell(crd.x - i, crd.y + j)->obj->getObjType()
                == ObjType::PREY)
                victims.push_back(ocean->getCell(crd.x - i, crd.y + j));
            }
          }
        }
      }
    }
  } else if (crd.x != 0) {
    if (crd.y != 0 && crd.y != N - 1) {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (i != 0 && j != 0) {
            if (ocean->getCell(crd.x - i, crd.y - j)->obj != nullptr ||
              ocean->getCell(crd.x - i, crd.y - j)->obj->getObjType()
              == ObjType::PREY)
              victims.push_back(ocean->getCell(crd.x - i, crd.y - j));
            if (ocean->getCell(crd.x, crd.y + j)->obj != nullptr ||
              ocean->getCell(crd.x, crd.y + j)->obj->getObjType()
              == ObjType::PREY)
              victims.push_back(ocean->getCell(crd.x, crd.y + j));
          }
        }
      }
    } else {
      if (crd.y != 0) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x - i, crd.y - j)->obj != nullptr ||
                ocean->getCell(crd.x - i, crd.y - j)->obj->getObjType()
                == ObjType::PREY)
                victims.push_back(ocean->getCell(crd.x - i, crd.y - j));
            }
          }
        }
      } else if (crd.y != N - 1) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x - i, crd.y + j)->obj != nullptr ||
                ocean->getCell(crd.x - i, crd.y + j)->obj->getObjType()
                == ObjType::PREY)
                victims.push_back(ocean->getCell(crd.x - i, crd.y + j));
            }
          }
        }
      }
    }
  } else if (crd.x != M - 1) {
    if (crd.y != 0 && crd.y != N - 1) {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (i != 0 && j != 0) {
            if (ocean->getCell(crd.x + i, crd.y + j)->obj != nullptr ||
              ocean->getCell(crd.x + i, crd.y + j)->obj->getObjType()
              == ObjType::PREY)
              victims.push_back(ocean->getCell(crd.x + i, crd.y + j));
            if (ocean->getCell(crd.x + i, crd.y - j)->obj != nullptr ||
              ocean->getCell(crd.x + i, crd.y - j)->obj->getObjType()
              == ObjType::PREY)
              victims.push_back(ocean->getCell(crd.x + i, crd.y - j));
          }
        }
      }
    } else {
      if (crd.y != 0) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x + i, crd.y - j)->obj != nullptr ||
                ocean->getCell(crd.x + i, crd.y - j)->obj->getObjType()
                == ObjType::PREY)
                victims.push_back(ocean->getCell(crd.x + i, crd.y - j));
            }
          }
        }
      } else if (crd.y != N - 1) {
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (i != 0 && j != 0) {
              if (ocean->getCell(crd.x + i, crd.y + j)->obj != nullptr ||
                ocean->getCell(crd.x + i, crd.y + j)->obj->getObjType()
                == ObjType::PREY)
                victims.push_back(ocean->getCell(crd.x + i, crd.y + j));
            }
          }
        }
      }
    }
  }
  if (victims.empty())
    return nullptr;
  int random_choice = static_cast<int>(gen() % victims.size());
  return victims[random_choice];
}

Ocean* Cell::getOcean() {
  return ocean;
}

void Cell::killMe() {
  ocean->addToDeleteObject(obj);
  obj = nullptr;
}
