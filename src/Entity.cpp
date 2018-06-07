#include "Entity.hpp"

bool Entity::shouldBeRemoved() const
{
	return toRemove;
}

void Entity::collideWith(Entity* other)
{
	toRemove = true;
}
