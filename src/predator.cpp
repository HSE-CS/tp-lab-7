#include "predator.h"
Predator::Predator(Cell* c) : Object(c) {
  this->livetime = LTPredator;
  type = ObjType::PREDATOR;
}
void Predator::live() {
  if (eat() != true && livetime > 2)
    livetime -= 2;
  else
    livetime--;
  move();
  if (livetime < 0.1 * LTPredator) copulation();
}
char Predator::getSymbol() { return PREDATOR_N; }
void Predator::move() {
  Cell* newCell = cell->FREE();
  if (newCell != nullptr) {
    this->getCell()->Moving();
    newCell->setObject(this);
    this->cell = newCell;
  }
}
bool Predator::eat() {
  Pair cord = cell->Cord();

  Cell* sacrifice = cell->RADAR();
  if (sacrifice && !sacrifice->getObject()->isLive() &&
      sacrifice->getObject()->getType() == ObjType::PREY) {
    sacrifice->getObject()->readytodie();
    sacrifice->getObject()->setLive(0);
    livetime += 5;
    return true;
  }
  return false;
}
void Predator::copulation() {
  Cell* newCell = cell->FREE();
  if (newCell) {
    Object* child = new Predator(newCell);
    newCell->setObject(child);
    cell->getOcean()->AddStuff(child);
  }
}
