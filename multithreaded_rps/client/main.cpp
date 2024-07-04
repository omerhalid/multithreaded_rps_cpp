#include "client.h"

int main() {
    Client client("127.0.0.1", 54000); // Create a client object with server IP and port
    client.start(); // Start the client's operation
    WSACleanup(); // Clean up Winsock
    return 0;
}
