#ifndef _INCLUDE_PREDATOR_H_
#define _INCLUDE_PREDATOR_H_

#include "Object.h"

class Predator : public Object {
 private:
  size_t lifeTime;
  size_t hunger;
  size_t hungerLimit;
  size_t breedTime;
  size_t breedCoolDawn;

 public:
  explicit Predator(Cell *cell_ = nullptr, size_t lifeTime_ = 0,
                    size_t breedCoolDawn_ = 0, size_t _hungerLimit = 10);
  void live() override;
  void breedingTime();
  void death();
  void move();
};

#endif  // !_INCLUDE_PREDATOR_H_
