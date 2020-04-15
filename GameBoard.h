#pragma once
#include <array>
#include "Player.h"
class GameBoard
{
public:
	//functions
	GameBoard();

	void UpDate();

	int ReturnSingles(int i_);
	int ReturnDoubles(int i_);
	int ReturnTriples(int i_);

	void SetPlayer(Player* player_);

private:
	//variables
	//the array for the board
	std::array<int, 20> singles = { 20,1,18,4,13,6,10,15,2,17,3,19,7,16,8,11,14,9,12,5 };
	std::array<int, 20> doubles = { 40,2,36,8,26,12,20,30,4,34,6,38,14,32,16,22,28,18,24,10 };
	std::array<int, 20> triples = { 60,3,54,12,39,18,30,45,6,51,9,57,21,48,24,33,42,27,36,15 };

	Player* player1;
	Player* player2;

	int player1Legs;
	int player2Legs;
	int player1Games;
	int player2Games;
	int totalGamesPlayed;

	std::array<string, 14> possibleOutComes = { "0|7","1|7","2|7","3|7","4|7"
											   ,"5|7","6|7","7|6","7|5","7,4"
											   ,"7|3","7|2","7|1","7|0" };
	std::array<int, 14> actualOutComes;
};

