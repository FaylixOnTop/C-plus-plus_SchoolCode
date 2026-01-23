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
    // seed rand() once per program run different every time based on current time
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    player = new Player();
    player->SetHealth(100.0f);
    AskPlayerName();

    if (hasPlayer)
    {
        std::cout << "The game is starting, Good luck\n";
        Sleep(1500);
        system("cls");
    }

    tabbyCat.NpcHealth(100.0f);
    tabbyCat.NpcWeakness("Fireball");

    cheetah.NpcHealth(125.0f);
    cheetah.NpcWeakness("Slash");

    tiger.NpcHealth(225.0f);
    tiger.NpcWeakness("RNG strike");
}

Game::~Game()
{
    std::cout << "The game is shutting down, Goodbye\n";
    delete player;
}

void Game::Update()
{
    bool tabbyActive = false;
    bool cheetah = false;
    bool tiger = false;

    std::cout << "You are exploring the cat world...\n";
    Sleep(1250);
    std::cout << "When suddenly...\n";
    Sleep(1250);
    tabbyCat.NpcDescription("A wild tabby cat appears with sharp claws and a fierce look.");
    Sleep(2000);
    tabbyActive = true;

    while (tabbyActive)
    {
        system("cls");
        std::cout << "You are fighting the tabby cat!\n";

        PossibleAttacks();

        if (!tabbyCat.IsAlive())
        {
            tabbyActive = false;
            break;
        }

        if (player->GetHealth() <= 0.0f)
        {
            std::cout << "Game Over\n";
            tabbyActive = false;
            break;
        }
    }

    while (cheetah == true)
    {
        system("cls");
        std::cout << "You are fighting the cheetah!\n";

        PossibleAttacks();

        if (!tabbyCat.IsAlive())
        {
            cheetah = false;
            break;
        }

        if (player->GetHealth() <= 0.0f)
        {
            std::cout << "Game Over\n";
            cheetah = false;
            break;
        }
    }

    while (tiger == true)
    {
        system("cls");
        std::cout << "You are fighting the tiger!\n";

        PossibleAttacks();

        if (!tabbyCat.IsAlive())
        {
            tiger = false;
            break;
        }

        if (player->GetHealth() <= 0.0f)
        {
            std::cout << "Game Over\n";
            tiger = false;
            break;
        }
	}
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
    Sleep(1000);
    std::cout << "\nWhat would you like to try?\n";

    Attack slash("Slash", 15.0f);
    Attack fireball("Fireball", 10.0f);

    // generate random damage between the existing variables
    const int minDamage = -5;
    const int maxDamage = 20;
    int finalDamage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage;

    Attack rng("RNG strike", static_cast<float>(finalDamage));

    std::cout << "1. " << slash.GetName() << " - Damage: " << slash.GetDamage();
    std::cout << "\n2. " << fireball.GetName() << " - Damage: " << fireball.GetDamage();
    std::cout << "\n3. " << rng.GetName() << " - Damage: ???" << std::endl;

    char attackChoice;
    std::cout << "\nChoose your attack : ";
    std::cin >> attackChoice;

    float playerDealt = 0.0f;
    const Attack* chosen = nullptr;

    switch (attackChoice) {
    case '1':
        chosen = &slash;
        break;

    case '2':
        chosen = &fireball;
        break;

    case '3':
        chosen = &rng;
        break;

    default:
        system("cls");
        std::cout << "Invalid attack choice. Please select a valid option\n";
        Sleep(1500);
        system("cls");
        return;
    }

    system("cls");
    std::cout << "You used " << chosen->GetName() << " and dealt " << chosen->GetDamage() << " damage!\n";

    // apply weakness multiplier
    playerDealt = tabbyCat.ApplyWeaknessMultiplier(chosen->GetName(), chosen->GetDamage());
    tabbyCat.ApplyDamage(playerDealt);

    Sleep(5000);
    system("cls");

    if (tabbyCat.IsAlive())
    {
        const int npcMin = 1;
        const int npcMax = 25;
        float npcDamage = tabbyCat.NpcDamage(static_cast<float>(npcMin), static_cast<float>(npcMax));

        // apply damage to player
        player->ApplyDamage(npcDamage);

        Sleep(3500);
        system("cls");
    }
}