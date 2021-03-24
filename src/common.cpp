//  Copyright © 2021 Ksuvot
#include "Ocean.h"
#include "Predator.h"
#include "Prey.h"
#include "Common.h"
#include <iostream>

void Object::Reproduction(Ocean* ocean_) {
    int randmount = std::rand() % 8;
    for (int i = 0; i < randmount; ++i) {
        int randBorn = std::rand() % 8;
        Object* newObject;
        if (this->getType() == ObjType::PREDATOR) {
            newObject = new Predator(pair_, &ocean_->cells[pair_.x][pair_.y]);
        } else {
            newObject = new Prey(pair_, &ocean_->cells[pair_.x][pair_.y]);
        }
        int flag = 0;
        switch (static_cast<Move>(randBorn)) {
        case Move::DOWN:
            if ((pair_.x != ocean_->getX())
                &&(ocean_->cells[pair_.x + 1][pair_.y].is_Empty())) {
                newObject->MoveDOWN();
                flag = 1;
            }
            break;
        case Move::DOWNLEFT:
            if (((pair_.x != ocean_->getX()) && (pair_.y != 0))
                &&(ocean_->cells[pair_.x + 1][pair_.y - 1].is_Empty())) {
                newObject->MoveDOWNLEFT();
                flag = 1;
            }
            break;
        case Move::LEFT:
            if ((pair_.y != 0)&&(ocean_->cells[pair_.x]
            [pair_.y - 1].is_Empty())) {
                newObject->MoveLEFT();
                flag = 1;
            }
            break;
        case Move::UPLEFT:
            if (((pair_.x) && (pair_.y))
                &&(ocean_->cells[pair_.x - 1][pair_.y - 1].is_Empty())) {
                newObject->MoveUPLEFT();
                flag = 1;
            }
            break;
        case Move::UP:
            if ((pair_.x)
                &&(ocean_->cells[pair_.x - 1][pair_.y].is_Empty())) {
                newObject->MoveUP();
                flag = 1;
            }
            break;
        case Move::UPRIGHT:
            if ((pair_.x) && (pair_.y != ocean_->getY())
                &&(ocean_->cells[pair_.x - 1][pair_.y + 1].is_Empty())) {
                newObject->MoveUPRIGHT();
                flag = 1;
            }
            break;
        case Move::RIGHT:
            if ((pair_.y != ocean_->getY())
                &&(ocean_->cells[pair_.x][pair_.y + 1].is_Empty())) {
                newObject->MoveRIGHT();
                flag = 1;
            }
            break;
        case Move::DOWNRIGHT:
            if ((pair_.x != ocean_->getX())
                && (pair_.y != ocean_->getY())
                &&(ocean_->cells[pair_.x + 1][pair_.y + 1].is_Empty())) {
                newObject->MoveDOWNRIGHT();
                flag = 1;
            }
            break;
        }
        if (flag) {
            ocean_->stuff.push_back(newObject);
            ocean_->cells[newObject->pair_.x]
                [newObject->pair_.y].setObject(newObject);
        } else {
            newObject->~Object();
            delete newObject;
        }
    }
}

void Object::PrepForMOVE(Move move, Ocean* ocean_) {
  move_ = move;
    switch (move) {
    case Move::DOWN:
        if ((pair_.x != ocean_->getX()) &&
            (ocean_->cells[pair_.x + 1][pair_.y].is_Empty())) {
            setCell(&ocean_->cells[pair_.x + 1][pair_.y]);
        } else {
            PrepForMOVE(Move::DOWNLEFT, ocean_);
        }
        break;
    case Move::UP:
        if ((pair_.x != 0) &&
            (ocean_->cells[pair_.x - 1][pair_.y].is_Empty())) {
            setCell(&ocean_->cells[pair_.x - 1][pair_.y]);
        } else {
            PrepForMOVE(Move::UPRIGHT, ocean_);
        }
        break;
    case Move::LEFT:
        if ((pair_.y != 0) &&
            (ocean_->cells[pair_.x][pair_.y - 1].is_Empty())) {
            setCell(&ocean_->cells[pair_.x][pair_.y - 1]);
        } else {
            PrepForMOVE(Move::UPLEFT, ocean_);
        }
        break;
    case Move::RIGHT:
        if ((pair_.y != ocean_->getY())
            && (ocean_->cells[pair_.x][pair_.y + 1].is_Empty())) {
            setCell(&ocean_->cells[pair_.x][pair_.y + 1]);
        } else {
            PrepForMOVE(Move::DOWNRIGHT, ocean_);
        }
        break;
    case Move::UPRIGHT:
        if (((pair_.x != 0) && (pair_.y != ocean_->getY()))
            && (ocean_->cells[pair_.x - 1][pair_.y + 1].is_Empty())) {
            setCell(&ocean_->cells[pair_.x - 1][pair_.y + 1]);
        } else {
            PrepForMOVE(Move::RIGHT, ocean_);
        }
        break;
    case Move::DOWNRIGHT:
        if (((pair_.x != ocean_->getX()) && (pair_.y != ocean_->getY()))
            && (ocean_->cells[pair_.x + 1][pair_.y + 1].is_Empty())) {
            setCell(&ocean_->cells[pair_.x + 1][pair_.y + 1]);
        } else {
            PrepForMOVE(Move::DOWN, ocean_);
        }
        break;
    case Move::DOWNLEFT:
        if (((pair_.x != ocean_->getX()) && (pair_.y != 0)) &&
            (ocean_->cells[pair_.x + 1][pair_.y - 1].is_Empty())) {
            setCell(&ocean_->cells[pair_.x + 1][pair_.y - 1]);
        } else {
            PrepForMOVE(Move::LEFT, ocean_);
        }
        break;
    case Move::UPLEFT:
        if (((pair_.x != 0) && (pair_.y != 0)) &&
                (ocean_->cells[pair_.x - 1][pair_.y - 1].is_Empty())) {
            setCell(&ocean_->cells[pair_.x - 1][pair_.y - 1]);
        } else {
            PrepForMOVE(Move::STAY, ocean_);
        }
        break;
    }
}

void Object::MoveUP() {
  pair_.x -= 1;
}
void Object::MoveUPLEFT() {
  pair_.x -= 1;
  pair_.y -= 1;
}
void Object::MoveUPRIGHT() {
  pair_.x -= 1;
  pair_.y += 1;
}
void Object::MoveRIGHT() {
  pair_.y += 1;
}
void Object::MoveDOWNRIGHT() {
  pair_.x += 1;
  pair_.y += 1;
}
void Object::MoveDOWN() {
  pair_.x += 1;
}
void Object::MoveDOWNLEFT() {
  pair_.x += 1;
  pair_.y -= 1;
}
void Object::MoveLEFT() {
  pair_.y -= 1;
}

void Object::MoveSTAY() {}

void Object::setCell(Cell* a) {
    cell = a;
}

void Coral::live() {}

Object::~Object() {}
