/**
 * @file client.h
 * @brief Client class header file.
 */

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <winsock2.h>

/**
 * @class Client
 * @brief Manages the client-side operations of the game.
 */
class Client {
public:
    /**
     * @brief Constructs a new Client object.
     * @param serverIP The IP address of the server.
     * @param port The port number of the server.
     */
    Client(const std::string& serverIP, int port);

    /**
     * @brief Starts the client.
     */
    void start();

    /**
     * @brief Plays the game by choosing rock, paper, or scissors.
     * @return The chosen option as a string.
     */
    std::string playGame();

private:
    std::string serverIP; ///< The IP address of the server.
    int port; ///< The port number of the server.
    SOCKET clientSocket; ///< The client socket.

    /**
     * @brief Connects to the server.
     */
    void connectToServer();
};

#endif
