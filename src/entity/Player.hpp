#ifndef PLAYER_HPP
#define PLAYER_HPP

#define INITIAL_VELOCITY 0.75
#define VELOCITY_INCREMENT 0.25

#include "Entity.hpp"

class Player : public Entity
{
private:
	UFixed<6, 2> velocity = INITIAL_VELOCITY;
	UFixed<6, 2> diagonalVelocity = INITIAL_VELOCITY;

public:
	void draw() const;
	void update();
	Rect getCollisionBox() const;

	void resetVelocity();
	void incrementVelocity();
};

#endif
