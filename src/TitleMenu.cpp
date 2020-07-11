#include "TitleMenu.h"

#include <SFML/Graphics.hpp>

TitleMenu::TitleMenu()
{
	m_onMenu = true;
	m_screen = 0;
	m_cooldown = 0;
	SetTexts();
	if (!m_font.loadFromFile("assets/ARCADECLASSIC.TTF"))
	{
		// Do nothing
	}
}

void TitleMenu::SetTexts()
{
	m_texts.clear();
	if (m_screen == 0)
	{
		sf::Text title0;
		title0.setString("Metal Shape");
		title0.setFont(m_font);
		title0.setCharacterSize(80);
		title0.setPosition(80,50);
		title0.setColor(sf::Color::Red);

		sf::Text title1;
		title1.setString("Solid");
		title1.setFont(m_font);
		title1.setCharacterSize(80);
		title1.setPosition(200, 150);
		title1.setColor(sf::Color::Red);

		sf::Text enterPrompt;
		enterPrompt.setString("Press Enter to Begin");
		enterPrompt.setFont(m_font);
		enterPrompt.setCharacterSize(20);
		enterPrompt.setPosition(200,400);
		enterPrompt.setColor(sf::Color::Red);

		m_texts.push_back(title0);
		m_texts.push_back(title1);
		m_texts.push_back(enterPrompt);
	}
	
	else
	{
		SetOnMenu(false);
	}
}

std::vector<sf::Text> TitleMenu::Texts() const
{
	return m_texts;
}

void TitleMenu::SetScreen(int x)
{
	m_screen = x;
	SetTexts();
}

void TitleMenu::IncrementScreen()
{
	++m_screen;
	SetTexts();
}

void TitleMenu::SetOnMenu(bool b)
{
	m_onMenu = b;
}

bool TitleMenu::GetOnMenu() const
{
	return m_onMenu;
}

int TitleMenu::GetCooldown() const
{
	return m_cooldown;
}

void TitleMenu::SetCooldown(int x)
{
	m_cooldown = x;
}