#include "..\include\ocean.h"

Ocean::Ocean(size_t preyLife_, size_t preyCoolDawn_, size_t predatorLife_,
             size_t predatorCoolDawn_, size_t predatorHunger_) {
  cells = new Cell*[N];
  for (size_t i = 0; i < N; ++i) {
    cells[i] = new Cell [M];
    for (size_t j = 0; j < M; ++j) {
      cells[i][j].init(Pair{i, j}, this);
    }
  }
  preyLife = preyLife_;
  preyCoolDawn = preyCoolDawn_;
  predatorLife = predatorLife_;
  predatorCoolDawn = predatorCoolDawn_;
  predatorHunger = predatorHunger_;
}

Ocean::~Ocean() {
  for (size_t i = 0; i < N; ++i) {
    delete[] cells[i];
  }
  delete [] cells;
}

void Ocean::print() const {
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < M; ++j) {
      cells[i][j].print();
    }
    std::cout << "\n";
  }
}



void Ocean::addObjects(size_t number, ObjType type) {
  std::srand(0);
  for (size_t i = 0; i < number; ++i) {
    size_t x_coord = std::rand() % N;
    size_t y_coord = std::rand() % M;
    while (cells[x_coord][y_coord].getObject()) {
      x_coord = std::rand() % N;
      y_coord = std::rand() % M;
    }
    Object *obj = nullptr;
    switch (type) {
      case ObjType::EMPTY:
        break;
      case ObjType::STONE:
        obj = new Stone (&cells[x_coord][y_coord]);
        break;
      case ObjType::CORAL:
        break;
      case ObjType::PREY:
        obj = new Prey(&cells[x_coord][y_coord], preyLife,
                       preyCoolDawn);
        break;
      case ObjType::PREDATOR:
        obj = new Predator(&cells[x_coord][y_coord], predatorLife,
                           predatorCoolDawn, predatorHunger);
        break;
      default:
        break;
    }
    cells[x_coord][y_coord].setObject(obj);
    stuff.push_back(obj);
  }
}

void Ocean::removeObj(Object *obj) {
  for (size_t i = 0; i < stuff.size(); ++i) {
    if (stuff[i] == obj) {
      stuff.erase(stuff.begin() + i);
      break;
    }
  }
}

void Ocean::pushObject(Object *obj) { stuff.push_back(obj); }

void Ocean::run() {
  size_t counter = 0;
  size_t shift = 0;
  while (check()) {
    system("cls");
    std::cout << counter << "\n";
    ++counter;
    for (size_t i = 0; i < stuff.size(); ++i) {
      stuff[(i + shift) % stuff.size()]->live();
    }
    ++shift;
    print();
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
  }
}

bool Ocean::check() {
  size_t preyCount(0), predatorCount(0);
  for (auto obj : stuff) {
    if (obj->getType() == ObjType::PREY) {
      ++preyCount;
    } else {
      if (obj->getType() == ObjType::PREDATOR) {
        ++predatorCount;
      }
    }
  }
  /*std::cout << "Predators: " << predatorCount;
  std::cout << "\nPreys: " << preyCount << "\n";*/
  if (predatorCount * preyCount == 0) return false;
  return true;
}

std::vector<Cell*> Ocean::emptyCells(Pair point) {
  std::vector<Cell*> empList;
  if (point.x == 0) {
    if (point.y == 0) {
      if (!cells[N - 1][M - 1].getObject())
        empList.push_back(&cells[N - 1][M - 1]);
      if (!cells[point.x][M - 1].getObject())
        empList.push_back(&cells[point.x][M - 1]);
      if (!cells[(point.x + 1) % N][M - 1].getObject())
        empList.push_back(&cells[(point.x + 1) % N][M - 1]);
    } else {
      if (!cells[N - 1][(point.y - 1) % M].getObject())
        empList.push_back(&cells[N - 1][(point.y - 1) % M]);
      if (!cells[point.x][(point.y - 1) % M].getObject())
        empList.push_back(&cells[point.x][(point.y - 1) % M]);
      if (!cells[(point.x + 1) % N][(point.y - 1) % M].getObject())
        empList.push_back(&cells[(point.x + 1) % N][(point.y - 1) % M]);
    }
    if (!cells[N - 1][point.y].getObject())
      empList.push_back(&cells[N - 1][point.y]);
    if (!cells[N - 1][(point.y + 1) % M].getObject())
      empList.push_back(&cells[N - 1][(point.y + 1) % M]);
  } else {
    if (point.y == 0) {
      if (!cells[(point.x-1) % N][M - 1].getObject())
        empList.push_back(&cells[(point.x - 1) % N][M - 1]);
      if (!cells[(point.x) % N][M - 1].getObject())
        empList.push_back(&cells[point.x][M - 1]);
      if (!cells[(point.x + 1) % N][M - 1].getObject())
        empList.push_back(&cells[(point.x + 1) % N][M - 1]);
    } else {
      if (!cells[(point.x - 1) % N][(point.y - 1) % M]
               .getObject())
        empList.push_back(&cells[(point.x - 1) % N][(point.y - 1) % M]);
      if (!cells[point.x][(point.y - 1) % M].getObject())
        empList.push_back(&cells[point.x][(point.y - 1) % M]);
      if (!cells[(point.x + 1) % N][(point.y - 1) % M].getObject())
        empList.push_back(&cells[(point.x + 1) % N][(point.y - 1) % M]);
    }
    if (!cells[(point.x - 1) % N][point.y].getObject())
      empList.push_back(&cells[(point.x - 1) % N][point.y]);
    if (!cells[(point.x - 1) % N][(point.y + 1) % M].getObject())
      empList.push_back(&cells[(point.x - 1) % N][(point.y + 1) % M]);
  }
  if (!cells[(point.x) % N][(point.y + 1) % M].getObject())
    empList.push_back(&cells[(point.x) % N][(point.y + 1) % M]);
  if (!cells[(point.x + 1) % N][(point.y) % M].getObject())
    empList.push_back(&cells[(point.x + 1) % N][(point.y) % M]);
  if (!cells[(point.x + 1) % N][(point.y + 1) % M].getObject())
    empList.push_back(&cells[(point.x + 1) % N][(point.y + 1) % M]);
  return empList;
}


std::vector<Cell *> Ocean::preyCells(Pair point) {
  std::vector<Cell *> empList;
  if (point.x == 0) {
    if (point.y == 0) {
      if (cells[N - 1][M - 1].getObject()->getType() == ObjType::PREY)
        empList.push_back(&cells[N - 1][M - 1]);
      if (cells[point.x][M - 1].getObject()->getType() == ObjType::PREY)
        empList.push_back(&cells[point.x][M - 1]);
      if (cells[(point.x + 1) % N][M - 1].getObject()->getType() ==
          ObjType::PREY)
        empList.push_back(&cells[(point.x + 1) % N][M - 1]);
    } else {
      if (cells[N - 1][(point.y - 1) % M].getObject()->getType() ==
          ObjType::PREY)
        empList.push_back(&cells[N - 1][(point.y - 1) % M]);
      if (cells[point.x][(point.y - 1) % M].getObject()->getType() ==
          ObjType::PREY)
        empList.push_back(&cells[point.x][(point.y - 1) % M]);
      if (cells[(point.x + 1) % N][(point.y - 1) % M].getObject()->getType() ==
          ObjType::PREY)
        empList.push_back(&cells[(point.x + 1) % N][(point.y - 1) % M]);
    }
    if (cells[N - 1][point.y].getObject()->getType() == ObjType::PREY)
      empList.push_back(&cells[N - 1][point.y]);
    if (cells[N - 1][(point.y + 1) % M].getObject()->getType() == ObjType::PREY)
      empList.push_back(&cells[N - 1][(point.y + 1) % M]);
  } else {
    if (point.y == 0) {
      if (cells[(point.x - 1) % N][M - 1].getObject()->getType() ==
          ObjType::PREY)
        empList.push_back(&cells[(point.x - 1) % N][M - 1]);
      if (cells[(point.x) % N][M - 1].getObject()->getType() == ObjType::PREY)
        empList.push_back(&cells[point.x][M - 1]);
      if (cells[(point.x + 1) % N][M - 1].getObject()->getType() ==
          ObjType::PREY)
        empList.push_back(&cells[(point.x + 1) % N][M - 1]);
    } else {
      if (cells[(point.x - 1) % N][(point.y - 1) % M].getObject()->getType() ==
          ObjType::PREY)
        empList.push_back(&cells[(point.x - 1) % N][(point.y - 1) % M]);
      if (cells[point.x][(point.y - 1) % M].getObject()->getType() ==
          ObjType::PREY)
        empList.push_back(&cells[point.x][(point.y - 1) % M]);
      if (cells[(point.x + 1) % N][(point.y - 1) % M].getObject()->getType() ==
          ObjType::PREY)
        empList.push_back(&cells[(point.x + 1) % N][(point.y - 1) % M]);
    }
    if (cells[(point.x - 1) % N][point.y].getObject()->getType() ==
        ObjType::PREY)
      empList.push_back(&cells[(point.x - 1) % N][point.y]);
    if (cells[(point.x - 1) % N][(point.y + 1) % M].getObject()->getType() ==
        ObjType::PREY)
      empList.push_back(&cells[(point.x - 1) % N][(point.y + 1) % M]);
  }
  if (cells[(point.x) % N][(point.y + 1) % M].getObject()->getType() ==
      ObjType::PREY)
    empList.push_back(&cells[(point.x) % N][(point.y + 1) % M]);
  if (cells[(point.x + 1) % N][(point.y) % M].getObject()->getType() ==
      ObjType::PREY)
    empList.push_back(&cells[(point.x + 1) % N][(point.y) % M]);
  if (cells[(point.x + 1) % N][(point.y + 1) % M].getObject()->getType() ==
      ObjType::PREY)
    empList.push_back(&cells[(point.x + 1) % N][(point.y + 1) % M]);
  return empList;
}
