#include "Missile.hpp"
#include <Arduboy2.h>

extern Arduboy2 arduboy;

void Missile::draw() const
{
	arduboy.drawFastHLine((uint16_t) x, (uint8_t) y, 2, WHITE);
}

void Missile::update()
{
	this->x += 1.5;
}

bool Missile::shouldBeRemoved() const
{
	return x > 128 || Entity::shouldBeRemoved();
}

Rect Missile::getCollisionBox() const
{
	Rect collisionBox;
	collisionBox.x = (uint16_t)x;
	collisionBox.y = (uint8_t)y;
	collisionBox.height = 1;
	collisionBox.width = 2;
	return collisionBox;
}
