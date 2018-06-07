#include "Game.hpp"
#include "globals.h"

Game::Game()
	: entities(ENTITIES_MAX_SIZE)
{
}

void Game::spawnEntity(Entity* entity)
{
	if (!entities.add(entity))
		delete entity;
}

void Game::update()
{

	// TODO: for test purpose, move elsewhere
	if (entities.getSize() == ENTITIES_MAX_SIZE)
		arduboy.digitalWriteRGB(RGB_ON,    RGB_OFF,  RGB_ON );
	else
		arduboy.digitalWriteRGB(RGB_OFF,    RGB_OFF,  RGB_OFF );

	// Update all entites
	for (uint8_t i = 0; i != entities.getSize(); i++)
		entities.get(i)->update();

	// Check for collision
	for (uint8_t i = 0; i != entities.getSize(); i++)
	{
		Entity* entity1 = entities.get(i);

		for (uint8_t j = i+1; j != entities.getSize(); j++)
		{
			Entity* entity2 = entities.get(j);

			if (arduboy.collide(entity1->getCollisionBox(), entity2->getCollisionBox()))
			{
				entity1->collideWith(entity2);
				entity2->collideWith(entity1);
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
	for (uint8_t i = 0; i != entities.getSize(); i++)
		entities.get(i)->draw();
}
