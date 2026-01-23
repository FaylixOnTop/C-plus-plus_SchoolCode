#pragma once
#include <string>
#include <iostream>

class Player
{
public:
    bool hasPlayer = false;

    void SetHealth(float aHealth);
    float GetHealth() const;
    void ApplyDamage(float dmg);

private:
    std::string name;
    float health = 100.0f;
};