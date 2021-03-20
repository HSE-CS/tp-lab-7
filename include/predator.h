//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_
#include "prey.h"

class Predator : public Prey {
 public:
  explicit Predator(ObjType type, Cell *cell) :
      Prey(type, cell),
      ot(type),
      breedCount(PREDATOR_BREED_PERIOD),
      healthCount(PREDATOR_LIFE_PERIOD) {}
  void live() override;
  /* work with breed */
  [[nodiscard]] int getBreedPredator() const;
  void setBreedPredator(int val);
  void updateBreedPredator();
  /* work with health */
  [[nodiscard]] int getHealthPredator() const;
  void setHealthPredator(int val);
  void updateHealthPredator();
  /* move */
  void movePredator();
  /* breed Predator */
  void breedPredator();
  /* kill Predator */
  void killPredator();

 private:
  ObjType ot;
  int breedCount;
  int healthCount;
};

#endif  //  INCLUDE_PREDATOR_H_
