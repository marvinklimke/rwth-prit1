/**
 * @file Reversi_KI.h
 *
 * Provides a KI for the game Reversi.
 */

#ifndef REVERSI_KI_H_
#define REVERSI_KI_H_

#include "config.h"

/**
 * A function which provides a KI for the game Reversi
 *
 * @param field The field on which the KI is going to play.
 * @param player The player number of the KI
 * @return True if a turn was executed. False if no turn is possible.
 */
bool computer_turn(int field[SIZE_Y][SIZE_X], const int player);

#endif /* REVERSI_KI_H_ */
