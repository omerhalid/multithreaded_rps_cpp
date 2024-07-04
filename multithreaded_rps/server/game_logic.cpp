#include "game_logic.h"
#include <vector>

/**
 * @brief Determines the winner of a Rock-Paper-Scissors game.
 * @param serverChoice The server's choice.
 * @param clientChoice The client's choice.
 * @return "client" if the client wins, "server" if the server wins, "draw" if it's a draw, or "invalid input" if either input is invalid.
 */
std::string determineWinner(const std::string& serverChoice, const std::string& clientChoice) {
    // Check for valid inputs
    const std::vector<std::string> validChoices = {"rock", "paper", "scissors"};
    if (std::find(validChoices.begin(), validChoices.end(), serverChoice) == validChoices.end() ||
        std::find(validChoices.begin(), validChoices.end(), clientChoice) == validChoices.end()) {
        return "invalid input";
    }

    if (serverChoice == clientChoice) {
        return "draw";
    }

    if ((serverChoice == "rock" && clientChoice == "scissors") ||
        (serverChoice == "scissors" && clientChoice == "paper") ||
        (serverChoice == "paper" && clientChoice == "rock")) {
        return "server";
    } else {
        return "client";
    }
}
