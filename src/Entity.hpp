#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <Arduboy2.h>
#include <FixedPoints.h>

class Entity
{
public:
	UFixed<14, 2> x = 0;
	UFixed<6, 2> y = 0;
	bool toRemove = false;

	virtual void update() = 0;
	virtual void draw() const = 0;
	virtual bool shouldBeRemoved() const;

	void collideWith(Entity* other);
	virtual Rect getCollisionBox() const = 0;
};

#endif
