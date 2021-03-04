//
// Created by Данил on 04.03.2021.
//

#ifndef TP_LAB_7_SPACE_H
#define TP_LAB_7_SPACE_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <random>
#include <windows.h>

#include "common.h"

class Object;

class Cell {
private:
    Object *object;
    char filler;
    int symbolColor;
    int backgroundColor;
public:
    explicit Cell(Object *object1);

    ~Cell();

    char getFiller();

    void setFiller(char c);

    Object *getObject();

    void setObject(Object *object1);
};

class Space {
private:
};


#endif //TP_LAB_7_SPACE_H
