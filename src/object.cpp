// Copyright <Roman Balayan> @ 2021

#include "object.h"
#include "cell.h"
#include "common.h"

Object::Object(std::weak_ptr<Cell> cell) : cell(cell)
                                         , type(ObjType::EMPTY){
}

void Object::live() {
}

void Object::setCell(std::weak_ptr<Cell> newCell) {
    this->cell = newCell;
}

ObjType Object::getType() {
    return this->type;
}

bool Object::moveTo(std::shared_ptr<Cell>& dest) {
    if (dest->isEmpty() || dest->getObjType() == ObjType::EMPTY) {
        this->cell.lock()->setObject(dest->getObject());
        dest->setObject(shared_from_this());
        this->setCell(dest);
        return true;
    }
    return false;
}
