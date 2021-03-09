
#include "common.h"
#include "ocean.h"


Ocean::Ocean() {

	this->cells = new Cell * [N];
	for (int i = 0; i < N; i++) {
		cells[i] = new Cell[M];
		for (int j = 0; j < M; j++) {
			Pair now_cord;
			now_cord.x = j;
			now_cord.y = i;
			cells[i][j].init(now_cord, this);
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
};

void addObjects();
void run();