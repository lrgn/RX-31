#ifndef GAME_HPP
#define GAME_HPP

#include "utils/DArray.hpp"
#include "entity/Entity.hpp"

#define ENTITIES_MAX_SIZE 20

class Game
{
private:
	DArray<Entity *> entities;

public:
	Game();
	void spawnEntity(Entity* entity);
	void update();
	void draw() const;
};

#endif
