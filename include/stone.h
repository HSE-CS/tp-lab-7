// Copyright slavokeru 2021
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include"object.h"
class Stone : public Object {
public:
	Stone();
	void live() override {}
};
#endif  // INCLUDE_STONE_H_