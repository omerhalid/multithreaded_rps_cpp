#include "server.h"

int main() {
    Server server(54000); // Create a server object with the specified port number
    server.start(); // Start the server's operation
    WSACleanup(); // Clean up Winsock upon server termination
    return 0;
}
