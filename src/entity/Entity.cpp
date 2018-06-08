#include "Entity.hpp"

Entity::~Entity()
{
}

bool Entity::shouldBeRemoved() const
{
	return toRemove;
}

void Entity::collideWith(Entity* other)
{
	toRemove = true;
}
