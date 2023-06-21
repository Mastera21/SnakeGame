#include "../../header/button/Button.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Button::init(std::string path, std::string text, sf::Vector2f size, int textSize, sf::Color bgColor, sf::Color textColor) {
	if (!m_Font.loadFromFile(path)) {
		std::cerr << "Cannot open font for file -> Button::init()\n";
	}

	m_Text.setString(text);
	m_Text.setCharacterSize(textSize);
	m_Text.setFont(m_Font);
	m_Text.setFillColor(textColor);
	m_Button.setSize(size);
	m_Button.setFillColor(bgColor);

	return EXIT_SUCCESS;
}

void Button::setBackColor(sf::Color color) {
	m_Button.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
	m_Text.setFillColor(color);
}

void Button::setPos(sf::Vector2f pos) {
	m_Button.setPosition(pos);

	float xPos = (pos.x + m_Button.getLocalBounds().width / 2) - (m_Text.getLocalBounds().width / 2);
	float yPos = (pos.y + m_Button.getLocalBounds().height / 2 - 9) - (m_Text.getLocalBounds().height / 2);
	m_Text.setPosition(sf::Vector2f(xPos, yPos));
}

void Button::draw(const std::unique_ptr<sf::RenderWindow>& window) {
	window->draw(m_Button);
	window->draw(m_Text);
}
	 
bool Button::isMouseHover(const std::unique_ptr<sf::RenderWindow>& window) {
	float mouseX = sf::Mouse::getPosition(*window).x;
	float mouseY = sf::Mouse::getPosition(*window).y;

	float btnPosX = m_Button.getPosition().x;
	float btnPosY = m_Button.getPosition().y;

	float btnxPosWidth = m_Button.getPosition().x + m_Button.getLocalBounds().width;
	float btnyPosHeight = m_Button.getPosition().y + m_Button.getLocalBounds().height;

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
		return true;
	}
	return false;
}