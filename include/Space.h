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
    int priority;
    int posX;
    int posY;
public:
    explicit Cell(int X,
                  int Y,
                  char filler,
                  int backgroundColor1,
                  int symbolColor1);

    ~Cell();

    char getFiller();

    void setFiller(char c);

    Object *getObject();

    void setObject(Object *object1);

    [[nodiscard]] int getSymbolColor() const;

    void setSymbolColor(int color);

    [[nodiscard]] int getBackgroundColor() const;

    void setBackgroundColor(int color);
};


class Space {
private:
    std::vector<std::vector<Cell *>> space;
    std::vector<std::vector<char>> prevCondition;
    std::vector<std::vector<char>> nextCondition;
public:
    explicit Space();

    void setCell(int x, int y, Cell *cell);

    Cell *getCell(int x, int y);
};

class Scene {
private:
    std::vector<std::vector<char>> prevCondition;
    std::vector<std::vector<char>> nextCondition;
    std::vector<std::vector<int>> prevConditionColor;
    std::vector<std::vector<int>> nextConditionColor;
    AbstractScene scene_;
public:
    explicit Scene(int sceneNumber);

    void rawRender();

    void render(int frequency, bool safe);

};

class Movie {
public:
    static void setStartDisplayCondition();

    static void setStartDisplayColors();

    static void renderStartDisplay();

    static void wait(int seconds);

    static void setAreaToNormalCondition(int startX, int startY, int finishX, int finishY);

    void setDisplayToSpace();

    void renderSpaceDisplay();
};


#endif //TP_LAB_7_SPACE_H
