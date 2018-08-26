#include <Arduboy2.h>
#include "entity/Player.hpp"
#include "entity/BurgerShip.hpp"
#include "entity/Booster.hpp"
#include "Game.hpp"

#define PLAYER_VELOCITY 1.2


Arduboy2 arduboy;
Game game;

void setup()
{
	//Serial.begin(9600);
	arduboy.begin();
	arduboy.setFrameRate(60);

	Player* player = new Player();
	player->resetVelocity();
	game.spawnEntity(player);
}

void loop()
{
	if (!(arduboy.nextFrameDEV()))
		return;

	arduboy.pollButtons();
	game.update();

	arduboy.clear();
	game.draw();
	arduboy.display();
}
