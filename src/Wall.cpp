#include "Wall.h"

Wall::Wall(int x, int y, int w, int h)
{
	body.setFillColor(sf::Color(200,0,0,255));
	
	body.setPosition(x, y);
	width = w;
	height = h;
	body.setSize(sf::Vector2f(w, h));

}