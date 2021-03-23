// Copyright 2021 Dev-will-work
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType {STONE, CORAL, PREY, PREDATOR};

class Cell;
class Object {
 protected:
  Cell *cell;
  ObjType type;
  size_t lifetime;
 public:
  explicit Object(Cell * = nullptr);
  virtual ~Object();
  virtual void live() = 0;  // object logic
  void setCell(Cell*);
  virtual Cell* getCell();
  virtual ObjType getType();
  virtual void print() = 0;
};
#endif  // INCLUDE_OBJECT_H_
