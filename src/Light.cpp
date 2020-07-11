#include <SFML/Graphics.hpp>

#include "Light.h"

Light::Light(int x, int y, int w, int h)
{
	body.setFillColor(sf::Color(180, 180, 20, 255));
	body.setOutlineColor(sf::Color(140, 140, 14, 255));
	body.setOutlineThickness(5);

	body.setPosition(x, y);
	width = w;
	height = h;
	body.setSize(sf::Vector2f(w, h));
}
