// Copyright 2021 soda

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "common.h"
#include "object.h"
#include "cell.h"
#include "ocean.h"


class Predator : public Object {
// fields: - (1) lifetime; (3) number of descendants available for reproduction.
 private:
    size_t time;
    size_t gender;
    size_t reprod_posib;
    size_t hunger;

 public:
    void set_time();
    void set_objType();
    void setGender();
    void setPosib();
    void setCell(Cell* c);
    void setHuger(size_t);
    void reproduction();
    void move();
    void hant();
    void die();
    void live();
    void print_object();
    size_t* get_posib();
    size_t getGender();
    size_t getHunger();
    void init(Cell* c);
    int get_objType();
    char get_info_object();
};

#endif // INCLUDE_PREDATOR_H_
