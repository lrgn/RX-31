#include "Game.hpp"
#include "globals.h"

#include "generated/levels.h"

Game::Game()
	: level(createLevel(LVL_LEVEL1))
	,entities(ENTITIES_MAX_SIZE)
{
}

void Game::spawnEntity(Entity* entity)
{
	if (!entities.add(entity))
		delete entity;

	// TODO: for test purpose, move elsewhere
	if (entities.getSize() == ENTITIES_MAX_SIZE)
		arduboy.digitalWriteRGB(RGB_ON,    RGB_OFF,  RGB_ON );
	else
		arduboy.digitalWriteRGB(RGB_OFF,    RGB_OFF,  RGB_OFF );
}

void Game::update()
{
	level->update ();

	// Update all entites
	for (uint8_t i = 0; i != entities.getSize(); i++)
		entities.get(i)->update();

	// Check for collision
	for (uint8_t i = 0; i != entities.getSize(); i++)
	{
		Entity* entity = entities.get(i);
		Rect collisionBox = entity->getCollisionBox();

		// With the level
		if (level->collide(collisionBox))
			entity->collideWithLevel();

		// With other entities
		for (uint8_t j = i+1; j != entities.getSize(); j++)
		{
			Entity* otherEntity = entities.get(j);

			if (arduboy.collide(collisionBox, otherEntity->getCollisionBox()))
			{
				entity->collideWithEntity(otherEntity);
				otherEntity->collideWithEntity(entity);
			}
		}
	}

	// Remove entities that should be removed
	for (uint8_t i = 0; i != entities.getSize(); i++)
	{
		Entity* entity = entities.get(i);

		if (entity->shouldBeRemoved())
		{
			entities.removeAt(i);
			delete entity;
			i--;
		}
	}
}

void Game::draw() const
{
	level->draw();

	for (uint8_t i = 0; i != entities.getSize(); i++)
		entities.get(i)->draw();
}
