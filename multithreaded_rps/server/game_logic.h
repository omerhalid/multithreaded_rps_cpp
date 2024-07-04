/**
 * @file game_logic.h
 * @brief Game logic header file.
 */

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <string>

/**
 * @brief Determines the winner between the server's and client's choices.
 * @param serverChoice The server's choice ("rock", "paper", or "scissors").
 * @param clientChoice The client's choice ("rock", "paper", or "scissors").
 * @return "client" if the client wins, "server" if the server wins, or "draw" if it's a draw.
 */
std::string determineWinner(const std::string& serverChoice, const std::string& clientChoice);

#endif
