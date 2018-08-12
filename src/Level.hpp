#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "entity/Entity.hpp"
#include "utils/DArray.hpp"

class Level
{
private:
	uint8_t* levelData;
	uint8_t width;
	DArray<Entity *> entities;
	uint16_t startX = 0;

public:
	Level(const uint8_t *levelData, const uint8_t *entitiesData);

	void draw() const;
	void update();
};

#endif
