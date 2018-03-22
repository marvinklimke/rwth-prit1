/**
 * @file Reversi_KI.cpp
 *
 * Provides a KI for the game Reversi.
 */

#include "Reversi_KI.h"
#include <iostream>


// decide which system header to include
#ifdef WIN32
	#include <windows.h> // Windows only
#else
	#include <unistd.h> //POSIX compliant Systems only (UNIX (e.g. Mac OS X), Linux, ...)
#endif


extern int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);
extern void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y);
extern bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y);

bool computer_turn(int field[SIZE_Y][SIZE_X], const int player)
{
	if (possible_turns(field,player) == 0)
	{
		return false;
	}
	int look_ahead[SIZE_Y][SIZE_X];
	int min_x = 0;
	int min_y = 0;
	int min = SIZE_X * SIZE_Y;

	for (int j = 0 ; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			// reset field
			for (int cj = 0; cj < SIZE_Y; cj++)
			{
				for (int ci = 0; ci < SIZE_X; ci++)
				{
					look_ahead[cj][ci]=field[cj][ci];
				}
			}

			if (turn_valid(look_ahead, player, i, j))
			{
				execute_turn(look_ahead, player, i, j);
				if (possible_turns(look_ahead, 3 - player) < min)
				{
					min=possible_turns(look_ahead, 3 - player);
					min_x = i;
					min_y = j;
				}
			}
		}
	}

	execute_turn(field, player, min_x, min_y);
	std::cout << std::endl << "Player " << player << " moves to " << (char) (min_x + 65) << (min_y + 1) << std::endl;

	// system dependent function call
	#ifdef WIN32
		Sleep(2); // 2 milliseconds pause to check computers move! (Windows only)
	#else
		usleep(2); // 2 milliseconds pause to check computers move!
				   //POSIX compliant Systems only (UNIX (e.g. Mac OS X), Linux, ...)
	#endif

	return true;
}
