#include "Attack.h"

Attack::Attack(const std::string& aName, float someDamage)
    : name(aName), damage(someDamage)
{
}

const std::string& Attack::GetName() const
{
    return name;
}

float Attack::GetDamage() const
{
    return damage;
}