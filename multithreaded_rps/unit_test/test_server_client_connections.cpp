/**
 * @brief Test case for handling a high number of client connections.
 *
 * This test ensures that the server can handle a high number of clients without crashing.
 */

#include <gtest/gtest.h>
#include "../server/server.h"
#include "../client/client.h"
#include <vector>
#include <thread>

// Define the port for the server and clients
constexpr int SERVER_PORT = 54000;

// Test for handling a high number of client connections
TEST(ServerTest, HighNumberOfClients) {
    // Create and start the server in a separate thread
    Server server(SERVER_PORT);
    std::thread serverThread([&server]() {
        server.start();
    });

    // Allow some time for the server to start properly
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Vector to hold client threads
    std::vector<std::thread> clientThreads;

    // Create and start multiple client threads
    for (int i = 0; i < 100; ++i) {
        clientThreads.emplace_back([i]() {
            Client client("localhost", SERVER_PORT);
            client.playGame();
        });
    }

    // Join all client threads
    for (auto& thread : clientThreads) {
        thread.join();
    }

    // Allow some time for the server to handle the disconnections
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Check server status, log files, or any other indicators to ensure it handled the load (optional)
    EXPECT_TRUE(server.isRunning());

    // Stop the server
    server.stop();
    serverThread.join();
}
