#include "Booster.hpp"

#include <Sprites.h>
#include "data/bitmaps.h"

void Booster::draw() const
{
	Sprites::drawPlusMask((uint16_t) x, (uint8_t) y, sprites_plus_mask, SPR_BOOSTER);
}

void Booster::update()
{
	x -= 2;
}

Rect Booster::getCollisionBox() const
{
	Rect collisionBox;
	collisionBox.x = (uint16_t)x;
	collisionBox.y = (uint8_t)y;
	collisionBox.height = 8;
	collisionBox.width = 8;
	return collisionBox;
}
