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
			bust = false;
			break;
		}

		if (score > 111)
		{
			ThrowTreble(20);
		}
		else
		{
			int tempScore = score;
			int target = (score - 50);
			for (int j = 19; j > -1; --j)
			{
				if (possibleTrebles[j] == target)
				{
					ThrowTreble(possibleSingles[j]);
					break;
				}
				else if (possibleDoubles[j] == target || (target - possibleDoubles[j]) > 0)
				{
					ThrowDouble(possibleSingles[j]);
					break;
				}
				else if (possibleSingles[j] == target || (target - possibleSingles[j]) > 0)
				{
					ThrowSingle(possibleSingles[j]);
					break;
				}
			}
			if (score == 50)
			{
			ThrowBull();
			if (hasWon == true)
			{
				break;
			}
			}
			if (score < 50)
			{
				bust = true;
				score = scoreAtStart;
				cout << name << " bust score reset to: " << scoreAtStart << endl;
				break;
			}
		}
	}
	cout << "turn over" << endl;
}

void Player::ThrowSingle(int target_)
{
	if (dartLanded == false)
	{
		int rand = std::rand() % 99 + 1;
		if (rand <= successRate)
		{
			score -= target_;
			dartLanded = true;
			cout << name << " hit a single " << target_ << " new score: " << score << endl;
		}
		else
		{
			for (int i = 0; i < 20; ++i)
			{
				if (gameBoard.ReturnSingles(i) == target_)
				{
					int rand = std::rand() % 50 + 1;
					if (rand > 0 && rand <= 10)
					{
						if (i == 0)//incase of i being zero (fixes wraparound problem)
						{
							i = 20;
						}
						score -= gameBoard.ReturnSingles(i - 1);
						dartLanded = true;
						cout << name << " mS,Hit " << gameBoard.ReturnSingles(i - 1) << " new score: " << score << endl;
						break;
					}
					else if (rand > 10 && rand <= 20)
					{
						if (i == 19)//incase of i being 21 (fixes wraparound problem)
						{
							i = -1;
						}
						score -= gameBoard.ReturnSingles(i + 1);
						dartLanded = true;
						cout << name << " mS,Hit " << gameBoard.ReturnSingles(i + 1) << " new score: " << score << endl;
						break;
					}
					else if (rand > 20 && rand <= 30)
					{
						score -= target_ * 2;//hit double by accident
						dartLanded = true;
						cout << name << " mS,HitD " << target_ * 2 << " new score: " << score << endl;
						break;
					}
					else if (rand > 30 && rand <= 40)
					{
						if (i == 0)//incase of i being zero (fixes wraparound problem)
						{
							i = 20;
						}
						score -= gameBoard.ReturnDoubles(i - 1);
						dartLanded = true;
						cout << name << " mS,HitD " << gameBoard.ReturnDoubles(i - 1) << " new score: " << score << endl;
						break;
					}
					else if (rand > 40 && rand <= 50)
					{
						if (i == 19)//incase of i being 21 (fixes wraparound problem)
						{
							i = -1;
						}
						score -= gameBoard.ReturnDoubles(i + 1);
						dartLanded = true;
						cout << name << " mS,HitD " << gameBoard.ReturnDoubles(i + 1) << " new score: " << score << endl;
						break;
					}
				}
			}
		}
	}
}

void Player::ThrowDouble(int target_)
{
	if (dartLanded == false)
	{
		int rand = std::rand() % 99 + 1;
		if (rand <= successRate)
		{
		score -= target_*2;
		dartLanded = true;
		cout << name << "hit a double " << target_*2 << " new score: " << score << endl;
		}
		else
		{
			for (int i = 0; i < 20; ++i)
			{
				if (gameBoard.ReturnDoubles(i) == target_*2)
				{
					int rand = std::rand() % 50 + 1;
					if (rand > 0 && rand <= 10)
					{
						if (i == 0)//incase of i being zero (fixes wraparound problem)
						{
							i = 20;
						}
						score -= gameBoard.ReturnDoubles(i - 1);
						dartLanded = true;
						cout << name << " mD,Hit " << gameBoard.ReturnDoubles(i - 1) << " new score: " << score << endl;
						break;
					}
					else if (rand > 10 && rand <= 20)
					{
						if (i == 19)//incase of i being 21 (fixes wraparound problem)
						{
							i = -1;
						}
						score -= gameBoard.ReturnDoubles(i + 1);
						dartLanded = true;
						cout << name << " mD,Hit " << gameBoard.ReturnDoubles(i + 1) << " new score: " << score << endl;
						break;
					}
					else if (rand > 20 && rand <= 30)
					{
						score -= target_; //misses the double, hits the single
						dartLanded = true;
						cout << name << " mD,hitS " << target_ << " new score: " << score << endl;
						break;
					}
					else if (rand > 30 && rand <= 40)
					{
						if (i == 0)//incase of i being zero (fixes wraparound problem)
						{
							i = 20;
						}
						score -= gameBoard.ReturnSingles(i - 1);
						dartLanded = true;
						cout << name << " mD,HitS " << gameBoard.ReturnSingles(i - 1) << " new score: " << score << endl;
						break;
					}
					else if (rand > 40 && rand <= 50)
					{
						if (i == 19)//incase of i being 21 (fixes wraparound problem)
						{
							i = -1;
						}
						score -= gameBoard.ReturnSingles(i + 1);
						dartLanded = true;
						cout << name << " mD,HitS " << gameBoard.ReturnSingles(i + 1) << " new score: " << score << endl;
						break;
					}
				}
			}
		}
	}
}

void Player::ThrowTreble(int target_)
{
	if (dartLanded == false)
	{
		int rand = std::rand() % 99 + 1;
		if (rand <= successRate)
		{
		score -= target_ * 3;
		dartLanded = true;
		cout << name << "hit a triple " << target_ * 3 << " new score: " << score << endl;
		}
		else
		{
			for (int i = 0; i < 20; ++i)
			{
				if (gameBoard.ReturnTriples(i) == target_*3)
				{
					int rand = std::rand() % 50 + 1;
					if (rand > 0 && rand <= 10)
					{
						if (i == 0)//incase of i being zero (fixes wraparound problem)
						{
							i = 20;
						}
						score -= gameBoard.ReturnTriples(i - 1);//returns the value of the tile on the left of the target tile
						dartLanded = true;
						cout << name << " mT,Hit " << gameBoard.ReturnTriples(i - 1) << " new score: " << score << endl;
						break;
					}
					else if (rand > 10 && rand <= 20)
					{
						if (i == 19)//incase of i being 21 (fixes wraparound problem)
						{
							i = -1;
						}
						score -= gameBoard.ReturnTriples(i + 1);//returns the value of the tile on the right of the target tile
						dartLanded = true;
						cout << name << " mT,Hit " << gameBoard.ReturnTriples(i + 1) << " new score: " << score << endl;
						break;
					}
					else if (rand > 20 && rand <= 30)
					{
						score -= target_;
						dartLanded = true;
						cout << name << " mT,hitS " << target_ << " new score: " << score << endl;
					}
					else if (rand > 30 && rand <= 40)
					{
						if (i == 0)//incase of i being zero (fixes wraparound problem)
						{
							i = 20;
						}
						score -= gameBoard.ReturnSingles(i - 1);//returns the value of the tile on the left of the target tile
						dartLanded = true;
						cout << name << " mT,HitS " << gameBoard.ReturnSingles(i - 1) << " new score: " << score << endl;
						break;
					}
					else if (rand > 40 && rand <= 50)
					{
						if (i == 19)//incase of i being 21 (fixes wraparound problem)
						{
							i = -1;
						}
						score -= gameBoard.ReturnSingles(i + 1);//returns the value of the tile on the right of the target tile
						dartLanded = true;
						cout << name << " mT,HitS " << gameBoard.ReturnSingles(i + 1) << " new score: " << score << endl;
						break;
					}

				}
			}
		}
	}
}

void Player::ThrowBull()
{
	if (dartLanded == false)
	{
		int rand = std::rand() % 99 + 1;
		if (rand <= successRate)
		{
		score -= 50;
		dartLanded = true;
		cout << name << " bull hit "<< score << endl;
		hasWon = true;
		cout << "game over " << name << " has won" << endl;
		}
		else
		{
			score -= 25; // hit outer bull
			dartLanded = true;
			cout << name << " hit outer bull hit" << endl;
		}
	
	}
}

void Player::SetWon(bool win_)
{
	hasWon = win_;
}

bool Player::HasWon()
{
	return hasWon;
}

void Player::SetSuccessRate(int SR_)
{
	successRate = SR_;
}
