#include <thread>
#include "high_score_board.h"
#include <gtest/gtest.h>

/**
 * @brief Test case for concurrent updates to the high score board.
 *
 * This test ensures that the high score board handles concurrent updates correctly and remains thread-safe.
 */
TEST(HighScoreBoardTest, ConcurrentUpdates) {
    HighScoreBoard board;

    // Lambda function to update scores for multiple players
    auto updateScores = [&board](const std::string& baseName, int baseScore) {
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::string name = baseName + std::to_string(j);
                board.updateHighScore(name, baseScore + i + j);
            }
        }
    };

    // Create threads to update scores concurrently
    std::thread t1(updateScores, "Alice", 10);
    std::thread t2(updateScores, "Bob", 20);
    std::thread t3(updateScores, "Charlie", 30);

    // Wait for all threads to finish execution
    t1.join();
    t2.join();
    t3.join();

    // Retrieve the high scores and perform assertions
    auto highScores = board.getHighScores();

    // Verify the size of the high score list
    EXPECT_EQ(highScores.size(), 10);

    // Verify that the highest score is greater than or equal to the base score
    EXPECT_GE(highScores[0].second, 10);

    // Print high scores for debugging purposes
    for (const auto& score : highScores) {
        std::cout << score.first << ": " << score.second << std::endl;
    }
}
