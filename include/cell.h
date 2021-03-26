// Copyright dmitrycvetkov 2021
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "common.h"
#include "object.h"

#include <vector>
#include <memory>

class Ocean;

class Cell {
    friend Ocean;
 public:
    Cell(Pair p, Ocean* oc);
    void init(Pair p, Ocean* oc);
    std::shared_ptr<Object> getObject() const;
    void setObject(std::weak_ptr<Object>);
    void killMe();

    std::vector<std::weak_ptr<Cell>> getAdjacent() const;

    void initChild(const std::shared_ptr<Object> &child);

 private:
    Pair crd;
    std::weak_ptr<Object> obj;
    Ocean* ocean;
};
#endif  // INCLUDE_CELL_H_
