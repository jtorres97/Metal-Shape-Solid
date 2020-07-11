#include "Door.h"
#include "Constants.h"

static sf::Color closed = sf::Color(100, 0, 80, 255);
static sf::Color opened = sf::Color(100, 0, 80, 80);

Door::Door(int x, int y, int w, int h)
{
	body.setFillColor(closed);
	body.setOutlineColor(closed);
	body.setOutlineThickness(1);
	state = true;

	body.setPosition(x, y);
	width = w;
	height = h;
	body.setSize(sf::Vector2f(w, h));
}

void Door::SetState(bool setting)
{
	state = setting;
	if (state)
	{
		body.setFillColor(closed);
	}
	else
	{
		body.setFillColor(opened);
	}
}

void Door::Toggle()
{
	if (state)
	{
		SetState(false);
	}
	else
	{
		SetState(true);
	}
}

DoorButton::DoorButton(int x, int y, int w, int h)
{
	body.setFillColor(sf::Color(255, 255, 255, 255));
	state = true;
	for (auto& operation : operations)
	{
		operation = 0;
	}

	body.setPosition(x, y);
	width = w;
	height = h;
	body.setSize(sf::Vector2f(w, h));
}

void DoorButton::SetState(bool setting)
{
	state = setting;
}

std::vector<Door> DoorButton::OperateLinkedDoors(std::vector<Door> doors)
{
	int count = 0;
	for (std::vector<Door>::iterator it = doors.begin(); it != doors.end(); ++it)
	{
		if (operations[count] == 0)
		{
			it->Toggle();
		}
		else if (operations[count] == 1)
		{
			//leave the door as is
		}
		else if (operations[count] == 2)
		{
			it->SetState(false);
		}
		else if (operations[count] == 3)
		{
			it->SetState(true);
		}
		count++;
	}
	return doors;
}

void DoorButton::SetOperation(int i, int j)
{
	if (i >= 0 && i < MAX_DOORS)
	{
		operations[i] = j;
	}
}
