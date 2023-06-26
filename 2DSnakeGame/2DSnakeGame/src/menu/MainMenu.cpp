#include "../../header/menu/MainMenu.h"

//C system headers

//C++ system headers
#include <iostream> 
//Other libraries headers
#include "../../manager/header/TextWidget.h"
//Own components headers

int32_t MainMenu::init(const std::unique_ptr<sf::RenderWindow>& window) {

	m_NumButtons = 2;

	m_Buttons.resize(m_NumButtons);

	if (EXIT_SUCCESS != m_TitleText.init("Roboto-BoldItalic.ttf", "Snake Game!", 45, sf::Color::White, sf::Vector2f(window->getSize().x / 2 - 130.f, window->getSize().y / 2 - 200.f))) {
		std::cerr << "TextWidget::Init() failed.\n";
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != m_Buttons[0].init("Roboto-BoldItalic.ttf", "Start", sf::Vector2f(100.f, 40.f), 25, sf::Color::White, sf::Color::Black)) {
		std::cerr << "m_Start.init() failed.\n";
		return EXIT_FAILURE;
	}
	m_Buttons[0].setPos(sf::Vector2f(window->getSize().x / 2 - 50.f, window->getSize().y / 2 - 50.f));

	if (EXIT_SUCCESS != m_Buttons[1].init("Roboto-BoldItalic.ttf", "Exit", sf::Vector2f(100.f, 40.f), 25, sf::Color::White, sf::Color::Black)) {
		std::cerr << "m_Start.init() failed.\n";
		return EXIT_FAILURE;
	}
	m_Buttons[1].setPos(sf::Vector2f(window->getSize().x / 2 - 50.f, window->getSize().y / 2.f));


	return EXIT_SUCCESS;
}

void MainMenu::deinit() {
	m_Buttons.clear();
}

void MainMenu::handleEvent(const std::unique_ptr<sf::RenderWindow>& window, bool& isStartButtonPressed, bool& exitButton) {
	for (auto& button : m_Buttons) {
		if (button.isMouseHover(window)) {
			button.setBackColor(sf::Color::Green);
			if (button.equalTitle("Start") && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				isStartButtonPressed = true;
			}else if (button.equalTitle("Exit") && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				exitButton = true;
			}
		} else {
			button.setBackColor(sf::Color::White);
		}
	}
}

void MainMenu::draw(const std::unique_ptr<sf::RenderWindow>& window) {
	m_TitleText.draw(window);

	for (auto& i : m_Buttons) {
		i.draw(window);
	}
}
