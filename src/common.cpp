#include "common.h"
#include "Ocean.h"
#include "Predator.h"
#include "Prey.h"
#include <iostream>

void Object::Reproduction(Ocean& ocean_) {
    int randmount = std::rand() % 8;
    for (int i = 0; i < randmount; ++i) {
        int randBorn = std::rand() % 8;
        Object* newObject;
        if (this->getType() == ObjType::PREDATOR) {
            newObject = new Predator(coord, &ocean_.cells[coord.x][coord.y]);
        }
        else {
            newObject = new Prey(coord, &ocean_.cells[coord.x][coord.y]);
        }
        int flag = 0;
        switch (static_cast<Move>(randBorn)) {
        case Move::DOWN:
            if ((coord.x != ocean_.getSizeX())
                &&(ocean_.cells[coord.x + 1][coord.y].isEmpty())) {
                newObject->MoveDOWN();
                flag = 1;
            }
            break;
        case Move::DOWNLEFT:
            if (((coord.x != ocean_.getSizeX()) && (coord.y != 0))
                &&(ocean_.cells[coord.x + 1][coord.y-1].isEmpty())) {
                newObject->MoveDOWNLEFT();
                flag = 1;
            }
            break;
        case Move::LEFT:
            if ((coord.y != 0)&&(ocean_.cells[coord.x][coord.y - 1].isEmpty())) {
                newObject->MoveLEFT();
                flag = 1;
            }
            break;
        case Move::UPLEFT:
            if (((coord.x) && (coord.y))
                &&(ocean_.cells[coord.x - 1][coord.y - 1].isEmpty())) {
                newObject->MoveUPLEFT();
                flag = 1;
            }
            break;
        case Move::UP:
            if ((coord.x)
                &&(ocean_.cells[coord.x - 1][coord.y].isEmpty())) {
                newObject->MoveUP();
                flag = 1;
            }
            break;
        case Move::UPRIGHT:
            if ((coord.x) && (coord.y != ocean_.getSizeY())
                &&(ocean_.cells[coord.x - 1][coord.y + 1].isEmpty())) {
                newObject->MoveUPRIGHT();
                flag = 1;
            }
            break;
        case Move::RIGHT:
            if ((coord.y != ocean_.getSizeY())
                &&(ocean_.cells[coord.x][coord.y + 1].isEmpty())) {
                newObject->MoveRIGHT();
                flag = 1;
            }
            break;
        case Move::DOWNRIGHT:
            if ((coord.x != ocean_.getSizeX()) && (coord.y != ocean_.getSizeY())
                &&(ocean_.cells[coord.x + 1][coord.y + 1].isEmpty())) {
                newObject->MoveDOWNRIGHT();
                flag = 1;
            }
            break;
        }
        if (flag) {
            ocean_.stuff.push_back(newObject);
            ocean_.cells[newObject->coord.x][newObject->coord.y].setObject(newObject);
        }
        else {
            newObject->~Object();
            delete newObject;
        }
    }
}

void Object::PrepForMOVE(Move move, Ocean& ocean_) {
    prepairForMove = move;
    switch (move) {
    case Move::DOWN:
        if ((coord.x != ocean_.getSizeX()) &&
            (ocean_.cells[coord.x + 1][coord.y].isEmpty())) {
            setCell(&ocean_.cells[coord.x + 1][coord.y]);
        }
        else {
            PrepForMOVE(Move::DOWNLEFT, ocean_);
        }
        break;
    case Move::UP:
        if ((coord.x != 0) &&
            (ocean_.cells[coord.x - 1][coord.y].isEmpty())) {
            setCell(&ocean_.cells[coord.x - 1][coord.y]);
        } else {
            PrepForMOVE(Move::UPRIGHT, ocean_);
        }
        break;
    case Move::LEFT:
        if ((coord.y != 0) &&
            (ocean_.cells[coord.x][coord.y - 1].isEmpty())) {
            setCell(&ocean_.cells[coord.x][coord.y - 1]);
        } else {
            PrepForMOVE(Move::UPLEFT, ocean_);
        }
        break;
    case Move::RIGHT:
        if ((coord.y != ocean_.getSizeY())
            && (ocean_.cells[coord.x][coord.y + 1].isEmpty())) {
            setCell(&ocean_.cells[coord.x][coord.y + 1]);
        } else {
            PrepForMOVE(Move::DOWNRIGHT, ocean_);
        }
        break;
    case Move::UPRIGHT:
        if (((coord.x != 0) && (coord.y != ocean_.getSizeY()))
            && (ocean_.cells[coord.x - 1][coord.y + 1].isEmpty())) {
            setCell(&ocean_.cells[coord.x - 1][coord.y + 1]);
        } else {
            PrepForMOVE(Move::RIGHT, ocean_);
        }
        break;
    case Move::DOWNRIGHT:
        if (((coord.x != ocean_.getSizeX()) && (coord.y != ocean_.getSizeY()))
            && (ocean_.cells[coord.x + 1][coord.y + 1].isEmpty())) {
            setCell(&ocean_.cells[coord.x + 1][coord.y + 1]);
        }else {
            PrepForMOVE(Move::DOWN, ocean_);
        }
        break;
    case Move::DOWNLEFT:
        if (((coord.x != ocean_.getSizeX()) && (coord.y != 0)) &&
            (ocean_.cells[coord.x + 1][coord.y - 1].isEmpty())) {
            setCell(&ocean_.cells[coord.x + 1][coord.y - 1]);
        } else {
            PrepForMOVE(Move::LEFT, ocean_);
        }
        break;
    case Move::UPLEFT:
        if (((coord.x != 0) && (coord.y != 0)) &&
                (ocean_.cells[coord.x - 1][coord.y - 1].isEmpty())) {
            setCell(&ocean_.cells[coord.x - 1][coord.y - 1]);
        }
        else {
            PrepForMOVE(Move::STAY, ocean_);
        }
        break;
    }
}

void Object::MoveUP() {
    coord.x -= 1;
}
void Object::MoveUPLEFT() {
    coord.x -= 1;
    coord.y -= 1;
}
void Object::MoveUPRIGHT() {
    coord.x -= 1;
    coord.y += 1;
}
void Object::MoveRIGHT() {
    coord.y += 1;
}
void Object::MoveDOWNRIGHT() {
    coord.x += 1;
    coord.y += 1;
}
void Object::MoveDOWN() {
    coord.x += 1;
}
void Object::MoveDOWNLEFT() {
    coord.x += 1;
    coord.y -= 1;
}
void Object::MoveLEFT() {
    coord.y -= 1;
}
void Object::MoveSTAY() {

}

void Object::setCell(Cell* a) {
    cell = a;
    //a->setObject(this);
}

void Coral::live() {

}

Object::~Object() {

}