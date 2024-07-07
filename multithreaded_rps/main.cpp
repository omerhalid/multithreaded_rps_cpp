#include <iostream>
#include <cstdlib>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <server|client>" << std::endl;
        return 1;
    }

    if (std::strcmp(argv[1], "server") == 0) {
        system("server.exe");
    } else if (std::strcmp(argv[1], "client") == 0) {
        system("client.exe");
    } else {
        std::cerr << "Invalid argument. Use 'server' or 'client'." << std::endl;
        return 1;
    }

    return 0;
}
