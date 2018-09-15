#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <Arduboy2.h>
#include <FixedPoints.h>

class Entity
{
private:
	bool toRemove = false;

public:
	UFixed<14, 2> x = 0;
	UFixed<6, 2> y = 0;

	virtual ~Entity();

	virtual void update() = 0;
	virtual void draw() const = 0;
	virtual bool shouldBeRemoved() const;

	void collideWithEntity(Entity* other);
	void collideWithLevel();
	virtual Rect getCollisionBox() const = 0;
};

#endif
