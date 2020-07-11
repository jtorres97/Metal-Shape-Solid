#pragma once

#include "Enemy.h"
#include "Door.h"
#include "Wall.h"
#include "Light.h"
#include "Zone.h"
#include "Player.h"

struct Level
{
	Level();
	
	void Init();
	void Win();

	int stage;
	Player player;
	std::vector<Wall> walls;
	std::vector<Enemy> enemies;
	std::vector<Door> doors;
	std::vector<DoorButton> buttons;
	std::vector<Light> lights;
	WinZone winZone;
};
