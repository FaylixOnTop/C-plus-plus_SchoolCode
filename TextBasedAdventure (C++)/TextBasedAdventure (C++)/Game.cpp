#include <iostream>
#include "Game.h"
#include "Player.h"

Game::Game()
{
	player = new Player();
	AskPlayerName();

	if (hasPlayer)
	{
		std::cout << "The game is starting, Good luck\n";
	}
}

Game::~Game()
{

}

void Game::Update()
{
	std::cout << "These are all of the possible attacks you can do:\n";
	PossibleAttacks();
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

}