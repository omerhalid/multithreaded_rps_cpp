Multithreaded Rock-Paper-Scissors (RPS) Game
--------------------------------------------------------------

Overview:
This project is a multithreaded implementation of a Rock-Paper-Scissors game. It consists of a server and a client, and supports high score tracking. The project includes unit tests for both game logic and high score management.

Features:
Multithreaded Server: Handles multiple clients concurrently.
Client Application: Connects to the server to play Rock-Paper-Scissors.
High Score Board: Maintains and updates player scores.
Unit Tests: Ensures the correctness of game logic and high score functionality.

Create a build directory:
mkdir build
cd build

Configure the project with CMake:
cmake ..

Build the project:
cmake --build .

Run the Server and Client:
Open two terminal windows.

In the first terminal, navigate to the build/server/Debug directory and run the server:
./server

In the second terminal, navigate to the build/client/Debug directory and run the client:
./client

Running Unit Tests
In the build directory, run the tests using CTest:
ctest -C Debug

Ömer Halit Cinar
omerhalidcinar@gmail.com
