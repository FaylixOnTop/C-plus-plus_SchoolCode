#pragma once
#include <vector>
#include "Player.h"

class Game
{
public:
    Game();
    ~Game();

    void Update();

private:
    void AskPlayerName();
    void PossibleAttacks();

    Player* player = nullptr;
    bool hasPlayer = false;
};