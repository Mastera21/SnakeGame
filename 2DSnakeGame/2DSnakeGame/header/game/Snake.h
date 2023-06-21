#pragma once

//C system headers

//C++ system headers
#include <list>
//Other libraries headers
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>

//Own components headers
 
//Forward declarations

enum Directions {
	RIGHT, LEFT, UP, DOWN
};

class Snake{
public:

	int32_t init();
	void deinit();
	void draw(const std::unique_ptr<sf::RenderWindow>& window);
	void handleEvent(const std::unique_ptr<sf::RenderWindow>& window);
	void buttonsEvent(sf::Event& e);

	bool collisionWithBody();

	std::list<sf::RectangleShape> getSnakeBody() const noexcept;
	uint32_t getSize() const noexcept;

	void setSize(uint32_t newSize);

private:
	void outOfBounds(const std::unique_ptr<sf::RenderWindow>& window);


private:
	sf::RectangleShape m_Shape;
	std::list<sf::RectangleShape> m_Body;

private:
	Directions dir{};

	uint32_t m_Size = 1;
	const uint32_t m_LenghtBody = 25;
};

