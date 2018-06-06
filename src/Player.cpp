#include "Player.hpp"
#include "globals.h"
#include "Missile.hpp"

#define moveLeft(velocity)  if (this->x >= velocity) this->x = this->x - velocity
#define moveRight(velocity) if (this->x + velocity <= 120) this->x = this->x + velocity
#define moveUp(velocity)    if (this->y >= velocity) this->y -= velocity
#define moveDown(velocity)  if (this->y + velocity <= 56) this->y += velocity

void Player::draw() const
{
	arduboy.drawRect((uint16_t) x, (uint8_t) y, 8, 8, WHITE);
}

void Player::update()
{
	if (arduboy.pressed(LEFT_BUTTON | UP_BUTTON))
	{
		moveLeft(diagonalVelocity);
		moveUp(diagonalVelocity);
	}
	else if (arduboy.pressed(LEFT_BUTTON | DOWN_BUTTON))
	{
		moveLeft(diagonalVelocity);
		moveDown(diagonalVelocity);
	}
	else if (arduboy.pressed(RIGHT_BUTTON | UP_BUTTON))
	{
		moveRight(diagonalVelocity);
		moveUp(diagonalVelocity);
	}
	else if (arduboy.pressed(RIGHT_BUTTON | DOWN_BUTTON))
	{
		moveRight(diagonalVelocity);
		moveDown(diagonalVelocity);
	}
	else if (arduboy.pressed(LEFT_BUTTON))
	{
		moveLeft(velocity);
	}
	else if (arduboy.pressed(RIGHT_BUTTON))
	{
		moveRight(velocity);
	}
	else if (arduboy.pressed(UP_BUTTON))
	{
		moveUp(velocity);
	}
	else if (arduboy.pressed(DOWN_BUTTON))
	{
		moveDown(velocity);
	}

	if (arduboy.justPressed(A_BUTTON))
	{
		Missile* missile = new Missile();
		missile->x = this->x + 8;
		missile->y = this->y + 4;
		game.spawnEntity(missile);
	}
}

bool Player::shouldBeRemoved() const
{
	return false;
}

void Player::resetVelocity()
{
	velocity  = INITIAL_VELOCITY;
	diagonalVelocity = velocity / sqrt(2);
}

void Player::incrementVelocity()
{
	velocity += VELOCITY_INCREMENT;
	diagonalVelocity = velocity / sqrt(2);
}
