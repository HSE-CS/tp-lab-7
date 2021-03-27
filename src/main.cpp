// Copyright 2021 ArinaMonicheva

#include "../include/predator.h"

int main() {
  time_t* n = NULL;
  unsigned* seed = 0;
  srand(time(n));

  Ocean newOcean;
  int available = N * M, tenth = available / 10,
   stones = tenth + rand_r(seed) % (available / 5 - tenth),
   preys = tenth + rand_r(seed) % (available / 3 - tenth),
   predators = tenth + rand_r(seed) % (available / 5 - tenth);
  int arr[3] = { stones, preys, predators };
  int size = 0;
  std::vector < std::vector <coords> > availableCoords(
    N, std::vector<coords>());

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      availableCoords[i].push_back({ j, i });
    }
  }

  while (size < 3) {
    newOcean.addObjects(arr[size], size, availableCoords);
    size++;
  }

  newOcean.run();

  return 0;
}
