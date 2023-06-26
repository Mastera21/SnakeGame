#pragma once

//C system headers

//C++ system headers

//Other libraries headers
#include <SFML/Graphics.hpp>
//Own components headers

//Forward declarations

class Button{
public:

	int32_t init(std::string path, std::string text, sf::Vector2f size, int textSize, sf::Color bgColor, sf::Color textColor);
	void setBackColor(sf::Color color);
	void setTextColor(sf::Color color);
	void setPos(sf::Vector2f pos);
	void draw(const std::unique_ptr<sf::RenderWindow>& window);

	bool isMouseHover(const std::unique_ptr<sf::RenderWindow>& window);
	bool equalTitle(const std::string& titleName);

	inline std::string getTitleName() const noexcept;

private:
	sf::RectangleShape m_Button;
	sf::Text m_Text;
	sf::Font m_Font;

private:
	std::string m_TitleName;

};

