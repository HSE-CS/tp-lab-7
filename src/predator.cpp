// Copyright 2021 Ilya Urtyukov
#include "predator.h"
#include "prey.h"
#include <cmath>

Object* Predator::Searching(Ocean* ocean) {
    readyForCatch = false;
    Object* targetObj = nullptr;
    double target = 100000000;
    int targdiffX = 0;
    int targdiffY = 0;
    for (Object* obj : (*ocean).getStuff()) {
        if (obj->getType() == ObjType::PREY) {
            int diffX = (obj->getCoord().x - coord.x);
            int diffY = (obj->getCoord().y - coord.y);
            double bufTarget = sqrt(diffX*diffX + diffY*diffY);
            if (bufTarget < 2) {
                targetObj = obj;
                targdiffX = diffX;
                targdiffY = diffY;
                target = bufTarget;
                readyForCatch = true;
                break;
            } else if ((obj->getType() == ObjType::PREY)
                && (target > bufTarget)) {
                targetObj = obj;
                targdiffX = diffX;
                targdiffY = diffY;
                target = bufTarget;
            }
        }
    }
    if (!readyForCatch) {
        if ((targdiffX > 0) && (targdiffY > 0))
            PrepForMOVE(Move::DOWNRIGHT, ocean);
        else if ((targdiffX > 0) && (targdiffY == 0))
            PrepForMOVE(Move::DOWN, ocean);
        else if ((targdiffX > 0) && (targdiffY < 0))
            PrepForMOVE(Move::DOWNLEFT, ocean);
        else if ((targdiffX == 0) && (targdiffY < 0))
            PrepForMOVE(Move::LEFT, ocean);
        else if ((targdiffX < 0) && (targdiffY < 0))
            PrepForMOVE(Move::UPLEFT, ocean);
        else if ((targdiffX < 0) && (targdiffY == 0))
            PrepForMOVE(Move::UP, ocean);
        else if ((targdiffX < 0) && (targdiffY > 0))
            PrepForMOVE(Move::UPRIGHT, ocean);
        else if ((targdiffX == 0) && (targdiffY > 0))
            PrepForMOVE(Move::RIGHT, ocean);
    } else {
        hunger += 5;
    }
    return targetObj;
}

void Predator::live() {
    hunger--;

     if (!readyForCatch) {
        switch (this->prepairForMove) {
        case Move::DOWN:this->MoveDOWN();
            break;
        case Move::DOWNLEFT:this->MoveDOWNLEFT();
            break;
        case Move::LEFT:this->MoveLEFT();
            break;
        case Move::UPLEFT:this->MoveUPLEFT();
            break;
        case Move::UP:this->MoveUP();
            break;
        case Move::UPRIGHT:this->MoveUPRIGHT();
            break;
        case Move::RIGHT:this->MoveRIGHT();
            break;
        case Move::DOWNRIGHT:this->MoveDOWNRIGHT();
            break;
        }
    }
}
