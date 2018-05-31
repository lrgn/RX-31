#include "Missile.hpp"
#include <Arduboy2.h>

extern Arduboy2 arduboy;

void Missile::draw() const
{
	arduboy.drawFastHLine(x, y, 2, WHITE);
}

void Missile::update()
{
	this->x++;
}
