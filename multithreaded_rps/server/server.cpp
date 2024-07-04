#include "server.h"
#include "game_logic.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <winsock2.h> // Include the Winsock library for network communication
#include <ctime>

#define BUFFER_SIZE 256 // Define a constant for the buffer size

// Constructor for the Server class
Server::Server(int port) : running(false) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData); // Initialize Winsock

    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // Create a TCP socket
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET; // Set the address family to IPv4
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Listen on any network interface
    serverAddr.sin_port = htons(port); // Set the port number, converting to network byte order
    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)); // Bind the socket to the address and port
    listen(serverSocket, 10); // Start listening for incoming connections, with a backlog of 10

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
}

// Start the server's operation
void Server::start() {
    running = true;
    while (running) {
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr); // Accept a new connection
        if (clientSocket != INVALID_SOCKET) {
            std::lock_guard<std::mutex> lock(mtx);
            clientThreads.emplace_back(&Server::handleClient, this, clientSocket);
        }
    }
    for (auto& thread : clientThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

// Stop the server's operation
void Server::stop() {
    running = false;
    closesocket(serverSocket); // Close the server socket
}

// Check if the server is running
bool Server::isRunning() const {
    return running;
}

// Handle communication with a client
void Server::handleClient(SOCKET clientSocket) {
    char buffer[BUFFER_SIZE];
    std::string clientName;
    int score = 0;

    // Receive the client's name
    int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0'; // Null-terminate the received string
        clientName = buffer; // Store the client's name
    }

    // Main game loop
    while (true) {
        std::string serverChoice = playGame();
        std::string clientChoice;

        // Receive the client's game choice
        bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0'; // Null-terminate the received string
            clientChoice = buffer; // Store the client's choice
        }

        // Determine the winner
        std::string result = determineWinner(serverChoice, clientChoice);

        // Debug information
        std::cout << "Server choice: " << serverChoice << ", Client choice: " << clientChoice << ", Result: " << result << std::endl;

        // Update score and notify client of the result
        if (result == "client") {
            score++;
            send(clientSocket, "win", strlen("win") + 1, 0); // Notify client of win
        } else if (result == "server") {
            send(clientSocket, "lose", strlen("lose") + 1, 0); // Notify client of loss and end game
            break;
        } else {
            send(clientSocket, "draw", strlen("draw") + 1, 0); // Notify client of draw
        }
    }

    // Update and print the high score board
    highScoreBoard.updateHighScore(clientName, score);
    highScoreBoard.printHighScores();
    closesocket(clientSocket); // Close the client socket
}

// Generate a random game choice
std::string Server::playGame() {
    static const std::vector<std::string> choices = {"rock", "paper", "scissors"};
    return choices[rand() % 3];
}
