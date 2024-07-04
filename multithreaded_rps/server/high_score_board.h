/**
 * @file high_score_board.h
 * @brief High Score Board class header file.
 */

#ifndef HIGH_SCORE_BOARD_H
#define HIGH_SCORE_BOARD_H

#include <vector>
#include <string>
#include <mutex>

/**
 * @class HighScoreBoard
 * @brief Manages the high scores for the game.
 */
class HighScoreBoard {
public:
    /**
     * @brief Updates the high score for a given player.
     * @param name The name of the player.
     * @param score The score of the player.
     */
    void updateHighScore(const std::string& name, int score);

    /**
     * @brief Prints the high scores to the console.
     */
    void printHighScores() const;

    /**
     * @brief Retrieves the high scores.
     * @return A vector of pairs containing player names and scores.
     */
    std::vector<std::pair<std::string, int>> getHighScores() const;

private:
    std::vector<std::pair<std::string, int>> highScores; ///< Vector to store high scores.
    mutable std::mutex highScoreMutex; ///< Mutex to protect access to high scores.
};

#endif
