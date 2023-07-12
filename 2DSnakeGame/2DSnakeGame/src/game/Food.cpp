#include "../../header/game/Food.h"

//C system headers

//C++ system headers
#include <iostream>
#include <random>
//Other libraries headers

//Own components headers

Food::Food() : Entity(sf::Vector2f(0.0f, 0.0f), sf::Color::Black) {}

Food::Food(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& color) : Entity(size, color) {

	Entity::setSize(size);
	Entity::setFillCol(color);

	m_FoodX = pos.x;
	m_FoodY = pos.y;

	m_Score = 0;

	Entity::setPos(sf::Vector2f(m_FoodX, m_FoodY));
}

void Food::draw(const std::unique_ptr<sf::RenderWindow>& window) {
	window->draw(Entity::getBody());
}

void Food::update(Snake& snake) {
	bool newPos = false;

	if (snake.getSnakeBody().front().getGlobalBounds().intersects(Entity::getBody().getGlobalBounds())) {
	
		m_Score += 5;
	
		while (!newPos) {
			m_FoodX = rand() % 650 + 40;
			m_FoodY = rand() % 600 + 40;
			
			int32_t newSize = snake.getSnakeBody().size();
			snake.setSize(++newSize);
	
			if (snake.getSnakeBody().front().getPosition().x != m_FoodX && snake.getSnakeBody().front().getPosition().y != m_FoodY) {
				newPos = true;
			}
	
			Entity::setPos(sf::Vector2f(m_FoodX, m_FoodY));
		}
	}
}


uint32_t Food::getScore() const noexcept {
	return m_Score;
}
