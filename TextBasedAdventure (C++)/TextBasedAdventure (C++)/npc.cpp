#include "npc.h"
#include <random>
#include <iostream>

void npc::NpcHealth(float someHealth)
{
    health = someHealth;
    isAlive = (health > 0.0f);
}

float npc::NpcDamage(float minDamage, float maxDamage)
{
    static thread_local std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<float> dist(minDamage, maxDamage);

    float finalDamage = dist(rng);
    damage = finalDamage;

    std::cout << "NPC deals " << finalDamage << " damage\n";
    return finalDamage;
}

bool npc::IsAlive() const
{
    return isAlive && (health > 0.0f);
}

std::string npc::NpcDescription(const std::string& aDescription)
{
    description = aDescription;
    std::cout << description << "\n";
    return description;
}

void npc::NpcWeakness(const std::string& aWeakness)
{
    weakness = aWeakness;
}

float npc::ApplyWeaknessMultiplier(const std::string& attackName, float baseDamage) const
{
    if (attackName == weakness)
    {
        float increased = baseDamage * 1.5f;
        std::cout << "It's super effective! Damage increased to " << increased << "\n";
        return increased;
    }

    return baseDamage;
}

float npc::GetHealth() const
{
    return health;
}

void npc::ApplyDamage(float dmg)
{
    health -= dmg;
    if (health <= 0.0f)
    {
        health = 0.0f;
        isAlive = false;
        std::cout << "The NPC has been defeated!\n";
    }
    else
    {
        std::cout << "NPC health is now " << health << "\n";
    }
}