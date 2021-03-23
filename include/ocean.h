// Copyright <Roman Balayan> @ 2021

#pragma once

#include <list>
#include <vector>
#include <iostream>
#include <memory>

class Object;
class Cell;

class Ocean : public std::enable_shared_from_this<Ocean> {
 public:
    Ocean();
    void print() const;
    void addObjects();
    void addObject(std::shared_ptr<Object> obj);
    void removeObject(std::shared_ptr<Object> obj);
    void resetObject(std::shared_ptr<Object> target,
                     std::shared_ptr<Object> newObj);
    void run();
    std::shared_ptr<Cell> getEmptyCell();
    std::shared_ptr<Cell> getEmptyCellAround(std::shared_ptr<Cell> target);
    std::shared_ptr<Cell> getCell(int x, int y);
 private:
    std::vector<std::vector<std::shared_ptr<Cell> > > cells;
    std::list<std::shared_ptr<Object> > stuff;
};
