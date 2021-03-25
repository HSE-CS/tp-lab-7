// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <cstdint>
#include <list>
#include <random>
#include <vector>

enum object_t {
  NONE = -1,
  STONE,
  PREY,
  PREDATOR,
};

struct coord_t {
  size_t x, y;
};

// Common output
#define OUTPUT_CYCLE_COUNT WINT_MAX  // max count of cycles
#define OUTPUT_CYCLE_SLEEP 40        // millisec

#define OUTPUT_SIGN_STONE (char)254  // ■
#define OUTPUT_SIGN_PREY '-'
#define OUTPUT_SIGN_PREDATOR 'x'

// Ocean
// The begin point is the top left corner
#define OCEAN_SIZE_WIDTH 100
#define OCEAN_SIZE_HEIGHT 35

// Health - max count of cycles alive
// Stamina - count of steps during the cycle
#define OBJECT_PREY_HEALTH 2
#define OBJECT_PREY_STAMINA 1

#define OBJECT_PREDATOR_HEALTH 4
#define OBJECT_PREDATOR_STAMINA 1

#endif  // INCLUDE_COMMON_H_
