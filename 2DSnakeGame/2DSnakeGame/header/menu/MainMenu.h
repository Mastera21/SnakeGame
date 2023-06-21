#pragma once

//C system headers

//C++ system headers
#include <vector>

//Other libraries headers
#include "SFML/Window/Event.hpp"

//Own components headers
#include "../button/Button.h"
#include "../../manager/header/TextWidget.h"
//Forward declarations

class MainMenu{
public:
	int32_t init(const std::unique_ptr<sf::RenderWindow>& window);
	void deinit();
	void handleEvent(const std::unique_ptr<sf::RenderWindow>& window, bool& isStartButtonPressed, bool& exitButton);
	void draw(const std::unique_ptr<sf::RenderWindow>& window);

private:
	TextWidget m_TitleText;

private:
	std::vector<Button> m_Buttons;
	int32_t m_NumButtons;

};

