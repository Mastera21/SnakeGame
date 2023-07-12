#pragma once

//C system headers

//C++ system headers

//Other libraries headers
#include <SFML/Graphics/RenderWindow.hpp>
//Own components headers
#include "../game/Snake.h"
#include "../entity/Entity.h"
//Forward declarations


class Food : public Entity {
public:
	Food();
	Food(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& color);

	virtual void draw(const std::unique_ptr<sf::RenderWindow>& window) override;
	virtual void update(Snake& snake, int& snakeSpeed) override;

	uint32_t getScore() const noexcept;

private:
	
	float m_FoodX = 0;
	float m_FoodY = 0;

	uint32_t m_Score = 0;

};

