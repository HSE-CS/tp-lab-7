//
// Created by Данил on 04.03.2021.
//

#ifndef TP_LAB_7_OBJECTS_H
#define TP_LAB_7_OBJECTS_H

#include "Space.h"
#include "scenes.h"


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
public:
    explicit Object(const StaticObject &object);

    static int getId();

    int getSizeY() const;

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
};

#endif //TP_LAB_7_OBJECTS_H
