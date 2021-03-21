#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"
#include "object.h"

class Ocean;

class Cell {
    friend Ocean;
    friend Object;
private:
    Object *object;
    Ocean *ocean;

public:
    std::pair<int, int> crd;
    explicit Cell(std::pair<int, int> p,
                  Ocean *oc);
    Object *getObject() const;
    void setObject(Object *obj);
    Ocean *getOcean();
    bool hasObject() { return this->object != nullptr; } ;
};

#endif // _OBJECT_H_