#pragma once
#include <iostream>
#include <string>


class Player
{
public:
	Player(std::string aName);
	~Player();

	bool IsAlive() const;
	float GetHealth() const;
	void TakeDamage(float damage);
	const std::string& GetName() const;


private:
	float health;
	std::string name;
};

