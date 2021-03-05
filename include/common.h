//
// Created by Данил on 04.03.2021.
//

#ifndef TP_LAB_7_COMMON_H
#define TP_LAB_7_COMMON_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>

#include "scenes.h"

static char __hitbox_void = '-';
static char __hitbox_solid = '+';

enum SceneNumber {
    TEST,
    INTRO,
    ALONGTIMEAGO,
    STARWARSTITLE,
    STARTCREDITS,
    ENDCREDITS,
};

enum Priority {
    LOW_PRIORITY,
    HIGH_PRIORITY,
};

enum Side {
    REBELS,
    IMPERY,
};

static char picture11[4][3 + 1]{
    " ^ ",
    " H ",
    "=#=",
    "| |",
};


typedef struct TEST_SHIP {
public:
    static const int sizeX = 3;
    static const int sizeY = 4;
    const char hitBox[sizeY][sizeX + 1] = {
        {__hitbox_void,  __hitbox_solid, __hitbox_void,},
        {__hitbox_void,  __hitbox_solid, __hitbox_void,},
        {__hitbox_solid, __hitbox_solid, __hitbox_solid,},
        {__hitbox_solid, __hitbox_void,  __hitbox_solid,},
    };
    std::vector<int> a{1, 2, 3};
    const char picture[sizeY][sizeX + 1]{
        " ^ ",
        " H ",
        "=#=",
        "| |",
    };
    const int color[sizeY][sizeX + 1] = {
        {-1,               cc(gray, orange), -1},
        {-1,               cc(gray, orange), -1},
        {cc(gray, orange), cc(gray, orange), cc(gray, orange)},
        {cc(gray, orange), -1,               cc(gray, orange)},
    };
    static const int side = REBELS;
    static const int priority = HIGH_PRIORITY;

    ~TEST_SHIP() {
        std::cout << "TEST_SHIP struct End\n";
    }
} TestShipS;


typedef struct AbstractScene {
    int framesCount;
    char **startImage;
    int startImageX;
    int startImageY;
    std::vector<Frame> frames;
} AbstractScene;


namespace test_ship {
    static const int sizeX = 3;
    static const int sizeY = 4;
    const char hitBox[sizeY][sizeX + 1] = {
        {__hitbox_void,  __hitbox_solid, __hitbox_void,},
        {__hitbox_void,  __hitbox_solid, __hitbox_void,},
        {__hitbox_solid, __hitbox_solid, __hitbox_solid,},
        {__hitbox_solid, __hitbox_void,  __hitbox_solid,},
    };
    static char picture[sizeY][sizeX + 1]{
        " ^ ",
        " H ",
        "=#=",
        "| |",
    };
    static const int color[sizeY][sizeX + 1] = {
        {-1,               cc(gray, orange), -1},
        {-1,               cc(gray, orange), -1},
        {cc(gray, orange), cc(gray, orange), cc(gray, orange)},
        {cc(gray, orange), -1,               cc(gray, orange)},
    };
    static const int side = REBELS;
    static const int priority = HIGH_PRIORITY;
}

static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

static void setCursorPosition(int x, int y) {
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = {(SHORT) x, (SHORT) y};
    SetConsoleCursorPosition(hOut, coord);
}

static void setConsoleColour(unsigned short colour) {
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    SetConsoleTextAttribute(hOut, colour);
}


class StaticObject {
private:
    int sizeY;
    int sizeX;
    std::vector<std::string> hitbox;
    std::vector<std::string> picture;
    std::vector<std::vector<int>> colors;
    int side;
    int priority;
public:
    template<std::size_t U, std::size_t V>
    StaticObject(int sizeX1,
                 int sizeY1,
                 const char (&hitBox1)[U][V],
                 char (&picture1)[U][V],
//                const char(*picture1)[U][V]
                 const int (&colors1)[U][V],
                 int side1,
                 int priority1) {
        this->sizeX = sizeX1;
        this->sizeY = sizeY1;
        this->side = side1;
        this->priority = priority1;
        this->hitbox.resize(this->sizeY);
        for (int i = 0; i < this->sizeY; ++i) {
            this->hitbox[i] = std::string(hitBox1[i]);
        }
        this->picture.resize(this->sizeY);
        for (int i = 0; i < this->sizeY; ++i) {
            this->picture[i] = std::string(picture1[i]);
        }
        this->colors.resize(this->sizeY);
        for (int i = 0; i < this->sizeY; ++i) {
            for (int j = 0; j < this->sizeX; ++j) {
                this->colors[i].push_back(colors1[i][j]);
            }
        }
    }


    ~StaticObject() {
        std::cout << "StaticObject End" << '\n';
    }

    [[nodiscard]] int getSizeY() const {
        return sizeY;
    }

    void setSizeY(int sizeY1) {
        StaticObject::sizeY = sizeY1;
    }

    [[nodiscard]] int getSizeX() const {
        return sizeX;
    }

    void setSizeX(int sizeX1) {
        StaticObject::sizeX = sizeX1;
    }

    [[nodiscard]] const std::vector<std::string> &getHitbox() const {
        return hitbox;
    }

    void setHitbox(const std::vector<std::string> &hitbox1) {
        StaticObject::hitbox = hitbox1;
    }

    [[nodiscard]] const std::vector<std::string> &getPicture() const {
        return picture;
    }

    void setPicture(const std::vector<std::string> &picture1) {
        StaticObject::picture = picture1;
    }

    [[nodiscard]] int getSide() const {
        return side;
    }

    void setSide(int side1) {
        StaticObject::side = side1;
    }

    [[nodiscard]] int getPriority() const {
        return priority;
    }

    void setPriority(int priority1) {
        StaticObject::priority = priority1;
    }

    void setColors(const std::vector<std::vector<int>> &colors1) {
        StaticObject::colors = colors1;
    }

    [[nodiscard]] const std::vector<std::vector<int>> &getColors() const {
        return colors;
    }

};

class TestShip : public StaticObject {
private:
    TestShipS p;
public:
    TestShip() : StaticObject(TestShipS::sizeX,
                              TestShipS::sizeY,
                              test_ship::hitBox,
                              test_ship::picture,
                              test_ship::color,
                              TestShipS::side,
                              TestShipS::priority) {
        std::cout << *p.picture << '\n';
    }

    ~TestShip() {
        std::cout << "TestShip End" << std::endl;
    }

};


#endif //TP_LAB_7_COMMON_H
