#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public:
	void setVelocity(sf::Vector2f v);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
private:
	sf::Vector2f m_velocity;
};