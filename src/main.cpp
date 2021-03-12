#include "ocean.h"

int main() {
	Ocean demo;
	Stone my_first;
	Pair p;
	p.i = 7;
	p.j = 7;
	Cell* cell = demo.get_cell(p);
	my_first.init(cell);
	cell->setObject(&my_first);
	demo.addObject(&my_first);

	p.i = 8;
	p.j = 8;
	Cell* f_f = demo.get_cell(p);
	Prey my_fish;
	my_fish.init(f_f);
	f_f->setObject(&my_fish);
	demo.addObject(&my_fish);

	p.i = 7;
	p.j = 8;
	Cell* f_f1 = demo.get_cell(p);
	Prey my_fish2;
	my_fish2.init(f_f1);
	f_f1->setObject(&my_fish2);
	demo.addObject(&my_fish2);

	p.i = 8;
	p.j = 7;
	Cell* f_f2 = demo.get_cell(p);
	Prey my_fish3;
	my_fish3.init(f_f2);
	f_f2->setObject(&my_fish3);
	demo.addObject(&my_fish3);

	p.i = 1;
	p.j = 1;
	f_f2 = demo.get_cell(p);
	Prey my_fish4;
	my_fish4.init(f_f2);
	f_f2->setObject(&my_fish4);
	demo.addObject(&my_fish4);

	p.i = 1;
	p.j = 2;
	f_f2 = demo.get_cell(p);
	Prey my_fish5;
	my_fish5.init(f_f2);
	f_f2->setObject(&my_fish5);
	demo.addObject(&my_fish5);
	demo.run();
}