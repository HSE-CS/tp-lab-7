// Copyright 2021 Ilya Urtyukov
#include "ocean.h"


int main() {
  unsigned size_x = 0, size_y = 0;
  unsigned stones_n = 0, preys_n = 0, predators_n = 0;
  unsigned prey_live_num = 0, predator_live_num = 0;
  unsigned prey_food_n_to_reproduce = 0, predator_food_n_to_reproduce = 0;
  std::cout << "Enter ocean params: " << std::endl;
  std::cout << "Ocean size (n * m): >> ";
  std::cin >> size_x >> size_y;
  std::cout << "Ocean objects numbers:(stones, preys, predators): >> ";
  std::cin >> stones_n >> preys_n >> predators_n;
  std::cout << "Prey's and Predators's live counts: >> ";
  std::cin >> prey_live_num >> predator_live_num;
  std::cout << "Prey's and Predators's numbers of food to reproduce: >> ";
  std::cin >> prey_food_n_to_reproduce >> predator_food_n_to_reproduce;
  Ocean* ocean = new Ocean(size_x, size_y, stones_n, preys_n, predators_n,
    prey_live_num, prey_food_n_to_reproduce, predator_live_num,
    predator_food_n_to_reproduce);
  // Ocean* ocean = new Ocean(20, 60, 100, 450, 200, 8, 3, 6, 3, 3000);
  ocean->run();
  return 0;
}
