#pragma once

#include "Entity.h"

struct Zone : Entity
{
	Zone();

	sf::RectangleShape body;
};

class WinZone : public Entity
{
public:
	WinZone();

	void Init(int x, int y, int w, int h);
	sf::RectangleShape Body();
	int Width();
	int Height();
private:
	sf::RectangleShape m_body;
	int m_width;
	int m_height;
};
