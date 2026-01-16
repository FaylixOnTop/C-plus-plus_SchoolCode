#include "Combat.h"
#include <cstdlib>
#include <iostream>

namespace CritHelper
{
    float ApplyCriticalHit(float baseDamage, float critChance, float critMultiplier)
    {
        float roll = static_cast<float>(std::rand()) / RAND_MAX;

        if (roll <= critChance)
        {
            std::cout << "Critical Hit!\n";
            return baseDamage * critMultiplier;
        }

        return baseDamage;
    }
}

float Combat::ApplyCriticalHit(float baseDamage, float critChance, float critMultiplier)
{
    return CritHelper::ApplyCriticalHit(baseDamage, critChance, critMultiplier);
}