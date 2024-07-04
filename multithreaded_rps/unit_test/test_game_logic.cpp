/**
 * @file test_game_logic.cpp
 * @brief Tests for game logic functions.
 *
 * This file contains tests for the game logic, specifically testing the outcomes
 * of rock-paper-scissors games between a server and a client.
 */

#include <gtest/gtest.h>
#include "../server/game_logic.h"

/**
 * @brief Test case for rock beating scissors.
 *
 * This test ensures that the game logic correctly identifies rock as the winner over scissors.
 */
TEST(GameLogicTest, RockBeatsScissors) {
    EXPECT_EQ(determineWinner("rock", "scissors"), "server");
    EXPECT_EQ(determineWinner("scissors", "rock"), "client");
}

/**
 * @brief Test case for scissors beating paper.
 *
 * This test verifies that the game logic accurately determines scissors as the winner over paper.
 */
TEST(GameLogicTest, ScissorsBeatsPaper) {
    EXPECT_EQ(determineWinner("scissors", "paper"), "server");
    EXPECT_EQ(determineWinner("paper", "scissors"), "client");
}

/**
 * @brief Test case for paper beating rock.
 *
 * This test checks that the game logic correctly assigns paper as the winner over rock.
 */
TEST(GameLogicTest, PaperBeatsRock) {
    EXPECT_EQ(determineWinner("paper", "rock"), "server");
    EXPECT_EQ(determineWinner("rock", "paper"), "client");
}

/**
 * @brief Test case for identical choices resulting in a draw.
 *
 * This test ensures that the game logic identifies games where both players make the same choice as a draw.
 */
TEST(GameLogicTest, SameChoiceDraw) {
    EXPECT_EQ(determineWinner("rock", "rock"), "draw");
    EXPECT_EQ(determineWinner("paper", "paper"), "draw");
    EXPECT_EQ(determineWinner("scissors", "scissors"), "draw");
}

/**
 * @brief Test case for handling invalid inputs in game logic.
 *
 * This test ensures that the game logic handles invalid inputs gracefully.
 */
TEST(GameLogicTest, InvalidInputs) {
    EXPECT_EQ(determineWinner("rock", "invalid"), "invalid input");
    EXPECT_EQ(determineWinner("invalid", "rock"), "invalid input");
    EXPECT_EQ(determineWinner("invalid", "invalid"), "invalid input");
}
