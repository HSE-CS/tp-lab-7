//
// Created by Данил on 04.03.2021.
//

#ifndef TP_LAB_7_OBJECTS_H
#define TP_LAB_7_OBJECTS_H

#include "Space.h"
#include "scenes.h"

enum Speed {
    ZERO_SPEED,
    ULTRA_LOW,
    LOW_SPEED,
    MEDIUM_SPEED,
    HIGH_SPEED,
    SUPER,
};

enum Direction {
    LEFT = 0,
    UP = 1,
    RIGHT = 2,
    DOWN = 3,
    NONE,
};

class Object {
private:
    int sizeY;
    int sizeX;
    std::vector<std::string> hitbox;
    std::vector<std::string> picture;
    std::vector<std::vector<int>> colors;
    int side;
    int priority;
    int id;
    std::string pilotName;
    int posX, posY;
    int speed, direction;
    int energy = 1000;

public:
    bool destroyed = false;

    explicit Object(const StaticObject &object, int speed);

    void render(int x, int y);

    void turn(int side);

    // Getters & setters:

    static int getId();

    int getSizeY() const;

    void setEnergy(int energy);

    int getEnergy();

    void setSizeY(int sizeY);

    int getSizeX() const;

    void setSizeX(int sizeX);

    const std::vector<std::string> &getHitbox() const;

    void setHitbox(const std::vector<std::string> &hitbox);

    const std::vector<std::string> &getPicture() const;

    void setPicture(const std::vector<std::string> &picture);

    int getSide() const;

    void setSide(int side);

    int getPriority() const;

    void setPriority(int priority);

    void setId(int id);

    const std::string &getPilotName() const;

    void setPilotName(const std::string &pilotName);

    const std::vector<std::vector<int>> &getColors() const;

    void setColors(const std::vector<std::vector<int>> &colors);

    int getSpeed();

    int getDirection();

    void setDirection(int direction);

    int getPosX();

    void setPosX(int x);

    int getPosY();

    void setPosy(int y);
};

#endif //TP_LAB_7_OBJECTS_H
