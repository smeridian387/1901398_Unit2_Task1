#include <iostream>
#include "Player.h"
#include "GameBoard.h"
#include <time.h>
using namespace std;

int main()
{

	srand(time(NULL));

	GameBoard gameBoard;

	Player Joe("Joe", &gameBoard);
	Player Sid("Sid", &gameBoard);

	while (Joe.HasWon() == false && Sid.HasWon() == false)
	{
		Joe.TakeTurn();
		if (Joe.HasWon() == true)
		{
			break;
		}
		Sid.TakeTurn();
	}

}
