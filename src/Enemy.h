#pragma once

#include "Graph.h"
#include "Entity.h"

class Player;

class Enemy : public Entity
{
public:
	Enemy(int x, int y, sf::Vector2f home, sf::Vector2f target);
	
	void Move(sf::Vector2f movement);
	static bool CheckPositions(sf::Vector2f v1, sf::Vector2f v2);
	void SetPatrolParameters();
	void SetStandingParameters();
	void Script(Player player);
	void Update(sf::Time deltaTime);
	
	sf::CircleShape Body() const;
	void SetState(int x);
	int State() const;
	void SetSpeed(float velocity);
	sf::Vector2f Home() const;
	sf::Vector2f Target() const;
private:
	void AddEdge(int i, int j);
	void RemoveEdge(int i, int j);
	
	sf::CircleShape m_body;
	Graph m_behaviorGraph;
	int m_state;
	sf::Vector2f m_home;
	sf::Vector2f m_target;
	sf::Vector2f m_playerTarget;
	float m_speed;
};
