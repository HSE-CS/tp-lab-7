#pragma once
#include <vector>

class Object;

class World {
  std::vector<Object*> objects;
  int width;
  int height;

 public:
  World(int width, int height);
  ~World();
  void init(int seed);
  void replace(Object* object, int x, int y);
  void swap(int a_x, int a_y, int b_x, int b_y);
  int getWidth() const;
  int getHeight() const;
  Object* getObjectAt(int x, int y) const;
  bool update();
  void printWorld() const;
};
