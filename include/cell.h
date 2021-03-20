// Copyright 2021 VadMack

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include <string>
#include "common.h"
#include "ocean.h"

#define RED "\033[31;41m- \33[0m"
#define GREY "\033[90;100m- \33[0m"
#define PINK "\033[95;105m- \33[0m"
#define BLUE "\033[96;106m- \33[0m"


class Ocean;
class Object;
class Cell
{
  friend Ocean;
 private:
  Pair crd;
  Object *obj;
  Ocean *ocean;

 public:
  explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
      crd(p),
      obj(nullptr),
      ocean(oc) {

  }
  void init(Pair p, Ocean* oc);
  Object* getObject() const;
  void setObject(Object*);
  void killMe();

  Cell * findCellAround();

  Ocean *GetOcean() const;
  void SetOcean(Ocean *ocean);

};

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell;
class Object {
 protected:
  Cell *cell;
  std::string color;

 public:
  Object(Cell *cell = nullptr) : cell(cell) {
  }
  virtual ~Object() = default;
  virtual void live() = 0; // жизнь объекта

  Cell *GetCell() const {
    return cell;
  }

  void setCell(Cell *cell){
    this->cell = cell;
  }

  const std::string &GetColor() const {
    return color;
  }
  void SetColor(const std::string &color) {
    Object::color = color;
  }

};

#endif  // INCLUDE_CELL_H_
