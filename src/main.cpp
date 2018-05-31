#include <Arduboy2.h>
#include "Player.hpp"
#include "Missile.hpp"
#include "DArray.hpp"

Arduboy2 arduboy;
Player player;
DArray<Entity *> entities(10);

void setup()
{
	arduboy.begin();
	arduboy.setFrameRate(60);
	entities.add(&player);
}

void loop()
{
	if (!(arduboy.nextFrame()))
		return;

	if (arduboy.pressed(LEFT_BUTTON) && player.x != 0)
		player.x--;
	if (arduboy.pressed(RIGHT_BUTTON) && player.x != 120)
		player.x++;
	if (arduboy.pressed(UP_BUTTON) && player.y != 0)
		player.y--;
	if (arduboy.pressed(DOWN_BUTTON) && player.y != 56)
		player.y++;
	if (arduboy.pressed(A_BUTTON)) {
		Missile* missile = new Missile();
		missile->x = player.x + 8;
		missile->y = player.y + 4;
		if (!entities.add(missile))
			delete missile;
	}

	arduboy.clear();

	for (uint8_t i = 0; i != entities.getSize(); i++)
		entities.get(i)->update();
	for (uint8_t i = 0; i != entities.getSize(); i++)
		entities.get(i)->draw();

	arduboy.display();
}
