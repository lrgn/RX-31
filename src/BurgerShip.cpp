#include "BurgerShip.hpp"
#include <Arduboy2.h>

extern Arduboy2 arduboy;

void BurgerShip::draw() const
{
	arduboy.drawRect((uint16_t) x, (uint8_t) y, 8, 3, WHITE);
	arduboy.drawRect((uint16_t) x, ((uint8_t) y)+5, 8, 3, WHITE);
	arduboy.drawFastVLine(((uint16_t) x) + 2, ((uint8_t) y)+3, 2, WHITE);
	arduboy.drawFastVLine(((uint16_t) x) + 5, ((uint8_t) y)+3, 2, WHITE);
}

void BurgerShip::update()
{
}


Rect BurgerShip::getCollisionBox() const
{
	Rect collisionBox;
	collisionBox.x = (uint16_t)x;
	collisionBox.y = (uint8_t)y;
	collisionBox.height = 8;
	collisionBox.width = 8;
	return collisionBox;
}
