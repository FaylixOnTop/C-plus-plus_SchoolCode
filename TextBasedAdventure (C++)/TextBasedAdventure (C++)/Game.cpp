#include <iostream>
#include "Game.h"
#include "Player.h"
#include "npc.h"
#include "Attack.h"
#include "Windows.h"

#include <ctime>
#include <cstdlib>

Game::Game()
{
	//seed rand() once per program run different every time based on current time
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	player = new Player();
	AskPlayerName();

	if (hasPlayer)
	{
		std::cout << "The game is starting, Good luck\n";
		Sleep(1500);
		system("cls");
	}

	npc enemy1;
	npc enemy2;
	npc enemy3;
}

Game::~Game()
{
	std::cout << "The game is shutting down, Goodbye\n";
	delete player;
}

void Game::Update()
{
	PossibleAttacks();
	std::cin.get();
}

void Game::AskPlayerName()
{
	do
	{
		std::string inputName;
		std::cout << "What is your name?" << std::endl;
		std::cin >> inputName;
		system("cls");

		std::cout << "Are you sure " << inputName << " is your name? (Y/N)" << std::endl;
		char nameConfirmation;
		std::cin >> nameConfirmation;

		if (nameConfirmation == 'n' || nameConfirmation == 'N')
		{
			system("cls");
			AskPlayerName();
		}
		else if (nameConfirmation == 'y' || nameConfirmation == 'Y')
		{
			hasPlayer = true;
			std::cout << "Welcome, " << inputName << "!\n";
			system("cls");
		}
		else
		{
			std::cout << "Please enter Y or N.\n";
			system("cls");
		}
	} while (!hasPlayer);
}

void Game::PossibleAttacks()
{
	std::cout << "Available Attacks! :\n";

	Attack slash("Slash", 15.0f);
	Attack fireball("Fireball", 10.0f);

	// generate random damage between the existing variables
	const int minDamage = 1;
	const int maxDamage = 20;
	int finalDamage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage;

	Attack rng("RNG strike", static_cast<float>(finalDamage));

	std::cout << "1. " << slash.GetName() << " - Damage: " << slash.GetDamage();
	std::cout << "\n2. " << fireball.GetName() << " - Damage: " << fireball.GetDamage();
	std::cout << "\n3. " << rng.GetName() << " - Damage: " << rng.GetDamage() << std::endl;

	char attackChoice;
	std::cout << "Choose your attack : ";
	std::cin >> attackChoice;

	switch (attackChoice) {
	case '1':
		system("cls");
		std::cout << "You used " << slash .GetName() << " and dealt " << slash.GetDamage() << " damage!\n";
		Sleep(1500);
		system("cls");
		break;

	case '2':
		system("cls");
		std::cout << "You used " << fireball.GetName() << " and dealt " << fireball.GetDamage() << " damage!\n";
		Sleep(1500);
		system("cls");
		break;

	case '3':
		system("cls");
		std::cout << "You used " << rng.GetName() << " and dealt " << rng.GetDamage() << " damage!\n";
		Sleep(1500);
		system("cls");
		break;

	default:
		system("cls");
		std::cout << "Invalid attack choice. Please select a valid option\n";
		Sleep(1500);
		system("cls");
		break;
	}
}