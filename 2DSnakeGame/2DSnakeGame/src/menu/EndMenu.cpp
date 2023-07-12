#include "../../header/menu/EndMenu.h"

//C system headers

//C++ system headers
#include <iostream> 
//Other libraries headers
#include "../../manager/header/TextWidget.h"
//Own components headers


int32_t EndMenu::init(const std::unique_ptr<sf::RenderWindow>& window) {
	m_NumButtons = 1;
	m_NumTextWidgets = 4;

	m_Buttons.resize(m_NumButtons);
	m_TextWidgets.resize(m_NumTextWidgets);

	if (EXIT_SUCCESS != m_TextWidgets[0].init("Roboto-BoldItalic.ttf", "Thank you for playing!", 40, sf::Color::White, sf::Vector2f(window->getSize().x / 2 - 200.f, window->getSize().y / 2 - 210.f))) {
		std::cerr << "TextWidget.init() failed.\n";
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != m_TextWidgets[1].init("Roboto-BoldItalic.ttf", "Total Score is:", 30, sf::Color::White, sf::Vector2f(window->getSize().x / 2 - 120.f, window->getSize().y / 2 - 125.f))) {
		std::cerr << "TextWidget.init() failed.\n";
		return EXIT_FAILURE;
	}
	
	if (EXIT_SUCCESS != m_TextWidgets[2].init("Roboto-BoldItalic.ttf", "", 30, sf::Color::White, sf::Vector2f(window->getSize().x / 2 + 90.f, window->getSize().y / 2 - 125.f))) {
		std::cerr << "TextWidget.init() failed.\n";
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != m_TextWidgets[3].init("Roboto-BoldItalic.ttf", "Made By: Mastera21/Svetoslav", 20, sf::Color::White, sf::Vector2f(window->getSize().x / 2 - 130, window->getSize().y - 40))) {
		std::cerr << "TextWidget.init() failed.\n";
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != m_Buttons[0].init("Roboto-BoldItalic.ttf", "Exit", sf::Vector2f(100.f, 40.f), 25, sf::Color::White, sf::Color::Black)) {
		std::cerr << "Button.init() failed.\n";
		return EXIT_FAILURE;
	}
	m_Buttons[0].setPos(sf::Vector2f(window->getSize().x / 2 - 50.f, window->getSize().y / 2 + 50.f));


	return EXIT_SUCCESS;
}
void EndMenu::deinit() {
	m_TextWidgets.clear();
	m_Buttons.clear();
}
void EndMenu::draw(const std::unique_ptr<sf::RenderWindow>& window, const std::string& socre) {
	m_TextWidgets[2].setTitleName(socre);

	for (auto& i : m_TextWidgets) {
		i.draw(window);
	}

	for (auto& i : m_Buttons) {
		i.draw(window);
	}
}
void EndMenu::handleEvent(const std::unique_ptr<sf::RenderWindow>& window, bool& exitButton) {
	if (m_Buttons[0].isMouseHover(window)) {
		m_Buttons[0].setBackColor(sf::Color::Green);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			exitButton = true;
		}
	}else {
		m_Buttons[0].setBackColor(sf::Color::White);
	}
}