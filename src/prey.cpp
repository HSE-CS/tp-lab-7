#include "prey.h"
#include "object.h"

void Prey::move()
{
  Cell* cel = getCell()->getOcean()->find(cell);
  if (cell != nullptr) {
    cell->setObject(nullptr);
    cell->setObject(this);
    setCell(cell);
  }
}

void Prey::live()
{
  if (!this->cell) return;
  
}
