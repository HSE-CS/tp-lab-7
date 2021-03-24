// Copyright © 2021 Ksuvot
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

#include "Ocean.h"
#include <string>

typedef size_t coord_t;

struct Pair {
    coord_t x;
    coord_t y;
};

const size_t N = 20;
const size_t M = 50;

enum class ObjType { STONE, CORAL, PREY, PREDATOR };
enum class Move {UPLEFT, UP, UPRIGHT, RIGHT,
    DOWNRIGHT, DOWN, DOWNLEFT, LEFT, STAY};

class Cell;
class Ocean;

class Object {
 protected:
    Cell* cell;
    ObjType obj_type_;
    Pair pair_;
    Move move_;

 public:
    Object(ObjType obj_type, Pair pair, Cell* cell_) :
        obj_type_(obj_type), pair_(pair), cell(cell_), move_(Move::STAY) {}
    virtual ~Object();
    void Reproduction(Ocean* ocean_);
    void PrepForMOVE(Move move, Ocean* ocean_);
    virtual void live() = 0;
    void setCell(Cell* a);
    ObjType getType() {
        return obj_type_;
    }
    void MoveUP();
    void MoveUPLEFT();
    void MoveUPRIGHT();
    void MoveRIGHT();
    void MoveDOWNRIGHT();
    void MoveDOWN();
    void MoveDOWNLEFT();
    void MoveLEFT();
    void MoveSTAY();
    Pair getPair() {
        return pair_;
    }
    Move getMove() {
        return this->move_;
    }
    void setPair(Pair pair) {
      pair_ = pair;
    }
};

class Coral : public Object {
 public:
     Coral(Pair pair, Cell* cell) :
         Object(ObjType::CORAL, pair, cell) {}
     ~Coral() override = default;
     void live() override;
};
#endif  // INCLUDE_COMMON_H_
