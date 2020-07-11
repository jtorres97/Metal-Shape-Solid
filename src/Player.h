#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player();

	void Move(sf::Vector2f movement);
	void AdvanceCooldowns();
	void Swap();
	
	void SetMovingUp(bool isPressed);
	void SetMovingDown(bool isPressed);
	void SetMovingLeft(bool isPressed);
	void SetMovingRight(bool isPressed);
	void SetInLight(bool l);
	bool IsMovingUp() const;
	bool IsMovingDown() const;
	bool IsMovingLeft() const;
	bool IsMovingRight() const;
	bool IsInLight() const;

	sf::CircleShape Body() const;
	sf::CircleShape Shadow() const;
	sf::RectangleShape ShadowBar() const;
private:
	sf::CircleShape m_body;
	sf::CircleShape m_shadow;
	sf::RectangleShape m_shadowBar;
	float m_shadowCooldown;
	bool m_movingUp;
	bool m_movingDown;
	bool m_movingLeft;
	bool m_movingRight;
	bool m_inLight;
};
