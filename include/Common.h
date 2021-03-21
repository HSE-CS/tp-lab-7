  // Copyright Baklanov 2021
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

#include "Ocean.h"
#include <string>

enum class ObjType { STONE, CORAL, PREY, PREDATOR };
enum class Move {UPLEFT, UP, UPRIGHT, RIGHT,
    DOWNRIGHT, DOWN, DOWNLEFT, LEFT, STAY};

typedef size_t coord_t;


struct Pair {
    coord_t x;
    coord_t y;
};

const size_t N = 20;
const size_t M = 50;

class Cell;
class Ocean;

class Object {
 protected:
    Cell* cell;
    ObjType type;
    Pair coord;
    Move prepairForMove;

 public:
    Object(ObjType type, Pair coord_, Cell* cell_) :
        type(type), coord(coord_), cell(cell_), prepairForMove(Move::STAY) {}
    virtual ~Object();
    void Reproduction(Ocean* ocean_);
    void PrepForMOVE(Move move, Ocean* ocean_);
    virtual void live() = 0;
    void setCell(Cell* a);
    ObjType getType() {
        return type;
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
    Pair getCoord() {
        return coord;
    }
    Move getMovePrep() {
        return this->prepairForMove;
    }
    void setCoord(Pair coord_) {
        coord = coord_;
    }
};

class Coral : public Object {
 public:
     Coral(Pair coord, Cell* cell) :
         Object(ObjType::CORAL, coord, cell) {}
     ~Coral() {}
     void live() override;
};
#endif  // INCLUDE_COMMON_H_
