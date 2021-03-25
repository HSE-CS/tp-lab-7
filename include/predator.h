// Copyright NikDemoShow 2021
#include"prey.h"
class Predator : public Prey {
private:
	static const unsigned int fullWeelFed{ 7 };
	unsigned int weelFed;
public:
	Predator(Cell* newCell = nullptr);
	virtual void live() override;
};
