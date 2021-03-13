

#ifndef _STONE_H_
#define _STONE_H_

#include "common.h"
#include "object.h"
#include "cell.h"
#include "ocean.h"

class Wall_W : public Object
{
private:
    size_t time = 0;
public:
    //Wall_W() {
    // cell = nullptr;
    // time = 1;
    // objType = 4;
    //}

     //~Wall_W() {
     // this->time = 0;
     // this->cell = nullptr;
     //}

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
    } // жизнь объекта

    void print_object() {
        std::cout << WALL_NW;
    }

    void setCell(Cell* c) {
        this->cell = c;
    }

    int get_objType() {
        return objType;
    }
};


class Wall_G : public Object
{
private:
    size_t time = 0;
public:
    //Wall_G() {
    //	this->cell = nullptr;
    //	this->time = 1;
    //   this->objType = 5;
    //}

    //~Wall_G() {
    //	this->time = 0;
    //	this->cell = nullptr;
    //}
    void set_time() {
        this->time = 1;
    }

    void set_objType() {
        this->objType = 4;
    }

    // жизнь объекта
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
};

class Stone : public Object
{
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
};

class Coral : public Object
{
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
};


#endif