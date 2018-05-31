#include "Player.hpp"
#include <Arduboy2.h>

extern Arduboy2 arduboy;

void Player::draw() const
{
	arduboy.drawRect(x, y, 8, 8, WHITE);
}

void Player::update()
{
}
