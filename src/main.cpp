// Copyright 2021 ArinaMonicheva

#include "predator.h"

int main() {
  time_t* n = NULL;
  unsigned* seed = 0;
  srand(time(n));

  Ocean newOcean;
  int available = N * M, tenth = available / 10,
   stones = tenth + r_rand(&seed) % (available / 5 - tenth),
   preys = tenth + r_rand(&seed) % (available / 3 - tenth),
   predators = tenth + r_rand(&seed) % (available / 5 - tenth);
  int arr[3] = { stones, preys, predators };
  int size = 0;
  std::vector < std::vector <coords> > availableCoords(
   N, std::vector<coords>());

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      availableCoords[i].push_back({ (coord_t)j, (coord_t)i });
    }
  }

  while (size < 3) {
    newOcean.addObjects(arr[size], size, availableCoords);
    size++;
  }

  newOcean.run();

  return 0;
}
