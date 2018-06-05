#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <stdint.h>
#include <FixedPoints.h>

class Entity
{
public:
	UFixed<14, 2> x = 0;
	UFixed<6, 2> y = 0;

	virtual void update() = 0;
	virtual void draw() const = 0;
	virtual bool shouldBeRemoved() const = 0;
};

#endif
