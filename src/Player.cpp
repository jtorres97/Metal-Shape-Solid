#include "Player.h"

Player::Player()
{
	m_body.setRadius(10.f);
	m_body.setPosition(16, 200);
	m_body.setFillColor(sf::Color(0, 250, 250, 255));
	m_body.setOutlineColor(sf::Color::White);
	m_body.setOutlineThickness(1);
	m_shadow.setRadius(10.f);
	m_shadow.setPosition(16, 200);
	m_shadow.setFillColor(sf::Color(10, 10, 10, 255));
	m_shadow.setOutlineColor(sf::Color::White);
	m_shadow.setOutlineThickness(1);
	m_shadowCooldown = 0;

	m_shadowBar.setPosition(10, 430);
	m_shadowBar.setSize(sf::Vector2f(620, 20));
	m_shadowBar.setFillColor(sf::Color(70, 70, 70, 255));
	m_shadowBar.setOutlineColor(sf::Color::White);
	m_shadowBar.setOutlineThickness(1);

	m_movingUp = false;
	m_movingDown = false;
	m_movingLeft = false;
	m_movingRight = false;
	m_inLight = false;
}

void Player::Move(sf::Vector2f movement)
{
	m_body.move(movement);
}

sf::CircleShape Player::Body() const
{
	return m_body;
}

sf::CircleShape Player::Shadow() const
{
	return m_shadow;
}

sf::RectangleShape Player::ShadowBar() const
{
	return m_shadowBar;
}

void Player::AdvanceCooldowns()
{
	if (m_shadowCooldown > 0)
	{
		m_shadowCooldown--;
		m_shadowBar.setSize(sf::Vector2f(620 - 620 * (m_shadowCooldown / 200), 20));
	}
}

void Player::Swap()
{
	if (m_shadowCooldown == 0 && !m_inLight)
	{
		float x = m_shadow.getPosition().x;
		float y = m_shadow.getPosition().y;
		m_shadow.setPosition(m_body.getPosition().x, m_body.getPosition().y);
		m_body.setPosition(x, y);
		m_shadowCooldown = 200;
		m_shadowBar.setSize(sf::Vector2f(0, 20));
	}
}

void Player::SetMovingUp(bool isPressed)
{
	m_movingUp = isPressed;
}

void Player::SetMovingDown(bool isPressed)
{
	m_movingDown = isPressed;
}

void Player::SetMovingLeft(bool isPressed)
{
	m_movingLeft = isPressed;
}

void Player::SetMovingRight(bool isPressed)
{
	m_movingRight = isPressed;
}

void Player::SetInLight(bool l)
{
	m_inLight = l;
}

bool Player::IsMovingUp() const
{
	return m_movingUp;
}

bool Player::IsMovingDown() const
{
	return m_movingDown;
}

bool Player::IsMovingLeft() const
{
	return m_movingLeft;
}

bool Player::IsMovingRight() const
{
	return m_movingRight;
}

bool Player::IsInLight() const
{
	return m_inLight;
}
