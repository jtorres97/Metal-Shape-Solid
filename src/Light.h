#pragma once

#include "Entity.h"

struct Light : Entity
{
	Light(int x, int y, int w, int h);

	sf::RectangleShape body;
	int width;
	int height;
};