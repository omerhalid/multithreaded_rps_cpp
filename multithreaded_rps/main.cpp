#include <iostream>   
#include <cstdlib>    
#include <cstring>  

int main(int argc, char* argv[]) {
    // Check if exactly one argument is provided (program name + one argument)
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <server|client>" << std::endl;
        return 1;
    }

    // Check if the argument is "server"
    if (std::strcmp(argv[1], "server") == 0) {
        system("server.exe"); // Run the server executable
    } 
    // Check if the argument is "client"
    else if (std::strcmp(argv[1], "client") == 0) {
        system("client.exe"); // Run the client executable
    } 
    // If the argument is neither "server" nor "client"
    else {
        std::cerr << "Invalid argument. Use 'server' or 'client'." << std::endl;
        return 1; // Return an error code
    }

    return 0;
}
