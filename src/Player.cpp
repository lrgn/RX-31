#include "Player.hpp"
#include <Arduboy2.h>

extern Arduboy2 arduboy;

void Player::draw() const
{
	arduboy.drawRect((uint16_t) x, (uint8_t) y, 8, 8, WHITE);
}

void Player::update()
{
}

bool Player::shouldBeRemoved() const
{
	return false;
}
