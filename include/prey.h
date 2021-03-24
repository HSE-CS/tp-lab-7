// Copyright 2021 soda

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "common.h"
#include "object.h"
#include "cell.h"
#include "ocean.h"


class Prey : public Object
{
    //fields: - (1) lifetime; (3) number of descendants available for reproduction.
 private:
    size_t time;
    size_t gender;
    size_t reprod_posib;

 public:
    void set_time();
    void set_objType();
    void reproduction();
    void move();
    void die();
    void live();
    void print_object();
    void setCell(Cell* c);
    void setGender();
    void setPosib();
    size_t* get_posib();
    size_t getGender();
    void init(Cell* c);
    int get_objType();
    char get_info_object();
};

#endif // INCLUDE_PREY_H_
