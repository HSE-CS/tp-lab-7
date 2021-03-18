
#include "common.h"
#include "ocean.h"
#include "Windows.h"
#include <vector>


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
	std::string buf = "";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cells[i][j].getObject() == nullptr)
				buf += ' ';
			else
				buf += cells[i][j].getObject()->get_info_object();
		}
		buf += '\n';
	}
	std::cout << buf;
	std::cout << this->time << std::endl;
	//std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
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
		srand(std::time(0));
		size_t size = this->objects.size();
		for (size_t index = 0; index < size / 10; index++) {
			int ind_f = rand() % size;
			int ind_s = rand() % size;
			if (ind_f == ind_s) {
				while (ind_f == ind_s)
					ind_s = rand() % size;
			}
			swapObj(ind_f + 1, ind_s + 1, this->objects);
		}


		this->objects.erase(std::remove_if(objects.begin(), objects.end(), [](auto* x) {
			if (x->get_objType() == -1)
			{
				x->~Object();
				return true;
			}
			x->live();
			return false;
			}), objects.end());

		this->print();
		this->time++;
		Sleep(100);
	}
}

void Ocean::Create_WORLD() {
	int N_1 = N;
	int M_1 = M;
	int area = (N_1 - 1) * (M_1 - 1);
	srand(std::time(0));
	int num_stone = rand() % (((area) / 100) * 3);
	//int num_stone = ((area) / 100) * 3;
	for (int index = 0; index < num_stone; index++) {
		Stone* n_stone = new Stone;
		Pair p;
		p.i = 0;
		p.j = 0;
		while (this->get_cell(p)->getObject() != nullptr) {
			p.i = (rand() % (N - 2)) + 1;
			p.j = (rand() % (M - 2)) + 1;
		}
		Cell* cell = this->get_cell(p);
		n_stone->init(cell);
		cell->setObject(n_stone);
		this->addObject(n_stone);
	}

	int num_coral = rand() % (((area) / 100) * 1);
	//int num_coral = ((area) / 100) * 1;
	for (int index = 0; index < num_coral; index++) {
		Coral* n_coral = new Coral;
		Pair p;
		p.i = 0;
		p.j = 0;
		while (this->get_cell(p)->getObject() != nullptr) {
			p.i = (rand() % (N - 2)) + 1;
			p.j = (rand() % (M - 2)) + 1;
		}
		Cell* cell = this->get_cell(p);
		n_coral->init(cell);
		cell->setObject(n_coral);
		this->addObject(n_coral);
	}

	int num_fish = rand() % (((area) / 100) * 35);
	//int num_fish = ((area) / 100) * 35;
	for (int index = 0; index < num_fish; index++) {
		Prey* n_fish = new Prey;
		Pair p;
		p.i = 0;
		p.j = 0;
		while (this->get_cell(p)->getObject() != nullptr) {
			p.i = (rand() % (N - 2)) + 1;
			p.j = (rand() % (M - 2)) + 1;
		}
		Cell* cell = this->get_cell(p);
		n_fish->init(cell);
		cell->setObject(n_fish);
		this->addObject(n_fish);
	}

	int num_pred = rand() % (((area) / 100) * 5);
	//int num_pred = ((area) / 100) * 5;
	for (int index = 0; index < num_pred; index++) {
		Predator* n_pred = new Predator;
		Pair p;
		p.i = 0;
		p.j = 0;
		while (this->get_cell(p)->getObject() != nullptr) {
			p.i = (rand() % (N - 2)) + 1;
			p.j = (rand() % (M - 2)) + 1;
		}
		Cell* cell = this->get_cell(p);
		n_pred->init(cell);
		cell->setObject(n_pred);
		this->addObject(n_pred);
	}
}

void swapObj(int fist, int second, std::list<Object*>& objects) {
	std::list<Object*>::iterator it1 = objects.begin();
	std::list<Object*>::iterator it2 = it1;
	int x1 = fist;
	int x2 = second;
	for (auto i = 0; i < x1 - 1; i++) it1++; //Смещаем итераторы на нужные позиции
	for (auto i = 0; i < x2 - 1; i++) it2++;
	std::swap(*it1, *it2);  //меняем
}
