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
/*
void screenCleaner() {
  COORD topLeft  = { 0, 0 };
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO screen;
  DWORD written;
  GetConsoleScreenBufferInfo(console, &screen);
  FillConsoleOutputCharacterA(
      console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
  );
  FillConsoleOutputAttribute(
      console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
      screen.dwSize.X * screen.dwSize.Y, topLeft, &written
  );
  SetConsoleCursorPosition(console, topLeft);
}
*/

#endif  //  INCLUDE_COMMON_H_
