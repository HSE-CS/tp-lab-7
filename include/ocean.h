// Copyright 2020 PollyllyZh
#pragma once
#include "common.h"
#include "cell.h"
#include "prey.h"
#include "predator.h"
#include "stone.h"


class Ocean {
    friend Cell;
	
private:
    Cell** cells;
    std::list<Object*> stuff;
	
public:
    Ocean();
    ~Ocean();
    void print() const;
    void add_objects(ObjType obj_type, uint num);
    void add_stuff(Object* object);
    void del_obj(Object* object);
    void run();
    Cell* find_empty(Pair crd);
    Cell* find_prey(Pair crd);
};
