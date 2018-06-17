#include "Level.hpp"

#include "entity/Booster.hpp"
#include "generated/levels.h"

Level::Level(const uint8_t *levelData, const uint8_t *entitiesData)
	: entities(pgm_read_byte(entitiesData))
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
