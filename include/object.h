//  Copyright <Roman Balayan> @ 2021

#pragma once

#include <memory>

class Cell;
enum class ObjType;

class Object : public std::enable_shared_from_this<Object> {
 public:
    explicit Object(std::weak_ptr<Cell> = std::weak_ptr<Cell>());
    virtual void live();  //  жизнь объекта, is not pure virtual coz of EMPTY obj
    void setCell(std::weak_ptr<Cell>);
    ObjType getType();
    bool moveTo(std::shared_ptr<Cell>& dest);
 protected:
    std::weak_ptr<Cell> cell;
    ObjType type;
};
