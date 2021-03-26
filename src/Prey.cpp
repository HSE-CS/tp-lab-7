//  Copyright 2021 GHA created by Klykov Anton

#include "Prey.h"
#include "Ocean.h"
Prey::Prey(std::string name, int life,
           int reproduce, Cell* cell)
          : Object(cell) {
  lifeTime = life;
  reproduceTime = reproduce;
  p_name = name;
}
std::string Prey::getName() {
  return p_name;
}
void Prey::live() {
  std::vector<std::vector<Cell* >> TemporaryCells =
      obj_cell->getOcean()->GetCells();
  Ocean* temp_ocean = obj_cell->getOcean();
  std::vector<Object* > TemporaryCreatures =
      obj_cell->getOcean()->GetCreatures();
  int x = obj_cell->getPair()->x;
  int y = obj_cell->getPair()->y;
  static int reproduce{0};
  static int life{0};
  if (life == lifeTime) {
    reproduce = 0;
    life = 0;
    TemporaryCells[x][y]->delObject();
    TemporaryCreatures.erase(std::remove
    (TemporaryCreatures.begin(),
                                         TemporaryCreatures.end(),
                                         this),
                             TemporaryCreatures.end());
    delete this;
    temp_ocean->SetOceanCells(TemporaryCells);
    temp_ocean->SetMarineCreatures(TemporaryCreatures);
    return;
  }
  // Если есть куда рожать - рожаем через заданное число итераций
  if (reproduce == reproduceTime) {
    reproduce = 0;
    if (y + 1 != M && TemporaryCells[x][y + 1]->getObject() ==
        nullptr) {
      Object* children_Prey = new Prey("Prey",
                                       lifeTime, reproduceTime,
                                       TemporaryCells[x][y + 1]);
      TemporaryCells[x][y + 1]->SetObject(children_Prey);
      TemporaryCreatures.push_back(children_Prey);
    } else if (y + 1 == M) {
      if (TemporaryCells[x][0]->getObject() == nullptr) {
        Object *children_Prey = new Prey("Prey",
                                         lifeTime, reproduceTime,
                                         TemporaryCells[x][0]);
        TemporaryCells[x][0]->SetObject(children_Prey);
        TemporaryCreatures.push_back(children_Prey);
      }
    } else if (y - 1 != -1 && TemporaryCells[x][y - 1]->getObject() ==
    nullptr) {
      Object* children_Prey = new Prey("Prey",
                                       lifeTime, reproduceTime,
                                       TemporaryCells[x][y - 1]);
      TemporaryCells[x][y - 1]->SetObject(children_Prey);
      TemporaryCreatures.push_back(children_Prey);
    } else if (y - 1 == -1) {
      if (TemporaryCells[x][M - 1]->getObject() == nullptr) {
        Object* children_Prey = new Prey("Prey",
                                         lifeTime, reproduceTime,
                                         TemporaryCells[x][M - 1]);
        TemporaryCells[x][M - 1]->SetObject(children_Prey);
        TemporaryCreatures.push_back(children_Prey);
      }
    } else if (x + 1 != N && TemporaryCells[x + 1][y]->getObject() ==
            nullptr) {
      Object* children_Prey = new Prey("Prey",
                                       lifeTime, reproduceTime,
                                       TemporaryCells[x + 1][y]);
      TemporaryCells[x + 1][y]->SetObject(children_Prey);
      TemporaryCreatures.push_back(children_Prey);
    } else if (x + 1 == N) {
      if (TemporaryCells[0][y]->getObject() == nullptr) {
        Object* children_Prey = new Prey("Prey",
                                         lifeTime, reproduceTime,
                                         TemporaryCells[0][y]);
        TemporaryCells[0][y]->SetObject(children_Prey);
        TemporaryCreatures.push_back(children_Prey);
      }
    } else if (x - 1 != -1 && TemporaryCells[x - 1][y]->getObject() ==
            nullptr) {
      Object* children_Prey = new Prey("Prey",
                                       lifeTime, reproduceTime,
                                       TemporaryCells[x - 1][y]);
      TemporaryCells[x - 1][y]->SetObject(children_Prey);
      TemporaryCreatures.push_back(children_Prey);
    } else if (x - 1 == -1) {
      if (TemporaryCells[N - 1][y]->getObject() == nullptr) {
        Object* children_Prey = new Prey("Prey",
                                         lifeTime, reproduceTime,
                                         TemporaryCells[N - 1][y]);
        TemporaryCells[N - 1][y]->SetObject(children_Prey);
        TemporaryCreatures.push_back(children_Prey);
      }
    }
  }
  // Движение
  // Если мы не у края и справа/слева/сверху/снизу 
  // пусто - идем туда, если непусто проверяем другие места
  // Если мы у края, то проверям свободно ли у 
  // другого конца, если да - идем, если нет - не идем.
    if (y + 1 != M && TemporaryCells[x][y + 1]->getObject() ==
        nullptr) {
      TemporaryCells[x][y + 1]->SetObject(this);
      this->SetCell(TemporaryCells[x][y + 1]);
      TemporaryCells[x][y]->delObject();
    } else if (y + 1 == M) {
      if (TemporaryCells[x][0]->getObject() == nullptr) {
        TemporaryCells[x][0]->SetObject(this);
        this->SetCell(TemporaryCells[x][0]);
        TemporaryCells[x][y]->delObject();
      }
    } else if (y - 1 != -1 && TemporaryCells[x][y - 1]->getObject()
                == nullptr) {
      TemporaryCells[x][y - 1]->SetObject(this);
      this->SetCell(TemporaryCells[x][y - 1]);
      TemporaryCells[x][y]->delObject();
    } else if (y - 1 == -1) {
      if (TemporaryCells[x][M - 1]->getObject() == nullptr) {
        TemporaryCells[x][M - 1]->SetObject(this);
        this->SetCell(TemporaryCells[x][M - 1]);
        TemporaryCells[x][y]->delObject();
      }
    } else if (x + 1 != N && TemporaryCells[x + 1][y]->getObject()
              == nullptr) {
      TemporaryCells[x + 1][y]->SetObject(this);
      this->SetCell(TemporaryCells[x + 1][y]);
      TemporaryCells[x][y]->delObject();
    } else if (x + 1 == N) {
      if (TemporaryCells[0][y]->getObject() == nullptr) {
        TemporaryCells[0][y]->SetObject(this);
        this->SetCell(TemporaryCells[0][y]);
        TemporaryCells[x][y]->delObject();
      }
    } else if (x - 1 != -1 && TemporaryCells[x - 1][y]->getObject()
              == nullptr) {
      TemporaryCells[x - 1][y]->SetObject(this);
      this->SetCell(TemporaryCells[x - 1][y]);
      TemporaryCells[x][y]->delObject();
    } else if (x - 1 == -1) {
      if (TemporaryCells[N - 1][y]->getObject() == nullptr) {
        TemporaryCells[N - 1][y]->SetObject(this);
        this->SetCell(TemporaryCells[N - 1][y]);
        TemporaryCells[x][y]->delObject();
    }
  }
  obj_cell->getOcean()->SetOceanCells(TemporaryCells);
  obj_cell->getOcean()->SetMarineCreatures(TemporaryCreatures);
  reproduce++;
  life++;
}
Prey::~Prey() {
  lifeTime = -1;
  reproduceTime = -1;
  p_name = "";
}
