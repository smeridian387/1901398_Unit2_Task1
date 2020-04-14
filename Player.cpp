#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(string name_, GameBoard* gameBoard_)
{
	gameBoard = *gameBoard_;
	name = name_;
}

void Player::TakeTurn()
{
	scoreAtStart = score; //incase of bust reset score
	for (int i = 0; i < 3; ++i)//loop three times for three darts
	{
		dartLanded = false;//readys the program to throw another dart

		if (bust == true)// if bust is true stop throwing darts
		{
			break;
		}

		if (score > 81)
		{
			ThrowTreble(20);
		}
		else
		{
			int target = (score - 50);
			for (int j = 19; j > 0; --j)
			{
				if (possibleTrebles[j] == target)
				{
					ThrowTreble(possibleSingles[j]);
				}
				else if (possibleDoubles[j] == target)
				{
					ThrowDouble(possibleSingles[j]);
				}
				else if (possibleSingles[j] == target)
				{
					ThrowSingle(possibleSingles[j]);
				}
			}
		}
	}
}

void Player::ThrowSingle(int target_)
{
	if (dartLanded == false)
	{
		score -= target_;
	}
}

void Player::ThrowDouble(int target_)
{

}

void Player::ThrowTreble(int target_)
{

}

void Player::ThrowBull()
{

}

bool Player::HasWon()
{
	return hasWon;
}

void Player::SetSuccessRate(int SR_)
{
	successRate = SR_;
}
