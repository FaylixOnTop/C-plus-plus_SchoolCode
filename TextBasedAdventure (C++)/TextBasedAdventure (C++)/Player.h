#pragma once
#include <string>

class Player
{
public:
    explicit Player(const std::string& name);

    bool IsAlive() const;
    float GetHealth() const;
    void TakeDamage(float damage);
    const std::string& GetName() const;

private:
    float health = 100.0f;
    std::string name;
};