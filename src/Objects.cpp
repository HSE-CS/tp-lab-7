//
// Created by Данил on 04.03.2021.
//

#include "../include/Objects.h"
#include "../include/common.h"

static int id__ = -1;

Object::Object(const StaticObject &object, int speed1) {
    this->sizeX = object.getSizeX();
    this->sizeY = object.getSizeY();
    this->hitbox = object.getHitbox();
    this->picture = object.getPicture();
    this->side = object.getSide();
    this->priority = object.getPriority();
    this->id = Object::getId();
    for (const auto &x : object.getColors()) {
        this->colors.push_back(x);
    }
    this->posX = 0;
    this->posY = 0;
    this->speed = speed1;
    this->direction = UP;
}


const std::vector<std::vector<int>> &Object::getColors() const {
    return colors;
}

void Object::setColors(const std::vector<std::vector<int>> &colors1) {
    for (std::size_t i = 0; i < colors.size(); ++i) {
        this->colors[i] = colors1[i];
    }
}

int Object::getId() {
    ++id__;
    return id__;
}

int Object::getSizeY() const {
    return sizeY;
}

void Object::setSizeY(int sizeY1) {
    Object::sizeY = sizeY1;
}

int Object::getSizeX() const {
    return sizeX;
}

void Object::setSizeX(int sizeX1) {
    Object::sizeX = sizeX1;
}

const std::vector<std::string> &Object::getHitbox() const {
    return hitbox;
}

void Object::setHitbox(const std::vector<std::string> &hitbox1) {
    Object::hitbox = hitbox1;
}

const std::vector<std::string> &Object::getPicture() const {
    return picture;
}

void Object::setPicture(const std::vector<std::string> &picture1) {
    Object::picture = picture1;
}

int Object::getSide() const {
    return side;
}

void Object::setSide(int side1) {
    Object::side = side1;
}

int Object::getPriority() const {
    return priority;
}

void Object::setPriority(int priority1) {
    Object::priority = priority1;
}

void Object::setId(int id1) {
    Object::id = id1;
}

const std::string &Object::getPilotName() const {
    return pilotName;
}

void Object::setPilotName(const std::string &pilotName1) {
    Object::pilotName = pilotName1;
}

int Object::getSpeed() {
    return this->speed;
}

void Object::setDirection(int direction1) {
    this->direction = direction1;
}

int Object::getDirection() {
    return this->direction;
}

int Object::getPosX() {
    return this->posX;
}

void Object::setPosy(int y) {
    this->posY = y;
}

int Object::getPosY() {
    return this->posY;
}

void Object::setPosX(int x) {
    this->posX = x;
}

void Object::render(int x, int y) {
    for (int i = 0; i < this->sizeY; ++i) {
        for (int j = 0; j < this->sizeX; ++j) {
            setCursorPosition((x + j) % displayWidth, (y + i) % displayHeight);
            setConsoleColour(this->colors[i][j]);
            if (this->colors[i][j] != -1)
                std::cout << this->picture[i][j];
            else {
                setConsoleColour(displayColor[(y + i) % displayHeight][(x + j) % displayWidth]);
                std::cout << display[(y + i) % displayHeight][(x + j) % displayWidth];
            }
        }
    }
}

void Object::turn(int side1) {
    if (side1 > 0) {
        this->direction = (direction + 1) % 4;
    } else {
        this->direction = (direction + 3) % 4;
    }
}

//void Object::move(int iteration) {
//    if (this->speed == HIGH_SPEED) {
//        relativeMove();
//    }
//    if (this->speed == MEDIUM_SPEED) {
//        if (iteration % 2 == 0) {
//            relativeMove();
//        }
//    }
//    if (this->speed == LOW_SPEED) {
//        if (iteration % 3 == 0) {
//            relativeMove();
//        }
//    }
//}
//
//void Object::relativeMove() {
//    switch (this->direction) {
//        case UP:
//            moveUp();
//            break;
//        case DOWN:
//            moveDown();
//            break;
//        case LEFT:
//            moveLeft();
//            break;
//        case RIGHT:
//            moveRight();
//            break;
//    }
//}
