#include "client.h"
#include <iostream>
#include <winsock2.h> // Include the Winsock library for network communication
#include <ctime>
#include <WS2tcpip.h> // Include for network utilities
#include <vector> 

#define BUFFER_SIZE 256

// Constructor for the Client class
Client::Client(const std::string& serverIP, int port)
    : serverIP(serverIP), port(port) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData); // Initialize Winsock

    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));
}

// Start the client's operation
void Client::start() {
    connectToServer(); // Establish a connection to the server
    char buffer[BUFFER_SIZE];
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;
    send(clientSocket, name.c_str(), name.size() + 1, 0); // Send the name to the server

    while (true) {
        std::string clientChoice = playGame(); // Get the client's game choice
        send(clientSocket, clientChoice.c_str(), clientChoice.size() + 1, 0); // Send the choice to the server

        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0); // Receive the game result from the server
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0'; // Null-terminate the received string
            std::string result = buffer;

            // Debug information
            std::cout << "Client choice: " << clientChoice << ", Result: " << result << std::endl;

            if (result == "win") {
                std::cout << "You won this round!\n";
            } else if (result == "lose") {
                std::cout << "You lost. Game over.\n";
                break;
            } else {
                std::cout << "It's a draw.\n";
            }
        }
    }

    closesocket(clientSocket); // Close the socket when done
}

// Establish a connection to the server
void Client::connectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // Create a socket
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET; // Use IPv4 addresses
    inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr.s_addr); // Convert the server IP to binary form
    serverAddr.sin_port = htons(port); // Convert the port number to network byte order

    connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)); // Connect to the server
}

std::string Client::playGame() {
    static const std::vector<std::string> choices = {"rock", "paper", "scissors"};
    return choices[rand() % 3];
}
