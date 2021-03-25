// Copyright 2021 MalininDmitry

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

class Predator : public Prey {
 protected:
    ObjType type;
    int satiety = 0;
    int deathByStarvation = 0;
 public:
    explicit Predator(int live_count,
                      int time_reproduction,
                      Cell * cell, int satiety,
                      int deathByStarvation,
                      ObjType type);
    ~Predator() override;
    void live() override;
    void go();
};

#endif  // INCLUDE_PREDATOR_H_
