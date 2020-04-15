#include "GameBoard.h"
#include <array>

GameBoard::GameBoard()
{

}

void GameBoard::UpDate()
{
	if (player1->HasWon() == true)
	{
		player1Legs++;
		if (player1Legs == 3)
		{
			player1Legs = 0;
			player2Legs = 0;
			player1Games++;
			totalGamesPlayed++;
		}
	}
	if (player2->HasWon() == true)
	{
		player2Legs++;
		if (player1Legs == 3)
		{
			player1Legs = 0;
			player2Legs = 0;
			player2Games++;
		}
	}
}

int GameBoard::ReturnSingles(int i_)
{
	return singles[i_];
}

int GameBoard::ReturnDoubles(int i_)
{
	return doubles[i_];
}

int GameBoard::ReturnTriples(int i_)
{
	return triples[i_];
}

void GameBoard::SetPlayer(Player* player_)
{
	if (player1 == nullptr)
	{
		player1 = player_;
	}
	else
	{
		player2 = player_;
	}
}