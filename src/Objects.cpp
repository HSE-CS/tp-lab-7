//
// Created by Данил on 04.03.2021.
//

#include "../include/Objects.h"
#include "../include/common.h"

static int id__ = -1;

Object::Object(const StaticObject &object) {
    this->sizeX = object.getSizeX();
    this->sizeY = object.getSizeY();
    this->hitbox = object.getHitbox();
    this->picture = object.getPicture();
    this->side = object.getSide();
    this->priority = object.getPriority();
    this->id = Object::getId();
    for (const auto& x : object.getColors()) {
        this->colors.push_back(x);
    }
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
