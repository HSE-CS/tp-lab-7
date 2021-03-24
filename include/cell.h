#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "object.h"
#include <utility>

class Ocean;

class Cell {
    friend Ocean;
private:
    std::pair<size_t, size_t> crd;
    Object *obj;
    Ocean *ocean;
public:
    explicit Cell(std::pair<size_t, size_t> p = {0, 0}, Ocean *oc = nullptr) :
            crd(p),
            obj(nullptr),
            ocean(oc) {}

    void init(std::pair<size_t, size_t> p, Ocean *oc);

    Object *getObject() const;

    void setObject(Object *);

    void killMe();

    int getX() const;

    int getY() const;

    Ocean* getOcean() const;

    friend std::ostream &operator<<(std::ostream &out, const Cell &cell);

};

#endif
