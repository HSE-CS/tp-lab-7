// Copyright dmitrycvetkov 2021
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include <memory>
#include <vector>

class Cell;
class Object;
struct Pair;

class Ocean {
 public:
    Ocean();

    void print() const;
    void addObjects(std::size_t count);
    void addObject(const std::shared_ptr<Object> &object);
    void run(std::size_t cycleCount);

    std::vector<std::weak_ptr<Cell>> getAdjacent(Pair coords) const;

    void removeObject(std::weak_ptr<Object> object);

 private:
    std::vector<std::vector<std::shared_ptr<Cell>>> cells;
    std::vector<std::shared_ptr<Object>> stuff;
};

#endif  // INCLUDE_OCEAN_H
