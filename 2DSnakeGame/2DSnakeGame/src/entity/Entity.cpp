#include "../../header/entity/Entity.h"


Entity::Entity(const sf::Vector2f& size, const sf::Color& color) {
	m_Body.setSize(size);
	m_Body.setOrigin(m_Body.getSize().x / 2.0f, m_Body.getSize().y / 2.0f);
	m_Body.setFillColor(color);
}

void Entity::draw(const std::unique_ptr<sf::RenderWindow>& window) {
	window->draw(m_Body);
}

sf::Vector2f Entity::getPos() {
	return m_Body.getPosition();
}
sf::RectangleShape Entity::getBody() {
	return m_Body;
}
sf::Vector2f Entity::getSize() {
	return m_Body.getSize();
}

void Entity::setPos(const sf::Vector2f& newPos) {
	m_Body.setPosition(newPos);
}

void Entity::setSize(const sf::Vector2f& newSize) {
	m_Body.setSize(newSize);
}

void Entity::setFillCol(const sf::Color& newColor) {
	m_Body.setFillColor(newColor);
}

