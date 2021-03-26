// Copyright dmitrycvetkov 2021
#ifndef _OBJECT_FACTORY_H_
#define _OBJECT_FACTORY_H_

#include <memory>

class Object;
class Cell;
enum class ObjType;

std::unique_ptr<Object> createObject(ObjType type, std::weak_ptr<Cell> cell);

#endif  // _OBJECT_FACTORY_H_
