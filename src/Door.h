#pragma once

#include "Entity.h"
#include "Constants.h"

struct Door : Entity
{
	Door(int x, int y, int w, int h);

	void SetState(bool setting);
	void Toggle();

	bool state;
	sf::RectangleShape body;
	int width;
	int height;
};

struct DoorButton : Entity
{
	DoorButton(int x, int y, int w, int h);
	
	void SetState(bool setting);
	std::vector<Door> OperateLinkedDoors(std::vector<Door> doors);
	void SetOperation(int i, int j);

	sf::RectangleShape body;
	int width;
	int height;
	int operations[MAX_DOORS];
	bool state;
};
