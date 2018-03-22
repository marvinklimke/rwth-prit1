/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

/**Defines the type of a player */
#define HUMAN 1
#define COMPUTER 2

#include "test.h"
#include "config.h"
#include "Reversi_KI.h"
#include <iostream>
#include <stdlib.h>

/**
 * @brief Function providing first initialization of a new field
 *
 * This function fills an existing field with zeros and creates the starting pattern.
 *
 * @param field The field which will be initialized
 */
void initialize_field(int field[SIZE_Y][SIZE_X])
{
	for (int j = 0; j < SIZE_Y; j++)
		{
			for(int i = 0; i < SIZE_X; i++)
			{
				field[j][i] = 0;
			}
		}
		field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
		field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
		field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
		field[SIZE_Y / 2][SIZE_X / 2] = 1;
}



/**
* @brief Prints the playing field to the console.
*
* This function gets the current playing field as parameter (two dimensional array)
* with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
* <br>The function prints the playing field, grid included, to the console.
* Crosses symbolize player 1 while circles symbolize player 2.
*
*  @param field  The field which is going to be printed
*/
void show_field(const int field[SIZE_Y][SIZE_X])
{
	std::cout << "  ";

//Start at ASCII 65 = A
	for (int j = 65; j < 65 + SIZE_Y; j++)
		std::cout << ((char) j) << " " ;

	std::cout << std::endl;

	for (int j = 0; j < SIZE_Y; j++)
	{
		std::cout << j + 1;
		for (int i = 0; i < SIZE_X; i++)
		{
			switch (field[j][i])
			{
				case 0:
					std::cout << "  " ;
					break;
				case 1:
					std::cout << " X";
					break;
				case 2:
					std::cout << " O";
					break;
				default:
					std::cout << "Inconsistent data in field!" << std::endl;
					std::cout << "Aborting .... " << std::endl;
					exit(0);
					break;
			}
		};//for i
		std::cout << std::endl;
	}//for j
}

/**
 * @brief Determines the winner based on a given field
 *
 * This function gets the playing field as a parameter (two dimensional array)
 * with entries of 0 (empty field), 1 (field belongs to player1) and 2 (field belongs to player2)
 * <br>All entries for player1 and player2 are summed up and compared to determine the winner
 * (i.e. the player with more fields belonging to him on the field).
 *
 * @param field the playing field as two dimensional array
 * @return 0 for draw, 1 for player1 wins, 2 for player2 wins
 */
int winner(const int field[SIZE_Y][SIZE_X])
{
	int count_p1 = 0;
	int count_p2 = 0;

	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			//loop through all fields & counting of X (P1) and O (P2)
			if(field[j][i] == 1)
			{
				count_p1++;
			}
			else if(field[j][i] == 2)
			{
				count_p2++;
			}
		}
	}
	// who has more fields?
	if (count_p1 == count_p2)
	{
		return 0;
	}
	if (count_p1 < count_p2)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

/**
 * \brief Checks whether a given player can take a move at a given position on a given field
 *
 * First, this function checks, if the desired field is empty (necessary for a move).
 * Then it looks for adjacent opponents stones and follows a path of those to check
 * if this path is terminated by a stone of the player, in this case the move is valid,
 * otherwise not.
 *
 * @param field the current playing field as a two dimensional array
 * @param player the current player that would take the move
 * @param pos_x the desired positions x-coordinate
 * @param pos_y the desired positions y-coordinate
 * @return true if the move is valid, false otherwise
 */
bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
	{
		return false;
	}

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			// Note: the case i=0, j=0 doesn't need an exception, because it is an empty field
			if(field[pos_y+i][pos_x+j] == opponent) // found an opponents stone?
			{
				int k = 2; // factor to follow along a path of stones
				while(pos_y+k*i >= 0 && pos_x+k*j >= 0 && pos_y+k*i < SIZE_Y && pos_x+k*j < SIZE_X)
				// Follow Path to the end of field
				{
					if(field[pos_y + k * i][pos_x + k * j] == 0)
					{
						// path interrupted by empty field
						break;
					}
					else if(field[pos_y + k * i][pos_x + k * j] == player)
					{
						// found a valid path
						return true;
					}
					k++; // go one step ahead following the path
				} // while
			} // if (opponent stone)
		} // for j
	} // for i
	return false;
}

/**
 * \brief Executes a turn of a given player on a given field at a given position
 *
 * This function takes a field (call by reference) a player and a position on the field
 * to execute the turn of the player. Therefore all paths of opponents stones encapsulated
 * by the players stones get turned to players stone.
 *
 * @param field the current playing field (call by reference)
 * @param player the player willing to do the move
 * @param pos_x desired positions x-coordinate
 * @param pos_y desired positions y-coordinate
 */
void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
	{
		return;
	}

	// Set first stone
	field[pos_y][pos_x] = player;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			// Note: the case i=0, j=0 doesn't need an exception, because it is an empty field
			if(field[pos_y+i][pos_x+j] == opponent) // found an opponents stone?
			{
				int k = 2; // factor to follow along a path of stones
				while(pos_y+k*i >= 0 && pos_x+k*j >= 0 && pos_y+k*i < SIZE_Y && pos_x+k*j < SIZE_X)
				// Follow Path to the end of field
				{
					if(field[pos_y + k * i][pos_x + k * j] == 0)
					{
						// path interrupted by empty field
						break;
					}
					else if(field[pos_y + k * i][pos_x + k * j] == player)
					{
						// found a valid path
						for(int l = k-1; l > 0; l--)
						{
							// Go path back again and set all fields to player
							field[pos_y + l * i][pos_x + l * j] = player;
						}
						break;
					}
					k++; // go one step ahead following the path

				} // while (following the path)
			} // if (found adjacent opponents stone)

		} // for (j) -
	} // for (i) |

} // void execute_turn

/**
 * \brief This function counts the possible turns of a given player on a given field
 *
 * This function checks or a given player the number of possible turns on the
 * given (current) playing field.
 *
 * @param field the current playing field
 * @param player the player, whose possible turns should be counted
 * @return number of possible turns of player
 */
int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
{
	int count = 0;

	// Check all fields for possible turns
	for(int i = 0; i < SIZE_Y; i++)
	{
		for(int j = 0; j < SIZE_X; j++)
		{
			// Possible turn found?
			if(turn_valid(field,player,j,i))
			{
				count++;
			}
		}
	}

	return count;
}

/**
 * \brief Function to execute a turn by a human player
 *
 * This function takes a given field and player code to allow this player to take a turn
 * on the field. It checks whether a turn is possible for this player.
 *
 * \param field the current playing field
 * \param player the player, who should be asked for a turn
 * \return true if turn was successful, false otherwise
 */
bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
{
	if (possible_turns(field, player) == 0)
	{
		return false;
	}

	int px;
	int py;
	// bool repeat=false; (not used)

	while (true)
	{
		std::string input;
		input.reserve(50);
		std::cout << std::endl << "Player " << player << ", Your move (e.g. A1): " ;
		input.erase(input.begin(), input.end());
		std::cin >> input;
		px = ((int) input.at(0) ) - 65;
		py = ((int) input.at(1) ) - 49;

		if (turn_valid(field, player, px, py))
		{
			//accept turn
			break;
		}
		else
		{
			std::cout << std::endl << "Invalid input !" << std::endl;
		}
	}

	execute_turn(field, player, px, py);

	return true;
}

/**
 * \brief Main game process is handled here
 *
 * This function takes the types of the two players (Human / Computer) and
 * handles the main process of the game, i.e. drawing the field, allowing
 * the players to turn alternately and check for a finished game.
 *
 * \param player_type array of two elements containing the type of the players
 */
void game(const int player_type[2])
{

	int field[SIZE_Y][SIZE_X];

	//Create starting pattern
	initialize_field(field);

	int current_player = 1;
	show_field(field);

	//let each player make its moves until no further moves are possible
	while(possible_turns(field, 1) > 0 || possible_turns(field, 2) > 0)
	{
		bool turn_success = false;

		// turn by human or by computer ?
		if(player_type[current_player-1] == COMPUTER)
		{
			turn_success = computer_turn(field, current_player);
		}
		else
		{
			turn_success = human_turn(field, current_player);
		}

		// turn successful completed ?
		if(turn_success)
		{
			show_field(field);
		}
		else
		{
			std::cout << "Player " << current_player << " can't execute turn." << std::endl;
		}

		// change the current Player 1 <-> 2
		current_player = 3 - current_player;
	}

	switch (winner(field))
	{
	case 0: std::cout << "Draw!" << std::endl; break;
	case 1: std::cout << "Player 1 wins!" << std::endl; break;
	case 2: std::cout << "Player 2 wins!" << std::endl; break;
	}
}

/**
 * \brief main routine for the application
 *
 * \return 0 for correct execution
 */
int main(void)
{
	if (TEST == 1)
	{
		bool result = run_full_test();
		if (result == true)
		{
			std::cout << "ALL TESTS PASSED!" << std::endl;
		}
		else
		{
			std::cout << "TEST FAILED!" << std::endl;
		}
	}

	int field[SIZE_Y][SIZE_X];
	int player_type[2];

	char user_input = ' ';
	do
	{
		std::cout << "=== Reversi ===" << std::endl; // Title

		// Ask for player types
		std::cout << "Please enter Player Type for Player 1 ([H]uman | [C]omputer): ";
		std::cin  >> user_input;
		player_type[0] = toupper(user_input)=='C' ? COMPUTER : HUMAN;
		std::cout << "Please enter Player Type for Player 2 ([H]uman | [C]omputer): ";
		std::cin  >> user_input;
		player_type[1] = toupper(user_input)=='C' ? COMPUTER : HUMAN;
		std::cout << std::endl;

		// empty field & start configuration
		initialize_field(field);

		// let's go!
		game(player_type);

		// start a new game ?
		std::cout << std::endl;
		std::cout << "Enter [E] to end the Game, any other character to continue.. ";
		std::cin  >> user_input;
	}
	while(toupper(user_input) != 'E'); // Abort with character E

	return 0;
}

// E.O.F.
