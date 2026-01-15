#include "Player.h"

Player::Player(std::string aName)
	: name(aName), health(100) // Initialize name and health
{

}

Player::~Player()
{

}

bool Player::IsAlive() const
{
	return health > 0;
}

float Player::GetHealth() const
{
	return health;
}

void Player::TakeDamage(float damage)
{
	health -= damage;
	if (health < 0) health = 0; // Prevent negative health
}

const std::string& Player::GetName() const
{
	return name;
}
