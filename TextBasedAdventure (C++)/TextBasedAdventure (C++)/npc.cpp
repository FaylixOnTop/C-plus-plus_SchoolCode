#include "npc.h"
#include "Attack.h"
#include <random>
#include <iostream>

bool npc::NpcHealth(float someHealth) const
{
	return (someHealth == health);
}

bool npc::NpcDamage(float minDamage, float maxDamage)
{
	// static threadlocal random seed per thread
	static thread_local std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<float> dist(minDamage, maxDamage);

	float finalDamage = dist(rng);
	std::cout << "NPC deals " << finalDamage << " damage\n";

	damage = finalDamage;

	return true;
}

bool npc::IsAlive(bool isNpcAlive) const
{
	isNpcAlive = isAlive;
	return isAlive;
}

std::string npc::NpcWeakness(std::string aWeakness)
{
	// stores weakness
	weakness = aWeakness;
	return weakness;
}

float npc::ApplyWeaknessMultiplier(const std::string& attackName, float baseDamage) const
{
	// if attackname matches weakness, apply multiplier
	if (!weakness.empty() && attackName == weakness)
	{
		return baseDamage * 1.5f;
		std::cout << "It's super effective! Damage increased to " << (baseDamage * 1.5f) << "\n";
	}

	return baseDamage;
}

std::string npc::NpcDescription(std::string aDescription)
{
	description = aDescription;
	return description;
}