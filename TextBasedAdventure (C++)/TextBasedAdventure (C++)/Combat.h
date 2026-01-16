#pragma once

class Combat
{
public:
        static float ApplyCriticalHit(float baseDamage,
        float critChance = 0.2f,
        float critMultiplier = 1.5f);
};