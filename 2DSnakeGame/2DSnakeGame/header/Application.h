#pragma once

//C system headers

//C++ system headers
#include <memory>

//Other libraries headers

//Own components headers
#include "../header/game/Snake.h"
#include "../header/game/Food.h"
#include "../header/menu/MainMenu.h"
#include "../header/menu/EndMenu.h"

#include "../interfaces/score/ScoreInterface.h"

//Forward declarations


class Application : public ScoreInterface {
public:

	int32_t init();
	void deinit();
	void main();
	void update(sf::Event& e);
	void run();
	void draw();
	void handleEvent();

	bool requestForExit(sf::Event& e);

	virtual std::string getScore() const override;

private:
	std::unique_ptr<sf::RenderWindow> m_Window;
	std::unique_ptr<MainMenu> m_MainMenu;
	std::unique_ptr<EndMenu> m_EndMenu;
	std::unique_ptr<Food> m_Food;

	Snake m_Snake;

private:
	std::string m_Title;

	bool m_IsStartButtonPressed;
	bool m_IsStopButtonPressed;

};

