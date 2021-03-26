// Copyright JMax 2021

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_
#include "../include/Common.h"
#include "../include/Cell.h"

class Cell;
class Object {
    friend Cell;

 protected:
    Cell* cell;
    objectType type;
    int age;
    int size;
    bool alive;
    void increaseAge();
    bool checkAge() const;
    static int getRandom(int max);

 private:
    char getSymbolByAging(char ifTrue, char ifFalse) const;

 public:
    Object(objectType type, Cell* cell) : type(type), cell(cell) {
        age = 0;
        size = 0;
        alive = true;
    };
    virtual ~Object();

    virtual void live() = 0;
    objectType getType() const;
    void changeCell(Cell* cell);
    void death();
    bool isAlive() const;
    char getSymbol();
    int getSize() const;
};

#endif  // INCLUDE_OBJECT_H_
