#include <iostream>
#include "Game.h"
#include "Player.h"

Game::Game()
{
	player = new Player();
	AskPlayerName();
}

Game::~Game()
{

}

void Game::Update()
{
	if (hasPlayer == true)
	{
		std::cout << "The game is starting..." << std::endl;
		std::cout << "Here are your possible attacks:" << std::endl;
		std::cin.get();
	}
}

void Game::AskPlayerName()
{
	std::string inputName;
	std::cout << "What is your name?" << std::endl;
	std::cin >> inputName;
	system("cls");

	std::cout << "Are you sure " << inputName << " is your name? (Y/N)" << std::endl;
	char nameConfirmation;
	std::cin >> nameConfirmation;

	do
	{
		std::cout << "Confirm name? (Y/N): ";
		std::cin >> nameConfirmation;

		if (nameConfirmation == 'n' || nameConfirmation == 'N')
			return;
		else if (nameConfirmation == 'y' || nameConfirmation == 'Y')
			hasPlayer = true;
		else
			std::cout << "Please enter Y or N." << std::endl;
	} while (!hasPlayer);

	std::cout << "Welcome, " << inputName << "!" << std::endl;
}

void Game::PossibleAttacks()
{
}
