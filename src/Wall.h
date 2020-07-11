#pragma once

#include "Entity.h"

struct Wall : Entity
{
	Wall(int x, int y, int w, int h);
	
	sf::RectangleShape body;
	int width;
	int height;
};
