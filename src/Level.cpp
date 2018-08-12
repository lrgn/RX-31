#include "Level.hpp"

#include "entity/Booster.hpp"
#include "generated/levels.h"
#include "data/bitmaps.h"
#include "globals.h"

Level::Level(const uint8_t *levelData, const uint8_t *entitiesData)
	: levelData(levelData)
	, width(pgm_read_byte(levelData))
	,entities(pgm_read_byte(entitiesData))
{
	uint8_t* currentAddress = entitiesData;

	for (uint8_t i = 0; i != entities.getSize(); i++)
	{
		uint8_t entityType = pgm_read_byte(currentAddress++);

		switch (entityType)
		{
		case ENT_BOOSTER:
			Booster* booster = new Booster();
			booster->x = pgm_read_byte(currentAddress++);
			booster->y = pgm_read_byte(currentAddress++);
			entities.add(booster);
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
}
