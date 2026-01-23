#pragma once
#include <string>

class npc
{
public:
    void NpcHealth(float someHealth);

    float NpcDamage(float minDamage, float maxDamage);

    bool IsAlive() const;

    std::string NpcDescription(const std::string& aDescription);

    void NpcWeakness(const std::string& aWeakness);

    float ApplyWeaknessMultiplier(const std::string& attackName, float baseDamage) const;

    float GetHealth() const;
    void ApplyDamage(float dmg);

private:
    bool isAlive = true;
    std::string name;
    float health = 100.0f;
    float damage = 10.0f;
    std::string weakness;
    std::string description;
};

