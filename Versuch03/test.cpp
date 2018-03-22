/**
 * @file test.cpp
 *
 * Provides a function for testing the program and some other functions in order to provide this.
 */

#include "test.h"
#include "config.h"

#include <iostream>


extern void show_field(const int field[SIZE_Y][SIZE_X]);
extern int winner(const int field[SIZE_Y][SIZE_X]);
extern bool turn_valid(const int field[SIZE_Y][SIZE_X],  const int player, const int pos_x, const int pos_y);
extern void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y);
extern int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);

/**
 * @brief Test function for 'winner'-function
 *
 * This function takes a playing field and the right code of the winner to
 * test the behavior of the function winner. It prints the current field and
 * messages about the running test cycle to the console.
 *
 * @param field the current playing field to test with
 * @param winner_code the correct winner code to be returned by winner function
 * @return true if winner determines the winner correctly, false otherwise
 */
bool test_winner(const int field[SIZE_Y][SIZE_X], const int winner_code)
{
	std::cout << "Running test for 'winner'..." << std::endl;
	std::cout << "----------------------------" << std::endl;
	show_field(field);
	std::cout << "Checking who wins" << std::endl;

	//Call winner-function
	int winner_ret = winner(field);

	// wrong result ?
	if(winner_ret != winner_code)
	{
		// Output values for comparison
		std::cout << "Test failed!" << std::endl;
		std::cout << "Winner function returned: " << winner_ret << std::endl;
		std::cout << "Winner as in winner_code: " << winner_code << std::endl;
		return false;
	}

	std::cout << "Test passed! Winner is " << winner_ret << std::endl;
	return true;
}

/**
 * @brief Test function for 'turn_valid'-function
 *
 * This function takes a playing field, a player code, a position and the correct
 * answer, if a move would be possible to test the function turn_valid. It prints
 * out important information about the running test cycle to the console.
 *
 * @param field the playing field to test with
 * @param player the player willing to move in test scenario
 * @param pos_x desired position for the move (x-coordinate)
 * @param pos_y desired position for the move (y-coordinate)
 * @param valid the correct answer, whether a move is possible under the given conditions
 */
bool test_turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
					 const int pos_y, const bool valid)
{
	std::cout << "Running test for 'turn_valid'..." << std::endl;
	std::cout << "--------------------------------" << std::endl;
	show_field(field);
	std::cout << "Position X: " << pos_x << std::endl;
	std::cout << "Position Y: " << pos_y << std::endl;
	std::cout << "Player: " << player << std::endl;
	std::cout << "Checking for valid move." << std::endl;

	//Call turn_valid-function
	bool turn_valid_ret = turn_valid(field, player, pos_x, pos_y);

	// wrong result ?
	if(turn_valid_ret != valid)
	{
		// output value for comparison
		std::cout << "Test failed!" << std::endl;
		std::cout << "Turn Valid function returned: " << turn_valid_ret << std::endl;
		std::cout << "valid should be: " << valid << std::endl;
		return false;
	}

	std::cout << "Test passed! Turn valid is " << turn_valid_ret << std::endl;
	return true;
}

/**
 * @brief Test function for 'execute_turn'-function
 *
 * This function takes a playing field, a player code, a position and the correct field
 * after a turn by given player. It compares the result of execute_turn function to
 * the given correct result, to test the function execute_turn.
 *
 * @param input the playing field to test with
 * @param player the player doing the turn in the test scenario
 * @param pos_x desired position for the turn (x-coordinate)
 * @param pos_y desired position for the turn (y-coordinate)
 * @param output the correct output field after doing the turn of player
 */
bool test_execute_turn(int input[SIZE_Y][SIZE_X], const int output[SIZE_Y][SIZE_X],
					   const int player, const int pos_x, const int pos_y)
{
	std::cout << "Running test for 'execute_turn'..." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	show_field(input);
	std::cout << "Position X: " << pos_x << std::endl;
	std::cout << "Position Y: " << pos_y << std::endl;
	std::cout << "Player: " << player << std::endl;
	std::cout << "Executing turn." << std::endl;

	//Call execute_turn-function
	execute_turn(input, player, pos_x, pos_y);

	bool execute_turn_success = true;
	for(int i = 0; i < SIZE_Y; i++) // Compare every field entry
	{
		for(int j = 0; j < SIZE_X; j++)
		{
			if(input[i][j] != output[i][j]) // One wrong?
			{
				execute_turn_success = false;
			}
		}
	}

	// wrong result
	if(!execute_turn_success)
	{
		// show field for comparison
		std::cout << "Test failed!" << std::endl;
		std::cout << "Execute Turn function returned:" << std::endl;
		show_field(input);
		std::cout << "Output field should be:" << std::endl;
		show_field(output);
		return false;
	}

	std::cout << "Test passed! Output field is:" << std::endl;
	show_field(input);
	return true;
}

/**
 * @brief Test function for the 'possible_turns'-function
 *
 * This function takes a playing field a player and a correct number of possible
 * turns for the player to test the possible_turns function. Important information
 * about the running test cycle is being printed to the console.
 *
 * @param field the current playing field
 * @param player the player the count the possible turns in test scenario
 * @param count_possible_turns the correct number of possible turns of player
 * @return true, if possible_turns function passes all test scenarios, false otherwise
 */
bool test_possible_turns(const int field[SIZE_Y][SIZE_X], const int player,
						 const int count_possible_turns)
{
	std::cout << "Running test for 'possible_turns'..." << std::endl;
	std::cout << "------------------------------------" << std::endl;
	show_field(field);
	std::cout << "Player to be checked: " << player << std::endl;
	std::cout << "Checking possible turns." << std::endl;

	//Call possible_turns-function
	int possible_turns_ret = possible_turns(field,player);

	if(possible_turns_ret != count_possible_turns)
	{
		std::cout << "Test failed!" << std::endl;
		std::cout << "Possible turns function returned: " << possible_turns_ret << std::endl;
		std::cout << "Possible turns should be: " << count_possible_turns << std::endl;
		return false;
	}

	std::cout << "Test passed! Possible turns are " << possible_turns_ret << std::endl;
	return true;
}

/**
 * \brief Test function for all test scenarios
 *
 * This function executes all tests to check the functions winner, turn_valid, execute_turn & possible_turns.
 * It uses the test functions defined in this file.
 *
 * \return true, if all tests ran successfully, false otherwise
 */
bool run_full_test(void)
{
	bool result = true;


// ---------- CHECK WINNER ---------- //

	int winner_matrix[5][8][8]= {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 2, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			{   {1, 0, 0, 0, 0, 0, 0, 1},
				{0, 0, 2, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 1, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 2, 0, 1, 0, 2, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			{   {0, 0, 0, 0, 2, 0, 0, 0},
				{0, 0, 2, 0, 2, 0, 0, 0},
				{2, 0, 0, 1, 0, 0, 2, 0},
				{0, 0, 1, 0, 0, 0, 2, 0},
				{0, 0, 0, 1, 2, 2, 0, 0},
				{0, 0, 0, 2, 0, 0, 2, 0},
				{1, 2, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			{   {1, 0, 2, 0, 1, 0, 2, 1},
				{1, 0, 2, 2, 0, 2, 0, 1},
				{1, 0, 0, 0, 0, 0, 2, 1},
				{0, 0, 1, 1, 0, 2, 0, 1},
				{0, 2, 0, 0, 1, 0, 2, 1},
				{2, 0, 0, 2, 0, 0, 2, 0},
				{0, 2, 0, 0, 0, 2, 0, 0},
				{2, 0, 1, 1, 1, 0, 0, 0}
			}};

	int winner_code[5] = {1, 2, 1, 2, 0};

	for (int i = 0; i < 5; i++)
	{
		if(!test_winner(winner_matrix[i], winner_code[i]))
		{
			result = false;
		}
	}


// ---------- CHECK TURN VALID ---------- //

	int turnvalid_matrix[6][8][8] = {
			{   {1, 0, 2, 0, 0, 1, 1, 1},
				{0, 0, 2, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 2, 0},
				{0, 0, 0, 2, 1, 1, 0, 2},
				{1, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 1}
			},

			{   {1, 0, 2, 0, 0, 1, 1, 1},
				{0, 0, 2, 0, 0, 1, 0, 0},
				{0, 0, 2, 0, 0, 2, 1, 1},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 2, 0},
				{0, 0, 0, 2, 1, 1, 0, 2},
				{1, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 1}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 1, 0, 0, 2, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{2, 0, 1, 2, 0, 2, 0, 0},
				{0, 2, 0, 2, 2, 2, 2, 2},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 2, 2, 2},
				{0, 2, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 1, 0, 0}
			},

			{   {2, 1, 0, 0, 2, 1, 1, 1},
				{0, 2, 0, 0, 0, 0, 0, 0},
				{1, 0, 0, 2, 0, 0, 0, 1},
				{0, 1, 1, 1, 0, 1, 0, 0},
				{1, 0, 0, 1, 1, 0, 0, 2},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{1, 1, 0, 0, 0, 0, 2, 0},
				{1, 1, 2, 0, 0, 2, 2, 1}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int turnvalid_player[6] = {1, 2, 2, 1, 2, 1};
	int turnvalid_pos[6][2] = { {2, 3}, {0, 3}, {4, 3}, {3, 4}, {3, 5}, {3, 4} };
	bool turnvalid_valid[6] = {0, 0, 0, 1, 1, 0};

	for (int i = 0; i < 6; i++)
	{
		if(!test_turn_valid(turnvalid_matrix[i],turnvalid_player[i],
				turnvalid_pos[i][0], turnvalid_pos[i][1], turnvalid_valid[i]))
		{
			result = false;
		}
	}


// ---------- CHECK EXECUTE TURN ---------- //

	int executeturn_matrix_in[9][8][8] = {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 2, 0, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 2, 0, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 1, 2, 0, 2, 2, 1, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 1, 1, 1, 1, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 2, 1},
				{1, 0, 1, 1, 2, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int executeturn_matrix_out[9][8][8] = {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 1, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 1, 1, 1, 1, 1, 1, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 2, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 2, 1, 1, 1, 1, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 2, 1},
				{1, 2, 2, 2, 2, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int executeturn_player[9]={0,0,0,1,2,0,1,2,2};
	int executeturn_pos[9][2]={	{0,0},
					{0,0},
					{0,0},
					{3,4},
					{3,5},
					{0,0},
					{3,4},
					{2,4},
					{1,4}};

	for (int i = 0; i < 9; i++)
	{
		if(!test_execute_turn(executeturn_matrix_in[i], executeturn_matrix_out[i],
				executeturn_player[i], executeturn_pos[i][0], executeturn_pos[i][1]))
		{
			result = false;
		}
	}


// ---------- CHECK POSSIBLE TURNS ---------- //

	int possibleturns_matrix[2][8][8] = {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 2, 0, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 2, 1, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int possibleturns_player[2] = {1, 1};
	int possibleturns_count[2] = {4, 5};

	for (int i = 0; i < 2; i++)
	{
		if(!test_possible_turns(possibleturns_matrix[i],
				possibleturns_player[i], possibleturns_count[i]))
		{
			result = false;
		}
	}

	// return whole result
	return result;
}

//E.O.F.
