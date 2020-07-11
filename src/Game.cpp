#include "Game.h"
#include "Player.h"
#include "Light.h"
#include "Level.h"
#include "Wall.h"

Game::Game()
	: m_window(sf::VideoMode(640, 480), "Metal Shape Solid", sf::Style::Default, sf::ContextSettings(0, 0, 0))
{
	m_gameOver = false;
	m_wonLevel = false;
	m_paused = false;
	m_won = false;

	if (!m_font.loadFromFile("assets/ARCADECLASSIC.TTF"))
	{
		// Do nothing
	}

	m_gameOverText.setString("Game Over!");
	m_gameOverText.setFont(m_font);
	m_gameOverText.setCharacterSize(80);
	m_gameOverText.setPosition(100, 140);
	m_gameOverText.setColor(sf::Color::Red);
	m_wonLevelText.setString("Level Complete!");
	m_wonLevelText.setFont(m_font);
	m_wonLevelText.setCharacterSize(56);
	m_wonLevelText.setPosition(100, 150);
	m_wonLevelText.setColor(sf::Color::Red);
	m_promptReturn.setString("Press Return to Continue");
	m_promptReturn.setFont(m_font);
	m_promptReturn.setCharacterSize(32);
	m_promptReturn.setPosition(100, 240);
	m_promptReturn.setColor(sf::Color::Red);
	m_pausedText.setString(
		"Paused\nPress Return to Continue\nPress Q to Restart level\nPress M to go to the Title\nPress Esc to Quit");
	m_pausedText.setFont(m_font);
	m_pausedText.setCharacterSize(30);
	m_pausedText.setPosition(100, 120);
	m_pausedText.setColor(sf::Color::Red);
	m_pausedScreen.setPosition(0, 0);
	m_pausedScreen.setSize(sf::Vector2f(640, 480));
	m_pausedScreen.setFillColor(sf::Color(0, 0, 0, 180));
	m_wonText.setString("Congrats!\nYou won!");
	m_wonText.setFont(m_font);
	m_wonText.setCharacterSize(80);
	m_wonText.setPosition(130, 100);
	m_wonText.setColor(sf::Color::Red);
	m_promptWon.setString("Press M to go the Menu");
	m_promptWon.setFont(m_font);
	m_promptWon.setCharacterSize(30);
	m_promptWon.setPosition(130, 360);
	m_promptWon.setColor(sf::Color::Red);

	m_titleTexts = m_titleMenu.Texts();

	m_level.Init();
	m_player = m_level.player;
	m_walls = m_level.walls;
	m_enemies = m_level.enemies;
	m_doors = m_level.doors;
	m_buttons = m_level.buttons;
	m_lights = m_level.lights;
	m_winZone = m_level.winZone;
}

void Game::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);

	while (m_window.isOpen())
	{
		ProcessInput();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			ProcessInput();
			Update(timePerFrame);
		}
		Render();
	}
}

void Game::ProcessInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			HandlePlayerInput(event.key.code, true);
		}

		if (event.type == sf::Event::KeyReleased)
		{
			HandlePlayerInput(event.key.code, false);
		}
	}
}

void Game::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Escape)
	{
		m_window.close();
	}

	if (!m_gameOver && !m_wonLevel && !m_paused && !m_titleMenu.GetOnMenu() && !m_won)
	{
		if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
		{
			m_player.SetMovingUp(isPressed);
		}

		if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
		{
			m_player.SetMovingDown(isPressed);
		}

		if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
		{
			m_player.SetMovingLeft(isPressed);
		}

		if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		{
			m_player.SetMovingRight(isPressed);
		}

		if (key == sf::Keyboard::P)
		{
			m_paused = true;
		}

		if (key == sf::Keyboard::Space)
		{
			m_player.Swap();
		}
	}
	else if (m_gameOver)
	{
		if (key == sf::Keyboard::Return)
		{
			m_gameOver = false;
			m_level.Init();
			m_player = m_level.player;
			m_walls = m_level.walls;
			m_enemies = m_level.enemies;
			m_doors = m_level.doors;
			m_buttons = m_level.buttons;
			m_lights = m_level.lights;
			m_winZone = m_level.winZone;
		}
	}
	else if (m_paused)
	{
		if (key == sf::Keyboard::Return)
		{
			m_paused = false;
		}
		if (key == sf::Keyboard::Q)
		{
			m_paused = false;
			m_level.Init();
			m_player = m_level.player;
			m_walls = m_level.walls;
			m_enemies = m_level.enemies;
			m_doors = m_level.doors;
			m_buttons = m_level.buttons;
			m_lights = m_level.lights;
			m_winZone = m_level.winZone;
		}
		if (key == sf::Keyboard::M)
		{
			m_paused = false;
			m_titleMenu.SetOnMenu(true);
			m_titleMenu.SetScreen(0);
			m_titleTexts = m_titleMenu.Texts();
			m_level.stage = 0;
			m_level.Init();
			m_player = m_level.player;
			m_walls = m_level.walls;
			m_enemies = m_level.enemies;
			m_doors = m_level.doors;
			m_buttons = m_level.buttons;
			m_lights = m_level.lights;
			m_winZone = m_level.winZone;
		}
	}
	else if (m_titleMenu.GetOnMenu())
	{
		if (key == sf::Keyboard::Return && m_titleMenu.GetCooldown() == 0)
		{
			m_titleMenu.IncrementScreen();
			m_titleTexts = m_titleMenu.Texts();
			m_titleMenu.SetCooldown(40);
		}
	}
	else if (m_won)
	{
		if (key == sf::Keyboard::M)
		{
			m_won = false;
			m_titleMenu.SetOnMenu(true);
			m_titleMenu.SetScreen(0);
			m_titleTexts = m_titleMenu.Texts();
			m_level.stage = 0;
			m_level.Init();
			m_player = m_level.player;
			m_walls = m_level.walls;
			m_enemies = m_level.enemies;
			m_doors = m_level.doors;
			m_buttons = m_level.buttons;
			m_lights = m_level.lights;
			m_winZone = m_level.winZone;
		}
	}
	else
	{
		if (key == sf::Keyboard::Return)
		{
			m_wonLevel = false;
			m_level.Win();
			m_level.Init();
			m_player = m_level.player;
			m_walls = m_level.walls;
			m_enemies = m_level.enemies;
			m_doors = m_level.doors;
			m_buttons = m_level.buttons;
			m_lights = m_level.lights;
			m_winZone = m_level.winZone;
			if (m_level.stage == MAX_LEVEL)
			{
				m_won = true;
			}
		}
	}
}

void Game::Update(sf::Time deltaTime)
{
	if (m_titleMenu.GetOnMenu() && m_titleMenu.GetCooldown() > 0)
	{
		m_titleMenu.SetCooldown(m_titleMenu.GetCooldown() - 1);
	}
	if (!m_paused && !m_titleMenu.GetOnMenu() && !m_gameOver && !m_won && !m_wonLevel)
	{
		m_player.AdvanceCooldowns();
		sf::Vector2f movement(0.f, 0.f);
		if (m_player.IsMovingUp())
		{
			m_player.setVelocity(movement.x, movement.y - 70.f);
			movement = m_player.getVelocity();
		}
		if (m_player.IsMovingDown())
		{
			m_player.setVelocity(movement.x, movement.y + 70.f);
			movement = m_player.getVelocity();
		}
		if (m_player.IsMovingLeft())
		{
			m_player.setVelocity(movement.x - 70.f, movement.y);
			movement = m_player.getVelocity();
		}
		if (m_player.IsMovingRight())
		{
			m_player.setVelocity(movement.x + 70.f, movement.y);
			movement = m_player.getVelocity();
		}

		m_player.Move(movement * deltaTime.asSeconds());

		sf::Vector2f correctMove(0.f, 0.f);
		if (m_player.Body().getPosition().x < m_zone.body.getPosition().x ||
			m_player.Body().getPosition().x > m_zone.body.getPosition().x + 600)
		{
			correctMove.x = -1 * movement.x * deltaTime.asSeconds();
		}
		if (m_player.Body().getPosition().y < m_zone.body.getPosition().y ||
			m_player.Body().getPosition().y > m_zone.body.getPosition().y + 380)
		{
			correctMove.y = -1 * movement.y * deltaTime.asSeconds();
		}

		for (auto& m_wall : m_walls)
		{
			if (m_player.Body().getPosition().y + 20 > m_wall.body.getPosition().y &&
				m_player.Body().getPosition().y < m_wall.body.getPosition().y + m_wall.height)
			{
				if (m_player.Body().getPosition().x + 20 > m_wall.body.getPosition().x &&
					m_player.Body().getPosition().x < m_wall.body.getPosition().x + m_wall.width)
				{
					correctMove.x = -1 * movement.x * deltaTime.asSeconds();
				}
			}
			if (m_player.Body().getPosition().x + 20 > m_wall.body.getPosition().x &&
				m_player.Body().getPosition().x < m_wall.body.getPosition().x + m_wall.width)
			{
				if (m_player.Body().getPosition().y + 20 > m_wall.body.getPosition().y &&
					m_player.Body().getPosition().y < m_wall.body.getPosition().y + m_wall.height)
				{
					correctMove.y = -1 * movement.y * deltaTime.asSeconds();
				}
			}
		}

		for (auto& m_door : m_doors)
		{
			if (m_door.state)
			{
				if (m_player.Body().getPosition().y + 20 > m_door.body.getPosition().y &&
					m_player.Body().getPosition().y < m_door.body.getPosition().y + m_door.height)
				{
					if (m_player.Body().getPosition().x + 20 > m_door.body.getPosition().x &&
						m_player.Body().getPosition().x < m_door.body.getPosition().x + m_door.width)
					{
						correctMove.x = -1 * movement.x * deltaTime.asSeconds();
					}
				}

				if (m_player.Body().getPosition().x + 20 > m_door.body.getPosition().x &&
					m_player.Body().getPosition().x < m_door.body.getPosition().x + m_door.width)
				{
					if (m_player.Body().getPosition().y + 20 > m_door.body.getPosition().y &&
						m_player.Body().getPosition().y < m_door.body.getPosition().y + m_door.height)
					{
						correctMove.y = -1 * movement.y * deltaTime.asSeconds();
					}
				}
			}
		}

		m_player.Move(correctMove);

		for (auto& m_button : m_buttons)
		{
			if (m_button.state)
			{
				if (m_player.Body().getPosition().y + 20 > m_button.body.getPosition().y &&
					m_player.Body().getPosition().y < m_button.body.getPosition().y + m_button.height)
				{
					if (m_player.Body().getPosition().x + 20 > m_button.body.getPosition().x &&
						m_player.Body().getPosition().x < m_button.body.getPosition().x + m_button.width)
					{
						m_doors = m_button.OperateLinkedDoors(m_doors);
						m_button.SetState(false);
					}
				}
			}
			else
			{
				if (m_player.Body().getPosition().y + 20 < m_button.body.getPosition().y ||
					m_player.Body().getPosition().y > m_button.body.getPosition().y + m_button.height)
				{
					m_button.SetState(true);
				}
				if (m_player.Body().getPosition().x + 20 < m_button.body.getPosition().x ||
					m_player.Body().getPosition().x > m_button.body.getPosition().x + m_button.width)
				{
					m_button.SetState(true);
				}
			}
		}

		for (auto& m_light : m_lights)
		{
			if (m_player.IsInLight())
			{
				if (m_player.Body().getPosition().y + 20 < m_light.body.getPosition().y ||
					m_player.Body().getPosition().y > m_light.body.getPosition().y + m_light.height)
				{
					m_player.SetInLight(false);
				}
				if (m_player.Body().getPosition().x + 20 < m_light.body.getPosition().x ||
					m_player.Body().getPosition().x > m_light.body.getPosition().x + m_light.width)
				{
					m_player.SetInLight(false);
				}
			}
			if (m_player.Body().getPosition().y + 20 > m_light.body.getPosition().y &&
				m_player.Body().getPosition().y < m_light.body.getPosition().y + m_light.height)
			{
				if (m_player.Body().getPosition().x + 20 > m_light.body.getPosition().x &&
					m_player.Body().getPosition().x < m_light.body.getPosition().x + m_light.width)
				{
					m_player.SetInLight(true);
					break;
				}
			}
		}

		for (auto& m_enemies : m_enemies)
		{
			m_enemies.Script(m_player);
			m_enemies.Update(deltaTime);

			if (m_player.Body().getPosition().y + 20 > m_enemies.Body().getPosition().y &&
				m_player.Body().getPosition().y < m_enemies.Body().getPosition().y + 55)
			{
				if (m_player.Body().getPosition().x + 20 > m_enemies.Body().getPosition().x &&
					m_player.Body().getPosition().x < m_enemies.Body().getPosition().x + 55)
				{
					m_gameOver = true;
				}
			}
			if (m_player.Body().getPosition().x + 20 > m_enemies.Body().getPosition().x &&
				m_player.Body().getPosition().x < m_enemies.Body().getPosition().x + 55)
			{
				if (m_player.Body().getPosition().y + 20 > m_enemies.Body().getPosition().y &&
					m_player.Body().getPosition().y < m_enemies.Body().getPosition().y + 55)
				{
					m_gameOver = true;
				}
			}
		}
		if (m_player.Body().getPosition().y + 20 > m_winZone.Body().getPosition().y &&
			m_player.Body().getPosition().y < m_winZone.Body().getPosition().y + m_winZone.Height())
		{
			if (m_player.Body().getPosition().x + 20 > m_winZone.Body().getPosition().x &&
				m_player.Body().getPosition().x < m_winZone.Body().getPosition().x + m_winZone.Width())
			{
				if (m_level.stage >= 0 && m_level.stage < MAX_LEVEL)
				{
					m_wonLevel = true;
				}
			}
		}
	}
}

void Game::Render()
{
	m_window.clear();
	if (!m_gameOver && !m_wonLevel && !m_titleMenu.GetOnMenu() && !m_won)
	{
		m_window.draw(m_zone.body);
		for (auto& m_light : m_lights)
		{
			m_window.draw(m_light.body);
		}
		for (auto& m_wall : m_walls)
		{
			m_window.draw(m_wall.body);
		}
		for (auto& m_door : m_doors)
		{
			m_window.draw(m_door.body);
		}
		for (auto& m_button : m_buttons)
		{
			m_window.draw(m_button.body);
		}
		m_window.draw(m_winZone.Body());
		m_window.draw(m_player.Shadow());
		m_window.draw(m_player.ShadowBar());
		m_window.draw(m_player.Body());
		for (auto& m_enemies : m_enemies)
		{
			m_window.draw(m_enemies.Body());
		}
		if (m_paused)
		{
			m_window.draw(m_pausedScreen);
			m_window.draw(m_pausedText);
		}
	}
	if (m_titleMenu.GetOnMenu())
	{
		for (auto& m_titleText : m_titleTexts)
		{
			m_window.draw(m_titleText);
		}
	}
	if (m_gameOver)
	{
		m_window.draw(m_gameOverText);
		m_window.draw(m_promptReturn);
	}
	if (m_wonLevel)
	{
		m_window.draw(m_wonLevelText);
		m_window.draw(m_promptReturn);
	}
	if (m_won)
	{
		m_window.draw(m_wonText);
		m_window.draw(m_promptWon);
	}
	m_window.display();
}
