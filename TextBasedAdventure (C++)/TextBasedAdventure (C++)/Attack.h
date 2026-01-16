#pragma once
#include <string>

class Attack
{
public:
    Attack(const std::string& name, float damage);

    const std::string& GetName() const;
    float GetDamage() const;

private:
    std::string name;
    float damage;
};