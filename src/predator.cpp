//  Copyright © 2021 Ksuvot
#include "Predator.h"
#include <cmath>

Object* Predator::Searching(Ocean* ocean) {
    eating = false;
    Object* targetObj = nullptr;
    double target = 100000000;
    int targdiff_x = 0;
    int targdiff_y = 0;
    for (Object* obj : (*ocean).getStuff()) {
        if (obj->getType() == ObjType::PREY) {
            int diff_x = (obj->getPair().x - pair_.x);
            int diff_y = (obj->getPair().y - pair_.y);
            double buf_target = sqrt(pow(diff_x, 2) + pow(diff_y, 2));
            if (buf_target < 2) {
                targetObj = obj;
                targdiff_x = diff_x;
                targdiff_y = diff_y;
                target = buf_target;
                eating = true;
                break;
            } else if ((obj->getType() == ObjType::PREY)
                && (target > buf_target)) {
                targetObj = obj;
                targdiff_x = diff_x;
                targdiff_y = diff_y;
                target = buf_target;
            }
        }
    }
    if (!eating) {
        if ((targdiff_x > 0) && (targdiff_y > 0))
            PrepForMOVE(Move::DOWNRIGHT, ocean);
        else if ((targdiff_x > 0) && (targdiff_y == 0))
            PrepForMOVE(Move::DOWN, ocean);
        else if ((targdiff_x > 0) && (targdiff_y < 0))
            PrepForMOVE(Move::DOWNLEFT, ocean);
        else if ((targdiff_x == 0) && (targdiff_y < 0))
            PrepForMOVE(Move::LEFT, ocean);
        else if ((targdiff_x < 0) && (targdiff_y < 0))
            PrepForMOVE(Move::UPLEFT, ocean);
        else if ((targdiff_x < 0) && (targdiff_y == 0))
            PrepForMOVE(Move::UP, ocean);
        else if ((targdiff_x < 0) && (targdiff_y > 0))
            PrepForMOVE(Move::UPRIGHT, ocean);
        else if ((targdiff_x == 0) && (targdiff_y > 0))
            PrepForMOVE(Move::RIGHT, ocean);
    } else {
      eat += 10;
    }
    return targetObj;
}

void Predator::live() {
    eat--;
    if (!eating) {
        switch (this->move_) {
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
          case Move::STAY:break;
        }
    }
}
