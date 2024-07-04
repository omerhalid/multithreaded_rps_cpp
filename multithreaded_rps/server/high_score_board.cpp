#include "high_score_board.h"
#include <algorithm>
#include <iostream>

void HighScoreBoard::updateHighScore(const std::string& name, int score) {
    // Lock the mutex to ensure thread-safe access to highScores
    std::lock_guard<std::mutex> lock(highScoreMutex);

    // Check if player already exists
    auto it = std::find_if(highScores.begin(), highScores.end(), [&name](const std::pair<std::string, int>& p) {
        return p.first == name;
    });

    if (it != highScores.end()) {
        // Update score if higher
        if (score > it->second) {
            it->second = score;
        }
    } else {
        // Add new player score
        highScores.push_back({name, score});
    }

    // Sort the high scores in descending order
    std::sort(highScores.begin(), highScores.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second > b.second;
    });

    // Keep only top 10 scores
    if (highScores.size() > 10) {
        highScores.resize(10);
    }
}

void HighScoreBoard::printHighScores() const {
    // Lock the mutex to ensure thread-safe access to highScores
    std::lock_guard<std::mutex> lock(highScoreMutex);
    std::cout << "High Score Board:\n";
    for (const auto& entry : highScores) {
        std::cout << entry.first << ": " << entry.second << "\n";
    }
}

std::vector<std::pair<std::string, int>> HighScoreBoard::getHighScores() const {
    // Lock the mutex to ensure thread-safe access to highScores
    std::lock_guard<std::mutex> lock(highScoreMutex);
    return highScores;
}
