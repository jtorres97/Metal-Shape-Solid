#include "Zone.h"

Zone::Zone()
{
	body.setSize(sf::Vector2f(620,400));
	body.setOutlineColor(sf::Color(200,0,0,255));
	body.setFillColor(sf::Color::Black);
	body.setOutlineThickness(5);
	body.setPosition(10,10);
}

WinZone::WinZone()
{
	m_body.setFillColor(sf::Color(0, 90, 180, 255));
	Init(620, 200, 10, 20);
}

void WinZone::Init(int x, int y, int w, int h)
{
	m_body.setPosition(x, y);
	m_width = w;
	m_height = h;
	m_body.setSize(sf::Vector2f(w, h));
}

sf::RectangleShape WinZone::Body()
{
	return m_body;
}

int WinZone::Width()
{
	return m_width;
}

int WinZone::Height()
{
	return m_height;
}