#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity
{
public:
	void draw() const;
	void update();
	bool shouldBeRemoved() const;
};

#endif
