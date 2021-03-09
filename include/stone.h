
#include "common.h"
#include "object.h"
#include "cell.h"
#include "ocean.h"

class Wall_W : public Object
{
private:
	size_t time;
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
};


class Wall_G : public Object
{
private:
	size_t time;
public:
	//Wall_G() {
	//	this->cell = nullptr;
	//	this->time = 1;
	//	this->objType = 5;
	//}

	//~Wall_G() {
	//	this->time = 0;
	//	this->cell = nullptr;
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
		std::cout << WALL_NG;
	}

	void setCell(Cell* c) {
		this->cell = c;
	}
};
