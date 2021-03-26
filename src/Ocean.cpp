//  Copyright 2021 GHA created by Klykov Anton

#include "Ocean.h"

#include <utility>

void Ocean::CreateEmptyOcean() {
  OceanCells.assign(N, std::vector<Cell* >(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      OceanCells[i][j] = new Cell(Pair{i, j}, this);
    }
  }
}
void Ocean::LaunchCreatures() {
  Factory factory;
  factory.readFile();
  MarineCreatures = factory.getObjects();
  for (int i = 0; i < MarineCreatures.size(); ++i) {
    std::random_device rd;
    std::mt19937 randomCoord(rd());
    int randomX = static_cast<int>(randomCoord() % N);
    int randomY = static_cast<int>(randomCoord() % M);
    if (OceanCells[randomX][randomY]->getObject() == nullptr) {
      OceanCells[randomX][randomY]->
      SetObject(MarineCreatures[i]);
      MarineCreatures[i]->SetCell
      (OceanCells[randomX][randomY]);
    } else {
      static int k = N + M;
      while (OceanCells[randomX][randomY]->getObject() != nullptr) {
        randomX = static_cast<int>((randomCoord() +
            k * i) % N);
        randomY = static_cast<int>((randomCoord() +
            k * i + 1) % M);
        k++;
      }
      OceanCells[randomX][randomY]->SetObject
      (MarineCreatures[i]);
      MarineCreatures[i]->SetCell
      (OceanCells[randomX][randomY]);
    }
  }
}
void Ocean::printOcean() {
  std::cout << std::string(100, '\n');
  for (int i = 0; i < N; ++i) {
    for (int k = 0; k < M; ++k) {
      if (OceanCells[i][k]->getObject() != nullptr) {
        if (OceanCells[i][k]->getObject()->getName() == "Prey") {
          std::cout << "f";
        } else if (OceanCells[i][k]->getObject()->getName() ==
          "Predator") {
          std::cout << "p";
        } else if (OceanCells[i][k]->getObject()->getName() ==
          "Stone") {
          std::cout << "*";
        }
      } else {
        std::cout << " ";
      }
    }
    std::cout << "\n";
  }
}
std::vector<std::vector<Cell* >> Ocean::GetCells() {
  return OceanCells;
}
void Ocean::SetOceanCells(std::vector<std::vector<Cell *>>
    TemporaryCells) {
  OceanCells = std::move(TemporaryCells);
}
std::vector<Object* > Ocean::GetCreatures() {
  return MarineCreatures;
}
void Ocean::SetMarineCreatures(std::vector<Object *>
    TemporaryCreatures) {
  MarineCreatures = std::move(TemporaryCreatures);
}
bool Ocean::findPrey() {
  bool isPrey{false};
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (OceanCells[i][j]->getObject() != nullptr &&
          OceanCells[i][j]->getObject()->getName() ==
          "Prey") {
        isPrey = true;
        return isPrey;
      }
    }
  }
  return isPrey;
}
bool Ocean::findPredator() {
  bool isPredator{false};
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (OceanCells[i][j]->getObject() != nullptr &&
          OceanCells[i][j]->getObject()->getName() ==
          "Predator") {
        isPredator = true;
        return isPredator;
      }
    }
  }
  return isPredator;
}


