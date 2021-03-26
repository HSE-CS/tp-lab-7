// Copyright 2021 Golovanov
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

class Cell;
class Object {
 protected:
    Cell* cell;
    char type;
 public:
    explicit Object(Cell* cell = nullptr);
    virtual ~Object();
    virtual void live() = 0;
    void setCell(Cell* cell);

    Cell* getCell();
    char getType();
    void setType(char type);
};

#endif  // INCLUDE_OBJECT_H_
