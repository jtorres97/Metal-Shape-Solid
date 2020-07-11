#include <cmath>

#include <SFML/Graphics.hpp>

#include "Enemy.h"
#include "Player.h"
#include "Graph.h"
#include "Constants.h"

Enemy::Enemy(int x, int y, sf::Vector2f home, sf::Vector2f target)
{
	m_body = sf::CircleShape(30, 12);
	m_body.setFillColor(sf::Color(255, 255, 255, 180));
	m_behaviorGraph = Graph(MAX_STATES);
	m_state = 0;
	m_speed = 80.f;

	m_body.setPosition(x, y);
	m_home = home;
	m_target = target;
}

void Enemy::Move(sf::Vector2f movement)
{
	m_body.move(movement);
}

void Enemy::AddEdge(int i, int j)
{
	m_behaviorGraph.AddEdge(i, j);
}

void Enemy::RemoveEdge(int i, int j)
{
	m_behaviorGraph.RemoveEdge(i, j);
}

sf::CircleShape Enemy::Body() const
{
	return m_body;
}

void Enemy::SetState(int x)
{
	m_state = x;
}

int Enemy::State() const
{
	return m_state;
}

void Enemy::Script(Player player)
{
	for (int j = 0; j < MAX_STATES; j++)
	{
		if (m_behaviorGraph.Edge(m_state, j) == 1)
		{
			if (j == 0)
			{
				if (CheckPositions(Body().getPosition(), Home()))
				{
					SetState(0);
				}
			}
			if (j == 1)
			{
				if (CheckPositions(Body().getPosition(), Home()))
				{
					SetState(1);
				}
			}
			if (j == 2 && player.IsInLight())
			{
				m_playerTarget = player.Body().getPosition();
				SetState(2);
			}
			if (j == 3)
			{
				if (CheckPositions(Body().getPosition(), Target()) ||
					CheckPositions(Body().getPosition(), m_playerTarget))
				{
					SetState(3);
				}
			}
		}
	}
}

void Enemy::Update(sf::Time deltaTime)
{
	sf::Vector2f direction;
	if (m_state == 0)
	{
		// Does not move in state 0
	}
	else
	{
		if (m_state == 1)
		{
			direction = m_target - m_body.getPosition();
		}
		if (m_state == 2)
		{
			direction = m_playerTarget - m_body.getPosition();
		}
		if (m_state == 3)
		{
			direction = m_home - m_body.getPosition();
		}
		direction = direction /
			sqrtf((direction.x * direction.x) + (direction.y * direction.y));
		direction.x = m_speed * direction.x;
		direction.y = m_speed * direction.y;
		Move(direction * deltaTime.asSeconds());
	}
}

sf::Vector2f Enemy::Home() const
{
	return m_home;
}

sf::Vector2f Enemy::Target() const
{
	return m_target;
}

void Enemy::SetSpeed(float velocity)
{
	m_speed = velocity;
}

bool Enemy::CheckPositions(sf::Vector2f v1, sf::Vector2f v2)
{
	for (auto i = -1; i < 2; i++)
	{
		for (auto j = -1; j < 2; j++)
		{
			if (static_cast<int>(v1.x) == static_cast<int>(v2.x) + i && static_cast<int>(v1.y) == static_cast<int>(v2.y)
				+ j)
			{
				return true;
			}
		}
	}
	return false;
}

void Enemy::SetPatrolParameters()
{
	SetState(1);
	AddEdge(1, 3);
	AddEdge(3, 1);
	AddEdge(1, 2);
	AddEdge(3, 2);
	AddEdge(2, 3);
	AddEdge(2, 2);
}

void Enemy::SetStandingParameters()
{
	SetState(0);
	AddEdge(3, 0);
	AddEdge(0, 2);
	AddEdge(3, 2);
	AddEdge(2, 3);
	AddEdge(2, 2);
}
