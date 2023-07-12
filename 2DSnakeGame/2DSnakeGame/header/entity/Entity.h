#pragma once

//C system headers

//C++ system headers
 
//Other libraries headers
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
//Own components headers
#include "../game/Snake.h"
//Forward declarations

class Entity{
public:
	Entity(const sf::Vector2f& size, const sf::Color& color);
	virtual ~Entity() = default;

	virtual void draw(const std::unique_ptr<sf::RenderWindow>& window);
	virtual void update(Snake& snake, int& snakeSpeed) = 0;

	sf::Vector2f getPos();
	sf::RectangleShape getBody();
	sf::Vector2f getSize();

	void setPos(const sf::Vector2f& newPos);
	void setSize(const sf::Vector2f& newSize);

	void setFillCol(const sf::Color& newColor);

private:
	sf::RectangleShape m_Body; 

};

