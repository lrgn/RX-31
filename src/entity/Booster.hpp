#ifndef BOOSTER_HPP
#define BOOSTER_HPP

#include "Entity.hpp"

class Booster : public Entity
{
public:
	void draw() const;
	void update();
	Rect getCollisionBox() const;
};

#endif
