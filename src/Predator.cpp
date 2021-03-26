//  Copyright 2021 GHA created by Klykov Anton

#include "Predator.h"
#include "Ocean.h"
Predator::Predator(std::string name, std::string pre_name,
                   int eat, int life, int reproduce, Cell* cell)
                  : Prey(pre_name, life, reproduce, cell) {
  eatTime = eat;
  p_name = name;
}
std::string Predator::getName() {
  return p_name;
}
Predator::~Predator() {
  eatTime = -1;
  p_name = "";
}
void Predator::live() {
  std::vector<std::vector<Cell* >> TemporaryCells =
      obj_cell->getOcean()->GetCells();
  Ocean* temp_ocean = obj_cell->getOcean();
  std::vector<Object* > TemporaryCreatures =
      obj_cell->getOcean()->GetCreatures();
  int x = obj_cell->getPair()->x;  // Координаты расположения хищника
  int y = obj_cell->getPair()->y;  // Координаты расположения хищника
  bool SamePlace;
  bool isPrey{false};
  static int reproduce{0};
  static int life{0};
  static int eat{0};
  // Смерть хищника
  if (life == lifeTime) {
    reproduce = 0;
    life = 0;
    eat = 0;
    TemporaryCells[x][y]->delObject();
    TemporaryCreatures.erase(std::remove(TemporaryCreatures.begin(),
                                         TemporaryCreatures.end(), this),
                             TemporaryCreatures.end());
    delete this;
    temp_ocean->SetOceanCells(TemporaryCells);
    temp_ocean->SetMarineCreatures(TemporaryCreatures);
    temp_ocean = nullptr;
    return;
  }
  // Рождение новых хищников
  if (reproduce == reproduceTime && DoEat) {
    reproduce = 0;
    eat = 0;
    if (y + 1 != M && TemporaryCells[x][y + 1]->getObject() == nullptr) {
      Object* children_Predator = new Predator
          ("Predator", "Prey",
                                               eatTime, lifeTime, reproduceTime,
                                               TemporaryCells[x][y + 1]);
      TemporaryCells[x][y + 1]->SetObject(children_Predator);
      TemporaryCreatures.push_back(children_Predator);
    } else if (y + 1 == M) {
      if (TemporaryCells[x][0]->getObject() == nullptr) {
        Object* children_Predator = new Predator
            ("Predator", "Prey",
                                                 eatTime,  lifeTime,
                                                 reproduceTime,
                                                 TemporaryCells[x][0]);
        TemporaryCells[x][0]->SetObject(children_Predator);
        TemporaryCreatures.push_back(children_Predator);
      }
    } else if (y - 1 != -1 && TemporaryCells[x][y - 1]->getObject()
               == nullptr) {
      Object* children_Predator = new Predator
          ("Predator", "Prey",
                                               eatTime, lifeTime, reproduceTime,
                                               TemporaryCells[x][y - 1]);
      TemporaryCells[x][y - 1]->SetObject(children_Predator);
      TemporaryCreatures.push_back(children_Predator);
    } else if (y - 1 == -1) {
      if (TemporaryCells[x][M - 1]->getObject() == nullptr) {
        Object *children_Predator = new Predator
            ("Predator", "Prey",
             eatTime, lifeTime, reproduceTime,
             TemporaryCells[x][M - 1]);
        TemporaryCells[x][M - 1]->SetObject(children_Predator);
        TemporaryCreatures.push_back(children_Predator);
      }
    } else if (x + 1 != N && TemporaryCells[x + 1][y]->getObject()
               == nullptr) {
      Object* children_Predator = new Predator
          ("Predator", "Prey",
                                               eatTime, lifeTime, reproduceTime,
                                               TemporaryCells[x + 1][y]);
      TemporaryCells[x + 1][y]->SetObject(children_Predator);
      TemporaryCreatures.push_back(children_Predator);
    } else if (x + 1 == N) {
      if (TemporaryCells[0][y]->getObject() == nullptr) {
        Object* children_Predator = new Predator
            ("Predator", "Prey",
                                                 eatTime, lifeTime,
                                                 reproduceTime,
                                                 TemporaryCells[0][y]);
        TemporaryCells[0][y]->SetObject(children_Predator);
        TemporaryCreatures.push_back(children_Predator);
      }
    } else if (x - 1 != -1 && TemporaryCells[x - 1][y]->getObject()
               == nullptr) {
      Object* children_Predator = new Predator
          ("Predator", "Prey",
                                               eatTime, lifeTime, reproduceTime,
                                               TemporaryCells[x - 1][y]);
      TemporaryCells[x - 1][y]->SetObject(children_Predator);
      TemporaryCreatures.push_back(children_Predator);
    } else if (x - 1 == -1) {
      if (TemporaryCells[N - 1][y]->getObject() == nullptr) {
        Object* children_Predator = new Predator
            ("Predator", "Prey",
                                                 eatTime, lifeTime,
                                                 reproduceTime,
                                                 TemporaryCells[N - 1][y]);
        TemporaryCells[N - 1][y]->SetObject(children_Predator);
        TemporaryCreatures.push_back(children_Predator);
      }
    }
  }
  // Движение
  // Сначала мы должны понять, где жертва, чтобы плыть за ней.
  // Поиск жертвы
  // Если жертв в реке не осталось, то нечего искать
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (TemporaryCells[i][j]->getObject() != nullptr &&
      TemporaryCells[i][j]->getObject()->getName() == "Prey") {
        isPrey = true;
        break;
      }
    }
  }
  std::queue<Cell* > q;
  q.push(obj_cell);
  std::vector<std::vector<bool> > used(N,
                                       std::vector<bool>(M,
                                                         false));
  std::vector<Pair* > p(N * M);
  Pair coord_prey;
  used[x][y] = true;
  int k{0};
  if (isPrey) {
    while (!q.empty()) {
      Cell* temporary_cell = q.front();
      int tx = temporary_cell->getPair()->x;
      int ty = temporary_cell->getPair()->y;
      q.pop();
      if (ty + 1 != M && TemporaryCells[tx][ty + 1]->getObject() ==
      nullptr) {
        if (!used[tx][ty + 1]) {
          q.push(TemporaryCells[tx][ty + 1]);
          p[k] = TemporaryCells[tx][ty]->getPair();
          used[tx][ty + 1] = true;
        }
      } else if (ty + 1 == M) {
        if (TemporaryCells[tx][0]->getObject() == nullptr) {
          if (!used[tx][0]) {
            q.push(TemporaryCells[tx][0]);
            p[k] = TemporaryCells[tx][ty]->getPair();
            used[tx][0] = true;
          }
        } else if (TemporaryCells[tx][0]->getObject()->getName() ==
                  "Prey") {
          p[k] = TemporaryCells[tx][ty]->getPair();
          coord_prey.x = tx;
          coord_prey.y = 0;
          break;
        }
      } else if (TemporaryCells[tx][ty + 1]->getObject()->getName() ==
                "Prey") {
        p[k] = TemporaryCells[tx][ty]->getPair();
        coord_prey.x = tx;
        coord_prey.y = ty + 1;
        break;
      }
      if (ty - 1 != -1 && TemporaryCells[tx][ty - 1]->getObject() ==
          nullptr) {
        if (!used[tx][ty - 1]) {
          q.push(TemporaryCells[tx][ty - 1]);
          p[k] = TemporaryCells[tx][ty]->getPair();
          used[tx][ty - 1] = true;  // Косяк
        }
      } else if (ty - 1 == -1) {
        if (TemporaryCells[tx][M - 1]->getObject() == nullptr) {
          if (!used[tx][M - 1]) {
            q.push(TemporaryCells[tx][M - 1]);
            p[k] = TemporaryCells[tx][ty]->getPair();
            used[tx][M - 1] = true;
          }
        } else if (TemporaryCells[tx][M - 1]->getObject()->getName() ==
                  "Prey") {
          p[k] = TemporaryCells[tx][ty]->getPair();
          coord_prey.x = tx;
          coord_prey.y = M - 1;
          break;
        }
      } else if (TemporaryCells[tx][ty - 1]->getObject()->getName() ==
                "Prey") {
        p[k] = TemporaryCells[tx][ty]->getPair();
        coord_prey.x = tx;
        coord_prey.y = ty - 1;
        break;
      }
      if (tx + 1 != N && TemporaryCells[tx + 1][ty]->getObject() ==
          nullptr) {
        if (!used[tx + 1][ty]) {
          q.push(TemporaryCells[tx + 1][ty]);
          p[k] = TemporaryCells[tx][ty]->getPair();
          used[tx + 1][ty] = true;
        }
      } else if (tx + 1 == N) {
        if (TemporaryCells[0][ty]->getObject() == nullptr) {
          if (!used[0][ty]) {
            q.push(TemporaryCells[0][ty]);
            p[k] = TemporaryCells[tx][ty]->getPair();
            used[0][ty] = true;
          }
        } else if (TemporaryCells[0][ty]->getObject()->getName() ==
                  "Prey") {
          p[k] = TemporaryCells[tx][ty]->getPair();
          coord_prey.x = 0;
          coord_prey.y = ty;
          break;
        }
      } else if (TemporaryCells[tx + 1][ty]->getObject()->getName() ==
                "Prey") {
        p[k] = TemporaryCells[tx][ty]->getPair();
        coord_prey.x = tx + 1;
        coord_prey.y = ty;
        break;
      }
      if (tx - 1 != -1 && TemporaryCells[tx - 1][ty]->getObject() ==
          nullptr) {
        if (!used[tx - 1][ty]) {
          q.push(TemporaryCells[tx - 1][ty]);
          p[k] = TemporaryCells[tx][ty]->getPair();
          used[tx - 1][ty] = true;
        }
      } else if (tx - 1 == -1) {
        if (TemporaryCells[N - 1][ty]->getObject() == nullptr) {
          if (!used[N - 1][ty]) {
            q.push(TemporaryCells[N - 1][ty]);
            p[k] = TemporaryCells[tx][ty]->getPair();
            used[N - 1][ty] = true;
          }
        } else if (TemporaryCells[N - 1][ty]->getObject()->getName() ==
                  "Prey") {
          p[k] = TemporaryCells[tx][ty]->getPair();
          coord_prey.x = N - 1;
          coord_prey.y = ty;
          break;
        }
      } else if (TemporaryCells[tx - 1][ty]->getObject()->getName() ==
                "Prey") {
        p[k] = TemporaryCells[tx][ty]->getPair();
        coord_prey.x = tx - 1;
        coord_prey.y = ty;
        break;
      }
      k++;
    }
  }
  auto result = std::unique(p.begin(), p.end());
  p.erase(result, p.end());
  // Движение
  if (p.size() == 2 && eat < eatTime) {
    TemporaryCreatures.erase(std::remove(TemporaryCreatures.begin(),
                                         TemporaryCreatures.end(),
                      TemporaryCells[coord_prey.x][coord_prey.y]->
                                         getObject()),
                             TemporaryCreatures.end());
    delete TemporaryCells[coord_prey.x][coord_prey.y]->
            getObject();  // Удалили связь обхекта с клеткой
    TemporaryCells[coord_prey.x][coord_prey.y]->
            delObject();  // Удалили связь клетки с обхектом
    TemporaryCells[x][y]->delObject();
    TemporaryCells[coord_prey.x][coord_prey.y]->SetObject(this);
    this->SetCell(TemporaryCells[coord_prey.x][coord_prey.y]);
    DoEat = true;
  } else if (p.size() > 2) {
    int n = static_cast<int>(p.size() - 2);
    coord_prey.x = p[n]->x;
    coord_prey.y = p[n]->y;
    TemporaryCells[x][y]->delObject();
    TemporaryCells[coord_prey.x][coord_prey.y]->SetObject(this);
    this->SetCell(TemporaryCells[coord_prey.x][coord_prey.y]);
  } else if (p.size() == 1) {
    SamePlace = true;
  }
  obj_cell->getOcean()->
            SetOceanCells(TemporaryCells);
  obj_cell->getOcean()->
            SetMarineCreatures(TemporaryCreatures);
  eat++;
  reproduce++;
  life++;
  p.clear();
  used.clear();
}
