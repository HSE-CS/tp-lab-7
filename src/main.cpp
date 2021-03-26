#include <chrono>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <thread>

#include "world.h"

int main(int argc, char** argv) {
  int current_arg = 1;
  int height = 0;
  int width = 0;
  int max_iterations = 0;
  int seed = 0;
  if (argc < 3) {
    std::cout << "not enough arguments: need to set height(-h), width(-w), "
                 "seed(-s) and max number of iterations(-m)\n";
    std::exit(0);
  }
  while (current_arg < argc - 1) {
    if (std::strcmp(argv[current_arg], "-h") == 0) {
      height =
          static_cast<int>(std::strtol(argv[current_arg + 1], nullptr, 10));
      if (height <= 0) {
        std::cout << "invalid height\n";
        std::exit(1);
      }
    } else if (std::strcmp(argv[current_arg], "-w") == 0) {
      width = static_cast<int>(std::strtol(argv[current_arg + 1], nullptr, 10));
      if (width <= 0) {
        std::cout << "invalid width\n";
        std::exit(1);
      }
    } else if (std::strcmp(argv[current_arg], "-m") == 0) {
      max_iterations =
          static_cast<int>(std::strtol(argv[current_arg + 1], nullptr, 10));
      if (max_iterations <= 0) {
        std::cout << "invalid max iterations count\n";
        std::exit(1);
      }
    } else if (std::strcmp(argv[current_arg], "-s") == 0) {
      seed = static_cast<int>(std::strtol(argv[current_arg + 1], nullptr, 10));
      if (seed == 0) {
        std::cout << "invalid seed\n";
        std::exit(1);
      }
    } else {
      std::cout << "invalid argument\n";
      std::exit(1);
    }
    current_arg += 2;
  }
  World world(width, height, seed);
  std::cout << "\033[?1049h";
  int i = 0;
  for (;;) {
    i += 1;
    std::cout << "iteration: " << i << "/" << max_iterations << "\n";
    bool done = world.update();
    world.printWorld();
    if (i >= max_iterations) {
      std::cout << "\nMax iteration limit reached!\n"
                << "(press any key to exit)";
      std::cin.get();
      break;
    }
    if (!done) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      std::cout << "\033[3J\033[1;1H";
    } else {
      std::cout << "\nAll done!\n"
                << "simulation took " << i << " iterations\n\n"
                << "(press any key to exit)";
      std::cin.get();
      break;
    }
  }
  std::cout << "\033[?1049l";
  return 0;
}
