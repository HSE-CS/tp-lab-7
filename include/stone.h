// Copyright 2021 soda

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/common.h"
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"

// Vertical wall class, for the ocean border
class Wall_W : public Object {
 private:
    size_t time = 0;

 public:
    void set_time() {
        this->time = 1;
    }

    void set_objType() {
        this->objType = 5;
    }

    void live() {
        time++;
        if (time == 100000)
            time = 1;
    }

    void print_object() {
        std::cout << WALL_NW;
    }

    void setCell(Cell* c) {
        this->cell = c;
    }

    int get_objType() {
        return objType;
    }

    char get_info_object() {
        return WALL_NW;
    }
};


// Horizontal wall class, for the ocean border
class Wall_G : public Object {
 private:
    size_t time = 0;

 public:
    void set_time() {
        this->time = 1;
    }

    void set_objType() {
        this->objType = 4;
    }

    void live() {
        time++;
        if (time == 100000)
            time = 1;
    }

    void print_object() {
        std::cout << WALL_NG;
    }

    void setCell(Cell* c) {
        this->cell = c;
    }

    int get_objType() {
        return objType;
    }

    char get_info_object() {
        return WALL_NG;
    }
};


class Stone : public Object {
 private:
    size_t time;

 public:
    void set_time();
    void set_objType();
    void live();
    void die();
    void print_object();
    void setCell(Cell* c);
    void init(Cell* c);
    int get_objType();
    char get_info_object();
};


class Coral : public Object {
 private:
    size_t time;
    size_t reprod_posib;

 public:
    void set_time();
    void set_objType();
    void setReprod();
    void live();
    void reproduction();
    void die();
    void print_object();
    void setCell(Cell* c);
    void init(Cell* c);
    size_t* getReprod();
    int get_objType();
    char get_info_object();
};

#endif  // INCLUDE_STONE_H_
