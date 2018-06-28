#include <Arduboy2.h>
#include "Game.hpp"

// Entities IDs
#define ENT_BOOSTER 1
#define ENT_BURGERSHIP 2

#define multiplyBy8(n)  (n << 3)
#define divideBy8(n)    (n >> 3)
#define modulo8(n)      (n & 0x0007)

extern Arduboy2 arduboy;
extern Game game;
