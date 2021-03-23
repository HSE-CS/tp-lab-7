  //  Copyright <Roman Balayan> @ 2021

#pragma once

#include <utility>
#include <memory>

using Pair = std::pair<int, int>;

class Ocean;
enum class ObjType;
class Object;

class Cell : public std::enable_shared_from_this<Cell> {
    friend Ocean;
 public:
    explicit Cell(Pair coords = { 0, 0 },
                  std::shared_ptr<Ocean> oceanPtr = nullptr);
    void init(Pair coords, std::shared_ptr<Ocean> oceanPtr);
    void set_ocean(std::shared_ptr<Ocean> oceanPtr = nullptr);
    std::shared_ptr<Object> getObject() const;
    void setObject(std::shared_ptr<Object> newObjectPtr);
    void killMe();
    bool isEmpty();
    std::shared_ptr<Cell> getNeighbour();
    ObjType getObjType();
    std::shared_ptr<Ocean> getOcean();
 private:
    Pair coords;
    std::shared_ptr<Object> obj;
    std::shared_ptr<Ocean> ocean;
};
