#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "entity/Entity.hpp"
#include "utils/DArray.hpp"

class Level {
private:
	DArray<Entity *> entities;

public:
	Level(const uint8_t *levelData, const uint8_t *entitiesData);

};

#endif
