#pragma once

class ScoreInterface {
public:
	virtual ~ScoreInterface() = default;
	virtual std::string getScore() const = 0;
};