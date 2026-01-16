#include "Game.h"
#include "Attack.h"
#include "Combat.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>

Game::Game()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    npcs.push_back(new Player("Goblin"));
    npcs.push_back(new Player("Orc"));
    npcs.push_back(new Player("Dragon"));
}

Game::~Game()
{
    delete player;
    for (Player* npc : npcs)
        delete npc;
}

void Game::Update()
{
    if (!hasPlayer)
        AskPlayerName();

    std::cout << "Player Health: " << player->GetHealth() << '\n';
    PossibleAttacks();

    if (!player->IsAlive())
    {
        std::cout << "You have died! Game Over.\n";
        std::exit(0);
    }
}

void Game::AskPlayerName()
{
    std::string name;
    std::cout << "What is your name?\n";
    std::cin >> name;

    _getch();
    system("cls");

    player = new Player(name);
    hasPlayer = true;
}

void Game::PossibleAttacks()
{
    char choice;
    std::cout << "1) Slash\n2) Blunt\n3) Quick\n";
    std::cin >> choice;

    Attack attack("", 0.0f);

    switch (choice)
    {
    case '1': attack = Attack("Slash", 25.0f); break;
    case '2': attack = Attack("Blunt", 15.0f); break;
    case '3': attack = Attack("Quick", 10.0f); break;
    default:
        std::cout << "Invalid choice\n";
        return;
    }

    float damage = Combat::ApplyCriticalHit(attack.GetDamage());
    player->TakeDamage(damage);

    std::cout << player->GetName()
        << " used " << attack.GetName()
        << " for " << damage << " damage!\n";
}