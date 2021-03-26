// Copyright dmitrycvetkov 2021
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "object.h"

#include <memory>

class Prey : public Object {
 public:
    explicit Prey(std::weak_ptr<Cell> cell);

    void live() override;
    virtual void reproduce(const std::shared_ptr<Cell>& cell);
    void die();
    ObjType type() const override;

 protected:
    std::size_t age;
    std::shared_ptr<Cell> move();

 private:
    std::size_t reproductionTimer;
};

#endif  // INCLUDE_PREY_H_
