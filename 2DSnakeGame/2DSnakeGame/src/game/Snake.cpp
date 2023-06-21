#include "../../header/game/Snake.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Snake::init() {

	m_Shape.setSize(sf::Vector2f(20.f, 20.f));
	m_Shape.setFillColor(sf::Color::Green);

	m_Body.resize(m_Size);

	return EXIT_SUCCESS;
}

void Snake::deinit() {
	m_Body.clear();
}

void Snake::draw(const std::unique_ptr<sf::RenderWindow>& window) {
	for (const auto& i : m_Body) {
		window->draw(i);
	}
}

void Snake::handleEvent(const std::unique_ptr<sf::RenderWindow>& window) {
	m_Body.resize(m_Size);
	sf::Vector2f pos;

	if (dir == Directions::RIGHT) {
		pos.x = m_Body.front().getPosition().x + m_LenghtBody;
		pos.y = m_Body.front().getPosition().y;

	}
	else if (dir == Directions::LEFT) {
		pos.x = m_Body.front().getPosition().x - m_LenghtBody;
		pos.y = m_Body.front().getPosition().y;

	}
	else if (dir == Directions::UP) {
		pos.x = m_Body.front().getPosition().x;
		pos.y = m_Body.front().getPosition().y - m_LenghtBody;

	}
	else if (dir == Directions::DOWN) {
		pos.x = m_Body.front().getPosition().x;
		pos.y = m_Body.front().getPosition().y + m_LenghtBody;

	}

	m_Shape.setPosition(pos);
	m_Body.push_front(m_Shape);

	outOfBounds(window);

	m_Body.pop_back();
}

void Snake::buttonsEvent(sf::Event& e) {
	if (e.type == sf::Event::KeyPressed) {
		if (e.key.code == sf::Keyboard::D && dir != Directions::LEFT) {
			dir = Directions::RIGHT;
		}
		else if (e.key.code == sf::Keyboard::A && dir != Directions::RIGHT) {
			dir = Directions::LEFT;
		}
		else if (e.key.code == sf::Keyboard::W && dir != Directions::DOWN) {
			dir = Directions::UP;
		}
		else if (e.key.code == sf::Keyboard::S && dir != Directions::UP) {
			dir = Directions::DOWN;
		}
	}
}

void Snake::setSize(uint32_t newSize) {
	m_Size = newSize;
}

bool Snake::collisionWithBody() {
	for (auto iter = m_Body.begin(); iter != m_Body.end(); ++iter) {
		if (iter != m_Body.begin() && iter->getPosition().x == m_Body.front().getPosition().x && iter->getPosition().y == m_Body.front().getPosition().y) {
			return true;
		}
	}

	return false;
}

std::list<sf::RectangleShape> Snake::getSnakeBody() const noexcept {
	return m_Body;
}

uint32_t Snake::getSize() const noexcept {
	return m_Size;
}

void Snake::outOfBounds(const std::unique_ptr<sf::RenderWindow>& window) {
	float width = window->getSize().x;
	float height = window->getSize().y;

	for (auto& i : m_Body) {
		if (i.getPosition().x > window->getSize().x) { // Right
			i.move(sf::Vector2f(-width, 0));
		}else if (i.getPosition().x < 0) { // Left
			i.move(sf::Vector2f(width, 0));
		}else if (i.getPosition().y > height) { // Down
			i.move(sf::Vector2f(0, -height));
		}else if (i.getPosition().y < 0) { // Up
			i.move(sf::Vector2f(0, height));
		}
	}
}
