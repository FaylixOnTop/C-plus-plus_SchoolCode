#include "Game.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Attack.h"

Game::Game()
{
	player = nullptr;
	hasPlayer = false;

	npcs.push_back(new Player("Goblin"));
	npcs.push_back(new Player("Orc"));
	npcs.push_back(new Player("Dragon"));
}

Game::~Game()
{

}

void Game::Update()
{
	if (!hasPlayer)
	{
		AskPlayerName();
	}

	std::cout << "Player Health: " << player->GetHealth() << std::endl;
	std::cout << "Press A to attack yourself (test)" << std::endl;

	char input;
	std::cin >> input;

	if (input == 'A' || input == 'a')
	{
		Attack SlashAttack("Slash", 25.0f);

		std::cout << player->GetName() << " has attacked " << player->GetName() << " with " << SlashAttack.GetName() << " for " << SlashAttack.GetDamage() << " Damage! " << std::endl;

		player->TakeDamage(SlashAttack.GetDamage());

		Sleep(2000);
		system("cls");
	}

	if (!player->IsAlive())
	{
		std::cout << "You have died! Game Over." << std::endl;
		exit(0);
	}

}

void Game::AskPlayerName()
{
	std::string inputName;
	std::cout << "What is your name player?" << std::endl;
	std::cin >> inputName;
	std::cout << "Press any key to continue..." << std::endl;

	_getch();
	system("cls");
	std::cout << "Hello " << inputName << ", welcome to the game!" << std::endl;

	player = new Player(inputName);
	hasPlayer = true;
}
