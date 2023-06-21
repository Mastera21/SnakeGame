#pragma once
//C system headers

//C++ system headers
#include <vector>
//Other libraries headers
#include "SFML/Graphics/RenderWindow.hpp"

//Own components headers
#include "../button/Button.h"
#include "../../manager/header/TextWidget.h"

#include "../../interfaces/score/ScoreInterface.h"

//Forward declarations

class EndMenu {
public:
	EndMenu(ScoreInterface* scoreInterface) : m_ScoreInterface(scoreInterface) {}

	int32_t init(const std::unique_ptr<sf::RenderWindow>& window);
	void deinit();
	void draw(const std::unique_ptr<sf::RenderWindow>& window);
	void handleEvent(const std::unique_ptr<sf::RenderWindow>& window, bool& exitButton);

private:
	std::vector<TextWidget> m_TextWidgets;
	std::vector<Button> m_Buttons;

	ScoreInterface* m_ScoreInterface;

	int32_t m_NumButtons;
	int32_t m_NumTextWidgets;
};

