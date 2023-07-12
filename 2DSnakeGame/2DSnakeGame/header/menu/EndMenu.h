#pragma once
//C system headers

//C++ system headers
#include <vector>
//Other libraries headers
#include "SFML/Graphics/RenderWindow.hpp"

//Own components headers
#include "../button/Button.h"
#include "../../manager/header/TextWidget.h"

//Forward declarations

class EndMenu {
public:
	EndMenu() = default;

	int32_t init(const std::unique_ptr<sf::RenderWindow>& window);
	void deinit();
	void draw(const std::unique_ptr<sf::RenderWindow>& window, const std::string& socre);
	void handleEvent(const std::unique_ptr<sf::RenderWindow>& window, bool& exitButton);

private:
	std::vector<TextWidget> m_TextWidgets;
	std::vector<Button> m_Buttons;

	int32_t m_NumButtons;
	int32_t m_NumTextWidgets;
};

