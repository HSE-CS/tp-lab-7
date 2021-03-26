// Copyright dmitrycvetkov 2021
#include "object.h"

#include "cell.h"

Object::Object(std::weak_ptr<Cell> cell) : cell { cell } {
}

void Object::moveToCell(const std::weak_ptr<Cell>& cell) {
    this->cell.lock()->setObject({});
    this->cell = cell;
    this->cell.lock()->setObject(weak_from_this());
}
