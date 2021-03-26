// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <map>
enum NATURE {
  UNKNOWN,
  PREY,
  PREDATOR,
  STONE
};


/*
namespace FEATURES {

std::map<NATURE, char> picture{{UNKNOWN, '.'},
                                  {PREY, 'f'},
                                  {PREDATOR, 'S'},
                                  {STONE, '#'}};

  std::map<NATURE, unsigned int> longevity{{UNKNOWN, 0},
                                                {PREY, 20},
                                                {PREDATOR, 10},
                                                {STONE, 1000}};

  std::map<NATURE, unsigned int> breedingTime{{UNKNOWN, 0},
                                                {PREY, 3},
                                                {PREDATOR, 5},
                                                {STONE, 0}};

  std::map<NATURE, unsigned int> eatTime{{UNKNOWN, 0},
                                                {PREY, 0},
                                                {PREDATOR, 2},
                                                {STONE, 0}};

  std::map<NATURE, int> minTemperature{{UNKNOWN, 0},
                                              {PREY, -20},
                                              {PREDATOR, -25},
                                              {STONE, -100}};

  std::map<NATURE, int> maxTemperature{{UNKNOWN, 0},
                                              {PREY, 40},
                                              {PREDATOR, 35},
                                              {STONE, 250}};

}
*/
/*
std::map<NATURE, char> picture{{UNKNOWN, '.'},
                                  {PREY, 'f'},
                                  {PREDATOR, 'S'},
                                  {STONE, '#'}};

  std::map<NATURE, unsigned int> longevity{{UNKNOWN, 0},
                                                {PREY, 20},
                                                {PREDATOR, 10},
                                                {STONE, 1000}};

  std::map<NATURE, unsigned int> breedingTime{{UNKNOWN, 0},
                                                {PREY, 3},
                                                {PREDATOR, 5},
                                                {STONE, 0}};

  std::map<NATURE, unsigned int> eatTime{{UNKNOWN, 0},
                                                {PREY, 0},
                                                {PREDATOR, 2},
                                                {STONE, 0}};

  std::map<NATURE, int> minTemperature{{UNKNOWN, 0},
                                              {PREY, -20},
                                              {PREDATOR, -25},
                                              {STONE, -100}};

  std::map<NATURE, int> maxTemperature{{UNKNOWN, 0},
                                              {PREY, 40},
                                              {PREDATOR, 35},
                                              {STONE, 250}};
*/


#endif  //  INCLUDE_COMMON_H_
