#pragma once
#include <string>
#include <iostream>

class Player
{
public:
	bool hasPlayer = false;
	bool playerHealth(float aHealth) const;
	



private:
	std::string name;
	float health = 100.0f;

};