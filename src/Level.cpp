#include "Level.hpp"

#include "entity/Booster.hpp"
#include "generated/levels.h"
#include "data/bitmaps.h"
#include "globals.h"

Level::Level(const uint8_t *levelData, const uint8_t *entitiesData)
	: levelData(levelData)
	, width(pgm_read_byte(levelData))
{
	uint8_t size = pgm_read_byte(entitiesData);

	entities = new DArray<Entity *>(size);

	uint8_t* currentAddress = entitiesData+1;

	for (uint8_t i = 0; i != size; i++)
	{
		uint8_t entityType = pgm_read_byte(currentAddress++);

		switch (entityType)
		{
		case ENT_BOOSTER:
			Booster* booster = new Booster();
			booster->x = pgm_read_byte(currentAddress++);
			booster->y = pgm_read_byte(currentAddress++);
			entities->add(booster);
			break;
		}
	}
}

void Level::draw() const
{
	uint16_t startTileX = divideBy8(startX);
	uint8_t shiftX = modulo8(startX);
	uint8_t *currentAddr = levelData + 2 + multiplyBy8(startTileX);

	for (uint8_t x= 0; x != 17; x++)
	{
		for (uint8_t y= 0; y != 8; y++)
		{
			uint8_t tile = pgm_read_byte(currentAddr++);

			Sprites::drawSelfMasked(x*8 - shiftX, y * 8, tiles, tile);
		}
	}
}

void Level::update()
{
	// Stop level scrolling
	if (divideBy8(startX) + 16 != width)
		startX++;

	for (uint8_t i = 0; i != entities->getSize(); i++)
	{
		Entity* entity = entities->get(i);

		if (entity->x >= startX && entity->x < startX+128)
		{
			game.spawnEntity(entity);
			entities->removeAt(i--);
		}
	}
}


bool Level::collide(Rect collisionBox) const
{
	uint16_t startTileX = divideBy8(collisionBox.x);
	uint16_t startTileY = divideBy8(collisionBox.y);
	uint16_t stopTileX = divideBy8(collisionBox.x + collisionBox.width - 1);
	uint16_t stopTileY = divideBy8(collisionBox.y+ collisionBox.height -1 );

	for (uint16_t x = startTileX; x <= stopTileX; x++)
		for (uint16_t y = startTileY; y <= stopTileY; y++)
		{
			uint8_t tile = pgm_read_byte(levelData + 2 + startX +  multiplyBy8(x) + y);

			if (tile == 4)
				return true;
		}

	return false;
}
