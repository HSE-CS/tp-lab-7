// Copyright NikDemoShow 2021
#ifndef _STONE_H_
#define _STONE_H_
#include"object.h"
class Stone : public Object {
public:
	Stone();
	virtual void live() override {}
};
#endif // _STONE_H_
