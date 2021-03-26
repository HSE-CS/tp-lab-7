// Copyright dmitrycvetkov 2021
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "common.h"

#include <memory>

class Cell;
class Object : public std::enable_shared_from_this<Object> {
 public:
    explicit Object(std::weak_ptr<Cell> cell);
    virtual void live() = 0;
    void moveToCell(const std::weak_ptr<Cell> &cell);

    virtual ObjType type() const = 0;

    void markAsRemoved() {
        removed = true;
    }

    bool isRemoved() const {
        return removed;
    }

 protected:
    std::weak_ptr<Cell> cell;
    bool removed = false;
};
#endif  // INCLUDE_OBJECT_H_
