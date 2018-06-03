#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <stdint.h>

class Entity
{
public:
	uint16_t x = 0;
	uint8_t y = 0;

	virtual void update() = 0;
	virtual void draw() const = 0;
	virtual bool shouldBeRemoved() const = 0;
};

#endif
