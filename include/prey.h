//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "stone.h"

class Prey : public Stone {
 public:
  explicit Prey(ObjType type, Cell *cell) :
      Stone(type, cell),
      ot(type),
      breedCount(PREY_BREED_PERIOD),
      healthCount(PREY_LIFE_PERIOD) {};
  void live() override;
  /* work with breed */
  [[nodiscard]] int getBreedCount() const;
  void setBreedCount(int val);
  void updateBreedCount();
  /* work with health */
  [[nodiscard]] int getHealth() const;
  void setHealth(int val);
  void updateHealth();
  /* move */
  void movePrey();
  /* breed prey */
  void breedPrey();
  /* death */
  void killPrey();

 private:
  ObjType ot;
  int breedCount;
  int healthCount;
};

#endif //TP_LAB_7_INCLUDE_PREY_H_
