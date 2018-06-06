#include <Arduboy2.h>
#include "Player.hpp"
#include "BurgerShip.hpp"
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

	BurgerShip* burg = new BurgerShip();
	burg->x = 120;
	burg->y = 28;
	game.spawnEntity(burg);
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
