// Copyright dmitrycvetkov 2021
#include "object.h"

#include "cell.h"

#include <cassert>

Object::Object(std::weak_ptr<Cell> cell) : cell { cell } {
}

void Object::moveToCell(const std::weak_ptr<Cell>& cell) {
    assert(this->cell.lock()->getObject());
    this->cell.lock()->setObject({});
    this->cell = cell;
    this->cell.lock()->setObject(weak_from_this());
}
