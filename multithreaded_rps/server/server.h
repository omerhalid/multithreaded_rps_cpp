/**
 * @file server.h
 * @brief Server class header file.
 */

#ifndef SERVER_H
#define SERVER_H

#include "high_score_board.h"
#include <winsock2.h>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

/**
 * @class Server
 * @brief Manages the server-side operations of the game.
 */
class Server {
public:
    /**
     * @brief Constructs a new Server object.
     * @param port The port number for the server.
     */
    Server(int port);

    /**
     * @brief Starts the server.
     */
    void start();

    /**
     * @brief Stops the server.
     */
    void stop();

    /**
     * @brief Checks if the server is running.
     * @return True if the server is running, false otherwise.
     */
    bool isRunning() const;

private:
    SOCKET serverSocket; ///< The server socket.
    HighScoreBoard highScoreBoard; ///< High score board.
    std::vector<std::thread> clientThreads;
    std::mutex mtx;
    std::atomic<bool> running; ///< Atomic variable to keep track of server status

    /**
     * @brief Handles a client connection.
     * @param clientSocket The socket for the connected client.
     */
    void handleClient(SOCKET clientSocket);

    /**
     * @brief Plays the game by choosing rock, paper, or scissors.
     * @return The chosen option as a string.
     */
    std::string playGame();
};

#endif // SERVER_H
