#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "Entity.hpp"

class Missile : public Entity
{
public:
	void draw() const;
	void update();
};

#endif
