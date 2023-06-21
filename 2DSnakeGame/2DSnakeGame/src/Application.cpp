#include "../header/Application.h"
//C system headers

//C++ system headers
#include <iostream> 
//Other libraries headers

//Own components headers

int32_t Application::init() {

	m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(700, 700), "");
	m_Window->setFramerateLimit(60);

	m_MainMenu = std::make_unique<MainMenu>();
	if (EXIT_SUCCESS != m_MainMenu->init(m_Window)) {
		std::cout << "Error, m_MainMenu.init() failed.\n";
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != m_Snake.init()) {
		std::cout << "Error, m_Snake.init() failed.\n";
		return EXIT_FAILURE;
	}

	m_Food = std::make_unique<Food>(sf::Vector2f(30.f,30.0f),sf::Vector2f(rand() % 650 + 40, rand() % 600 + 40), sf::Color::Red);
	if (m_Food == nullptr) {
		std::cout << "Error, Food() failed.\n";
		return EXIT_FAILURE;
	}

	m_EndMenu = std::make_unique<EndMenu>(this);
	if (EXIT_SUCCESS != m_EndMenu->init(m_Window)) {
		std::cout << "Error, m_EndMenu.init() failed.\n";
		return EXIT_FAILURE;
	}

	m_IsStartButtonPressed = false;
	m_IsStopButtonPressed = false;

	return EXIT_SUCCESS;
}

void Application::deinit() {
	m_Snake.deinit();
}

void Application::main() {

	if (EXIT_SUCCESS != init()) {
		std::cout << "Error, init() failed.\n";
		return;
	}

	while (m_Window->isOpen()) {
		sf::sleep(sf::Time(sf::milliseconds(100)));
		sf::Event e;
		update(e);
		draw();

	}
	deinit();
}

void Application::update(sf::Event& e) {
	while (m_Window->pollEvent(e)) {
		if (requestForExit(e) || m_IsStopButtonPressed) {
			m_Window->close();
			break;
		}
		m_Snake.buttonsEvent(e);
		m_Window->setTitle("Snake 2D					Score: " + std::to_string(m_Food->getScore()));
	}

	handleEvent();
}

void Application::run() {
	main();
}

void Application::draw() {
	m_Window->clear({70, 115, 232});

	if (!m_Snake.collisionWithBody()) {
		if (m_IsStartButtonPressed) {
			m_Snake.draw(m_Window);
			m_Food->draw(m_Window);
			m_MainMenu->deinit();
		}
		else {
			m_MainMenu->draw(m_Window);
		}
	}else {
		m_EndMenu->draw(m_Window);
	}

	m_Window->display();
}

void Application::handleEvent() {
	if (!m_Snake.collisionWithBody()) {
		if (m_IsStartButtonPressed) {
			m_Snake.handleEvent(m_Window);
			m_Food->update(m_Snake);
		}else {
			m_MainMenu->handleEvent(m_Window, m_IsStartButtonPressed, m_IsStopButtonPressed);
		}
	}else {
		m_EndMenu->handleEvent(m_Window, m_IsStopButtonPressed);
	}
}

bool Application::requestForExit(sf::Event& e) {
	switch (e.type) {
	case sf::Event::Closed:
		m_Window->close();
		return true;
		break;
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			m_Window->close();
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}

std::string Application::getScore() const {
	return std::to_string(m_Food->getScore());
}