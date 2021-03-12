
#include "common.h"
#include "ocean.h"
#include "Windows.h"

Ocean::Ocean() {
	this->time = 1;
	this->cells = new Cell * [N];
	for (int i = 0; i < N; i++) {
		cells[i] = new Cell[M];
		for (int j = 0; j < M; j++) {
			Pair* now_cord = new Pair;
			now_cord->i = i;
			now_cord->j = j;
			cells[i][j].init(*now_cord, this);
			if (i == 0 || i == N - 1) {
				Wall_G* wall_g = new Wall_G;
				wall_g->setCell(&cells[i][j]);
				wall_g->set_time();
				wall_g->set_objType();
				cells[i][j].setObject(wall_g);
				objects.push_back(wall_g);
			}
			if ((j == 0 || j == M - 1) && i != 0 && i != N - 1) {
				Wall_W* wall_w = new Wall_W;
				wall_w->setCell(&cells[i][j]);
				wall_w->set_time();
				wall_w->set_objType();
				cells[i][j].setObject(wall_w);
				objects.push_back(wall_w);
			}
		}
	}


}

Ocean::~Ocean() {
	for (int i = 0; i < N; i++) {
		delete[] cells[i];
	}
	delete[] cells;
}

void Ocean::print() const {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cells[i][j].getObject() == nullptr)
				std::cout << ' ';
			else
				cells[i][j].getObject()->print_object();
		}
		std::cout << std::endl;
	}
	std::cout << this->time << std::endl;

	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
};

void Ocean::delObj(const Object* obj) {
	this->objects.erase(std::remove(this->objects.begin(),
		this->objects.end(), obj), this->objects.end());
	size_t size = this->objects.size();
	this->objects.resize(size - 1);
}

Cell* Ocean::get_cell(Pair p) {
	int i = p.i;
	int j = p.j;
	return &this->cells[p.i][p.j];
}

void Ocean::addObject(Object* obj) {
	this->objects.push_back(obj);
}

void addObjects();

void Ocean::run() {
	while (true) {
		int k = 0;
		if (time == 34) {
			//std::cout << "Help";
		}
		this->objects.erase(std::remove_if(objects.begin(), objects.end(), [](auto* x) {
			x->live();
			if (x->get_objType() == -1)
			{
				x->~Object();
				return true;
			}
			return false;
			}), objects.end());

		this->print();
		this->time++;
		Sleep(100);
	}
}