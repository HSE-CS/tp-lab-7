// Copyright 2021 by Sid

#ifndef Factory_h
#define Factory_h
#include "Ocean.h"
#include "Object.h"
#include "Cell.h"
#include "Coordinates.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"


#endif /* Factory_h */



class Factory {


public:
    static Object* createObject(ObjectTypes type, Cell* cell);
};
