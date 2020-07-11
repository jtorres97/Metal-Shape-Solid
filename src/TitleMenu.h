#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

class TitleMenu
{
public:
	TitleMenu();
	
	void SetTexts();
	std::vector<sf::Text> Texts() const;
	void SetScreen(int x);
	void IncrementScreen();
	void SetOnMenu(bool b);
	bool GetOnMenu() const;
	int GetCooldown() const;
	void SetCooldown(int x);
private:
	bool m_onMenu;
	int m_screen;
	std::vector<sf::Text> m_texts;
	sf::Font m_font;
	int m_cooldown;
};
