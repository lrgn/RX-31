#include "Entity.hpp"

Entity::~Entity()
{
}

bool Entity::shouldBeRemoved() const
{
	return toRemove;
}

void Entity::collideWithEntity(Entity* other)
{
	toRemove = true;
}

void Entity::collideWithLevel()
{
	toRemove = true;
}
