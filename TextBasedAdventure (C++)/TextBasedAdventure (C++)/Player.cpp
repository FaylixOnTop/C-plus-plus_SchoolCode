#include "Player.h"

Player::Player(const std::string& aName)
    : name(aName)
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
    if (health < 0) health = 0;
}

const std::string& Player::GetName() const
{
    return name;
}