#include "high_score_board.h"
#include <gtest/gtest.h>

/**
 * @file test_high_score_board.cpp
 * @brief Tests for the HighScoreBoard functionality.
 *
 * This file contains tests for the HighScoreBoard class, ensuring that scores are added,
 * updated, and maintained correctly within the top 10 scores.
 */

/**
 * @brief Test case for adding new scores to the high score board.
 *
 * This test verifies that new scores are added correctly to the high score board
 * and that the scores are sorted in descending order.
 */
TEST(HighScoreBoardTest, AddNewScore) {
    HighScoreBoard board;
    board.updateHighScore("Alice", 5);
    board.updateHighScore("Bob", 10);
    
    std::vector<std::pair<std::string, int>> expected = { {"Bob", 10}, {"Alice", 5} };
    EXPECT_EQ(board.getHighScores(), expected);
}

/**
 * @brief Test case for updating an existing score on the high score board.
 *
 * This test ensures that if a player's new score is higher than their existing score,
 * the high score board is updated accordingly.
 */
TEST(HighScoreBoardTest, UpdateExistingScore) {
    HighScoreBoard board;
    board.updateHighScore("Alice", 5);
    board.updateHighScore("Alice", 10);

    std::vector<std::pair<std::string, int>> expected = { {"Alice", 10} };
    EXPECT_EQ(board.getHighScores(), expected);
}

/**
 * @brief Test case for maintaining only the top 10 scores on the high score board.
 *
 * This test checks that the high score board correctly limits itself to storing
 * only the top 10 scores, even when more than 10 scores are added.
 */
TEST(HighScoreBoardTest, KeepTop10Scores) {
    HighScoreBoard board;
    for (int i = 1; i <= 11; ++i) {
        board.updateHighScore("Player" + std::to_string(i), i);
    }
    
    auto highScores = board.getHighScores();
    EXPECT_EQ(highScores.size(), 10);
    EXPECT_EQ(highScores[0], std::make_pair("Player11", 11));
    EXPECT_EQ(highScores[9], std::make_pair("Player2", 2));
}

/**
 * @brief Test case for handling very high scores in high score board.
 *
 * This test ensures that the high score board can handle very high scores correctly.
 */
TEST(HighScoreBoardTest, VeryHighScores) {
    HighScoreBoard board;
    board.updateHighScore("Alice", 1000000);
    board.updateHighScore("Bob", 2000000);
    
    std::vector<std::pair<std::string, int>> expected = { {"Bob", 2000000}, {"Alice", 1000000} };
    EXPECT_EQ(board.getHighScores(), expected);
}
