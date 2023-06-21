#pragma once

//C system headers

//C++ system headers

//Other libraries headers
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"

//Own components headers

//Forward declarations

class TextWidget{
public:

	int32_t init(const std::string& fileFontName, const std::string& titleName, uint32_t fontSize, const sf::Color& color, const sf::Vector2f& pos);
	void draw(const std::unique_ptr<sf::RenderWindow>& window);

	std::string getTitleName() const noexcept;
	uint32_t getSize() const noexcept;
	sf::Color getColor() const noexcept;
	sf::Vector2f getPos() const noexcept;

	void setTitleName(const std::string& newTitleName);
	void setSize(uint32_t newSize);
	void setColor(const sf::Color& newColor);
	void setPos(const sf::Vector2f& newPos);

private:
	sf::Text m_Title;
	sf::Font m_Font;

};

