#pragma once

#include <SFML/Graphics.hpp>

#include "Door.h"
#include "Enemy.h"
#include "Level.h"
#include "Zone.h"
#include "Wall.h"
#include "Light.h"
#include "TitleMenu.h"
#include "Player.h"

class Game
{
public:
	Game();
	
	void Run();
private:
	void ProcessInput();
	void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void Update(sf::Time deltaTime);
	void Render();
	
	sf::RenderWindow m_window;
	
	bool m_gameOver;
	bool m_wonLevel;
	bool m_paused;
	bool m_won;

	sf::Text m_gameOverText;
	sf::Text m_wonLevelText;
	sf::Text m_promptReturn;
	sf::Text m_pausedText;
	sf::RectangleShape m_pausedScreen;
	sf::Text m_wonText;
	sf::Text m_promptWon;
	
	Player m_player;
	Zone m_zone;
	WinZone m_winZone;

	Level m_level;
	std::vector<Wall> m_walls;
	std::vector<Enemy> m_enemies;
	std::vector<Door> m_doors;
	std::vector<DoorButton> m_buttons;
	std::vector<Light> m_lights;
	sf::Font m_font;

	TitleMenu m_titleMenu;
	std::vector<sf::Text> m_titleTexts;
};
