#include "../../manager/header/TextWidget.h"

//C system headers

//C++ system headers
#include <iostream> 
//Other libraries headers

//Own components headers

int32_t TextWidget::init(const std::string& fileFontName, const std::string& titleName, uint32_t fontSize, const sf::Color& color, const sf::Vector2f& pos) {
	if (!m_Font.loadFromFile(fileFontName)) {
		std::cout << "Cannot open font for file -> TextWidget::init()\n";
		return EXIT_FAILURE;
	}

	m_Title.setString(titleName);
	m_Title.setCharacterSize(fontSize);
	m_Title.setFont(m_Font);
	m_Title.setFillColor(color);
	m_Title.setPosition(pos);

	return EXIT_SUCCESS;
}
void TextWidget::draw(const std::unique_ptr<sf::RenderWindow>& window) {
	window->draw(m_Title);
}

std::string TextWidget::getTitleName() const noexcept {
	return m_Title.getString();
}
uint32_t TextWidget::getSize() const noexcept {
	return m_Title.getCharacterSize();
}
sf::Color TextWidget::getColor() const noexcept {
	return m_Title.getFillColor();
}
sf::Vector2f TextWidget::getPos() const noexcept {
	return m_Title.getPosition();
}

void TextWidget::setTitleName(const std::string& newTitleName) {
	m_Title.setString(newTitleName);
}
void TextWidget::setSize(uint32_t newSize) {
	m_Title.setCharacterSize(newSize);
}
void TextWidget::setColor(const sf::Color& newColor) {
	m_Title.setFillColor(newColor);
}
void TextWidget::setPos(const sf::Vector2f& newPos) {
	m_Title.setPosition(newPos);
}
