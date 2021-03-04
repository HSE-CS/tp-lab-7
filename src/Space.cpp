//
// Created by Данил on 04.03.2021.
//

#include "../include/Space.h"
#include "../include/Objects.h"


Cell::~Cell() {
    this->object = nullptr;
}

char Cell::getFiller() {
    return this->filler;
}

void Cell::setFiller(char c) {
    this->filler = c;
}

Object *Cell::getObject() {
    return this->object;
}

void Cell::setObject(Object *object1) {
    this->object = object1;
}

int Cell::getSymbolColor() const {
    return symbolColor;
}

void Cell::setSymbolColor(int color) {
    this->symbolColor = color;
}

int Cell::getBackgroundColor() const {
    return backgroundColor;
}

void Cell::setBackgroundColor(int color) {
    this->backgroundColor = color;
}

Cell::Cell(int X,
           int Y,
           char filler1,
           int backgroundColor1,
           int symbolColor1) {
    this->posX = X;
    this->posY = Y;
    this->filler = filler1;
    this->backgroundColor = backgroundColor1;
    this->symbolColor = symbolColor1;
    this->object = nullptr;
    this->priority = LOW_PRIORITY;
}

Space::Space() {
    this->prevCondition.resize(displayHeight);
    for (int i = 0; i < displayHeight; ++i) {
        for (int j = 0; j < displayWidth; ++j) {
            this->prevCondition[i].push_back(startSpacePicture[i][j]);
        }
    }
    this->nextCondition.resize(displayHeight);
    for (int i = 0; i < displayHeight; ++i) {
        for (int j = 0; j < displayWidth; ++j) {
            this->nextCondition[i].push_back(startSpacePicture[i][j]);
        }
    }
    for (int i = 0; i < displayHeight; ++i) {
        for (int j = 0; j < displayWidth; ++j) {
            int bcolor = black;
            int scolor = black;
            if (startSpacePicture[i][j] == '*') {
                scolor = white;
            }
            Cell *cell = new Cell(j, i, this->prevCondition[i][j], bcolor, scolor);
            this->space[i][j] = cell;
        }
    }
}

void Space::setCell(int x, int y, Cell *cell) {
    this->space[y][x] = cell;
}

Cell *Space::getCell(int x, int y) {
    return this->space[y][x];
}

Scene::Scene(int sceneNumber) {
    if (sceneNumber == TEST) {
        this->scene_.framesCount = __s_test::framesCount;
        this->scene_.frames.push_back(__s_test::__s_test_1());
        this->scene_.frames.push_back(__s_test::__s_test_2());
        this->scene_.frames.push_back(__s_test::__s_test_3());
        this->scene_.frames.push_back(__s_test::__s_test_4());


    }
}

void Scene::rawOut() {
    for (int i = 0; i < this->scene_.framesCount; ++i) {
        system("cls");
        setCursorPosition(0, 0);
        for (int j = 0; j < this->scene_.frames[i].sizeX; ++j) {
            for (int k = 0; k < this->scene_.frames[i].sizeX; ++k) {
                std::cout << this->scene_.frames[i].image[j][k];
            }
            std::cout << '\n';
        }
        Sleep(100);
//        std::cout << this->scene_.frames[i].sizeX << '\n';
    }
}
