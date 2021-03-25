// Copyright NikDemoShow 2021
#include"predator.h"
#include"cell.h"
#include<iostream>
Predator::Predator(Cell* newCell) {
	this->cell = newCell;
	this->reproduction = 0;
	this->timeLive = std::rand() % 10 + 30;
	this->timeToReproduction = std::rand() % 10 + 6;
	this->weelFed = this->fullWeelFed;
	this->type = ObjType::PREDATOR;
}

void Predator::live() {
	if (this->timeLive && this->weelFed) {
		if (this->reproduction >= this->timeToReproduction && this->weelFed == this->fullWeelFed) {
			Cell* newCell{ this->cell->getFreeNeighbour() };
			if (newCell && !newCell->getObject()) {
				this->cell->addObject(this->type, newCell);
				this->reproduction = 0;
				this->weelFed -= 2;
			}
		}
		else {
			Cell* newCell{ this->cell->getFreeNeighbour(this->weelFed <= this->fullWeelFed) };
			if (newCell) {
				this->cell->setObject(nullptr);
				if (newCell->getObject()) {
				newCell->getObject()->setCell(nullptr);
					this->weelFed += 5;
				}
				this->setCell(newCell);
				this->cell->setObject(this);
			}
		}
		this->weelFed--;
		this->timeLive--;
		this->reproduction++;
	}
	else {
		this->cell->setObject(nullptr);
		this->setCell(nullptr);
	}
}
