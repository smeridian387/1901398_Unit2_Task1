#pragma once
#include <iostream>
#include <string>
#include "GameBoard.h"
#include <array>
using namespace std;

class Player
{
public:

	Player(string name_, GameBoard* gameBoard_);

	void TakeTurn();

	void ThrowSingle(int target_);
	void ThrowTreble(int target_);
	void ThrowDouble(int target_);
	void ThrowBull();

	bool HasWon();
	void SetWon(bool won_);
	void SetSuccessRate(int SR_);

private:

	GameBoard gameBoard;
	string name;

	//the folloing 3 arrays are the possible outcomes of every tile on the dart board not including bull and outer bull
	std::array<int, 20 >possibleSingles = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	std::array<int, 20 >possibleDoubles = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40 };
	std::array<int, 20 >possibleTrebles = { 3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60 };
	int successRate;// successrate of the player
	int score = 501;// player score
	int scoreAtStart; //score at the start of the turn
	int throwsThisGame = 0;
	int legsWon = 0;
	bool dartLanded = false;//has the dart landed in the board this throw?
	bool hasWon = false;
	bool bust = false;
};

