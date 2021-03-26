// Copyright dmitrycvetkov 2021
#include "cell.h"
#include "ocean.h"

#include <vector>

Cell::Cell(Pair p, Ocean* oc) : crd(p), obj({}), ocean(oc) {
}

void Cell::init(Pair p, Ocean* oc) {
}

std::shared_ptr<Object> Cell::getObject() const {
    return obj.lock();
}

void Cell::setObject(std::weak_ptr<Object> object) {
    obj = object;
}

void Cell::killMe() {
    ocean->removeObject(obj);
    setObject({});
}

std::vector<std::weak_ptr<Cell>> Cell::getAdjacent() const {
    return ocean->getAdjacent(crd);
}

void Cell::initChild(const std::shared_ptr<Object> &child) {
    obj = child;
    ocean->addObject(child);
}
