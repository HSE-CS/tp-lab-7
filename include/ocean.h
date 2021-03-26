#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include "../include/cell.h"
#include "../include/common.h"

class Cell;
class Object;
enum class ObjType;
class Ocean {
 private:
  Cell **cells;
  std::list<Object *> stuff;
  std::list<Object *> blackList;
  int sizeN;
  int sizeM;

 public:
  Ocean(int sizeN, int sizeM, int numOfStones, int numOfPreys,
        int numOfPredators);
  ~Ocean() = default;
  void print() const;
  void addObjects(ObjType type, int number);
  Cell *findCellAround(Pair coord);
  void run();

  void addObject(Object *);

  void addToBlackList(Object *obj);
  void thinTheRanks();
  Cell *findCellWithPrey(Pair coord);
};

#endif  // INCLUDE_OCEAN_H_