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
    std::vector<Object *> objects;
public:
    explicit Space();

    void generateArmy(int rebels, int impery);

    void generateAsteroidField(int count);

    void setCellsForObject(Object * obj);

    int countSideObject(int side);

    static Object *shoot(Object *ship);

    void destroy(Object *object);

    void destroyWithExplosion(Object *object);

    static void explode(int x, int y, int radius);

    Object *scan(Object *whizzbang);  // Unsafe function

    void hit(Object *whizzbang, Object *target);

    void addObject(Object *obj);

    void removeObject(Object *obj);

    std::vector<Object *> *getObjects();

    Object *scan(Object *ship, int depth);

    void move(Object *object, int iteration);

    void relativeMove(Object *object);

    void moveUp(Object *object);

    void moveDown(Object *object);

    void moveLeft(Object *object);

    void moveRight(Object *object);

    void setCell(int x, int y, Cell *cell);

    Cell *getCell(int x, int y);

    static double dist(int a, int b, int c, int d);
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

    static void wait(float seconds);

    static void setAreaToNormalCondition(int startX, int startY, int finishX, int finishY);

    static void setDisplayToSpace();

    static void renderSpaceDisplay();

    static void renderIntroduction();

    static void renderRebelsWin();




    static void renderImperyWin();
};


#endif // TP_LAB_7_SPACE_H
