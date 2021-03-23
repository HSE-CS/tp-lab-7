// Copyright 2021 Ilya Urtyukov
#include "prey.h"
#include "common.h"
#include <iostream>
#include <random>

void Prey::live() {
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

Prey::~Prey() {}
