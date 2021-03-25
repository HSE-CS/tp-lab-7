// Copyright 2021 MalininDmitry

#ifndef _PREY_H_
#define _PREY_H_

#include "object.h"
#include "cell.h"
#include "common.h"

class Prey : public Object {
 protected:
    ObjType type;
    int live_count = 0;
    int time_reproduction = 0;
    int curr_time = 0;
 public:
    explicit Prey(int live_count, int time_reproduction, Cell * cell, ObjType type);
    ~Prey() override;
    void live() override;
    void go();

};

#endif
