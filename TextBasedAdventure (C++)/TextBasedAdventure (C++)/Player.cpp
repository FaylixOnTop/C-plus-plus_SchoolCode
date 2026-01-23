#include "Player.h"
#include <iostream>

void Player::SetHealth(float aHealth)
{
    health = aHealth;
}

float Player::GetHealth() const
{
    return health;
}

void Player::ApplyDamage(float dmg)
{
    health -= dmg;
    if (health <= 0.0f)
    {
        health = 0.0f;
        std::cout << "You have been defeated!\n";
    }
    else
    {
        std::cout << "Your health is now " << health << "\n";
    }
}
