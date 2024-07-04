cmake_minimum_required(VERSION 3.10)
project(MultithreadedRPS_Tests)

# Add Google Test
add_subdirectory(${CMAKE_SOURCE_DIR}/googletest ${CMAKE_BINARY_DIR}/googletest)

# Set the runtime library to Multi-threaded Debug DLL (/MDd) for all targets in debug mode
if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd")
    set(CMAKE_C_FLAGS_DEBUG "/MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "/MD")
    set(CMAKE_C_FLAGS_RELEASE "/MD")
endif()

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/server)
include_directories(${CMAKE_SOURCE_DIR}/client)
include_directories(${CMAKE_SOURCE_DIR}/googletest/googletest/include)

# Add test executables
add_executable(test_game_logic test_game_logic.cpp ../server/game_logic.cpp)
add_executable(test_high_score_board test_high_score_board.cpp ../server/high_score_board.cpp)
add_executable(test_concurrency test_concurrency.cpp ../server/high_score_board.cpp)
add_executable(test_server_client_connections test_server_client_connections.cpp ../server/server.cpp ../server/high_score_board.cpp ../client/client.cpp ../server/game_logic.cpp)

# Link test executables with Google Test and Winsock
target_link_libraries(test_game_logic gtest gtest_main ws2_32)
target_link_libraries(test_high_score_board gtest gtest_main ws2_32)
target_link_libraries(test_concurrency gtest gtest_main ws2_32)
target_link_libraries(test_server_client_connections gtest gtest_main ws2_32)

# Add tests
add_test(NAME test_game_logic COMMAND test_game_logic)
add_test(NAME test_high_score_board COMMAND test_high_score_board)
add_test(NAME test_concurrency COMMAND test_concurrency)
add_test(NAME test_server_client_connections COMMAND test_server_client_connections)
