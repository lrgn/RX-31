#ifndef BURGERSHIP_HPP
#define BURGERSHIP_HPP

#include "Entity.hpp"

class BurgerShip : public Entity
{
public:
	void draw() const;
	void update();
	bool shouldBeRemoved() const;
};

#endif
