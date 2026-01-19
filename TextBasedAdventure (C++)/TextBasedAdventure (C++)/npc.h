#pragma once
#include <string>

class npc
{
public:
	bool NpcHealth(float someHealth) const;
	bool NpcDamage(float minDamage, float maxDamage);
	bool IsAlive(bool isNpcAlive) const;

	std::string NpcDescription(std::string aDescription);
	std::string NpcWeakness(std::string aWeakness);

	float ApplyWeaknessMultiplier(const std::string& attackName, float baseDamage) const;

private:
	bool isAlive = true;

	std::string name;
	float health = 100.0f;
	float damage = 10.0f;

	std::string weakness;
	std::string description;
};

