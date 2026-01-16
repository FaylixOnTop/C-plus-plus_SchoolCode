#pragma once
#include <string>

class Player
{
public:
	bool hasPlayer = false;
	bool playerHealth();
	



private:
	std::string name;
	float health = 100.0f;

};