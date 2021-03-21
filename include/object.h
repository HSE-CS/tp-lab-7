// Copyright 2021 VadMack

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include <string>
enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell;
class Object {
 protected:
  Cell *cell;
  std::string color;

 public:
  explicit Object(Cell *cell = nullptr);
  virtual ~Object();
  virtual void live() = 0;

  Cell *GetCell() const {
    return cell;
  }

  void setCell(Cell *cell) {
    this->cell = cell;
  }

  const std::string &GetColor() const {
    return color;
  }
  void SetColor(const std::string &color) {
    Object::color = color;
  }
};

#endif  // INCLUDE_OBJECT_H_
