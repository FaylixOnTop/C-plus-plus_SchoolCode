#pragma once
#include <vector>
#include "Player.h"
#include "npc.h"

class Game
{
public:
    Game();
    ~Game();

    void Update();

private:
    void AskPlayerName();
    void PossibleAttacks();

    std::string playerName;

    npc tabbyCat;
    npc cheetah;
    npc tiger;

    Player* player = nullptr;
    bool hasPlayer = false;
};